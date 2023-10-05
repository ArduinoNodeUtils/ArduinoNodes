// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __SUBSCRIBER_H__
#define __SUBSCRIBER_H__

#include "nf/MessageComponent.h"

namespace nf {
template <typename M, typename T>
class Subscriber {
public:

    Subscriber(typename T::type topic, std::function<void (M*)> callback, MessageComponent<T>& node): _callback(callback), _node{node} {
       // _messageBroker.addCallback(topic, reinterpret_cast<std::function<void (void*)>>(callback)); 
       _node.getMessageBroker().addCallback(topic, [callback](void* m){callback(static_cast<M*>(m));}); 
    }

    void handle(void *message) {
        M* msg = static_cast<M*>(message);
        _callback(msg);
    }
private:
    typename T::type _topic;
    std::function<void (M* message)> _callback;

    MessageComponent<T>& _node;
};
}
#endif