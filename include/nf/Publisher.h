// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __PUBLISHER_H__
#define __PUBLISHER_H__ 

#include "MessageBroker.h"
#include "MessageComponent.h"

namespace nf {
template <typename M, typename T>
class Publisher {
public:

    Publisher(typename T::type topic, MessageComponent<T>& parent) : _topic{topic}, _node{parent} {
    }

    void publish(M message) {
        _messageBuffer.data = message.data;
        this->_node.getMessageBroker().publish(_topic, &_messageBuffer);
    }

    // void setMessageBroker(MessageBroker<T>& messageBroker) {
    //     this->_messageBroker = messageBroker;
    // }
private:
    M _messageBuffer;
    typename T::type _topic;
    MessageComponent<T>& _node;
};
}
#endif