// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __MESSAGE_BROKER_H__
#define __MESSAGE_BROKER_H__

// #include <Arduino.h>

#include <functional>
#include <ArduinoLogging.h>

#include <Logger.h>

#include "Vector.h"
#include "Publication.h"

#ifndef NDEBUG
#include <Serial.h>

#include <SerialPrinter.h>
#endif

namespace nf {

    #ifndef NDEBUG
    static SerialPrinter printer;
    static Logger logger(printer);
    static int logdelay1;
    static int logdelay2;
    static int logdelay3;
    static int logdelay4;
    #endif 
    
    static int ID = -1;

template <typename T>
class MessageBroker {
public:


    MessageBroker(){
        _id = ++ID;
    }

    void addCallback(typename T::type topic, std::function<void(void *)> callback) {
        auto topicId = static_cast<int>(topic);

        #ifndef NDEBUG
            LOG_DEBUG(logger, "MessageBroker %p: add callback for topic %d", this, topicId);
        #endif

        _subscriberMap[topicId].add(callback);

        LOG_DEBUG(logger, "did add callback");
    }

    void publish(typename T::type topic, void *message) {
        _publicationsBuffer[_producer].add({topic, message});
        #ifndef NDEBUG
            LOG_DEBUG_DELAY(logger, logdelay4, 1000, "MessageBroker %p: published message for topic %d\nproducer(%d)-buffersize now: %d", this, static_cast<int>(topic),
            _producer, (int) _publicationsBuffer[_producer].getSize());
            // Serial.println("MessageBroker: publishing message");
        #endif

    }
    void run() {
        #ifndef NDEBUG
            LOG_DEBUG_DELAY(logger, logdelay1, 1000, 
            "MessageBroker %p: run\nconsumer(%d) buffer size: %d\nproducer(%d) buffer size: %d",
            this, _consumer, (int) _publicationsBuffer[_consumer].getSize(), _producer, (int) _publicationsBuffer[_producer].getSize());
        #endif

        auto tmp = _producer;
        _producer = _consumer;
        _consumer = tmp;

        while (_publicationsBuffer[_consumer].getSize() > 0) {

            // LOG_DEBUG_DELAY(logger, logdelay2, 1000, "MessageBroker %p: iterating through publications", this);

            for (auto pub : _publicationsBuffer[_consumer]) {

                auto topicId = static_cast<int>(pub.topic);
                auto subscriberCallbacks = _subscriberMap[topicId];

                // LOG_DEBUG_DELAY(logger, logdelay3, 1000, "MessageBroker %p: processing publication for topic %d with N=%d subscribercallbacks", this, topicId, (int)subscriberCallbacks.getSize());
                
                for (auto cb : subscriberCallbacks) {
                    cb(pub.message);
                }
            }

            /* clear the consumer buffer, effectively removing the
               publications that where already handled by the subscribers */
            _publicationsBuffer[_consumer].clear();

            /* swap producer and consumer buffers */
            auto tmp = _producer;
            _producer = _consumer;
            _consumer = tmp;
        }

    }

    static MessageBroker<T> DefaultMessageBroker;

private:


    int _id = 0;
    int _consumer = 1;
    int _producer = 0;

    Vector<Vector<Publication<typename T::type>, 10>, 2> _publicationsBuffer;
    Vector<Vector<std::function<void(void*)>, 10>, T::size> _subscriberMap;

    // Vector<Vector<std::function<void (Message *)>, 16>, TopicCount> subscriptions;
};
template<typename T> MessageBroker<T> MessageBroker<T>::DefaultMessageBroker;
}
#endif