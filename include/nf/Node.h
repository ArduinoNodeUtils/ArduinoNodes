// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __NODE_H__
#define __NODE_H__

#include "nf/MessageComponent.h"
#include "nf/Publisher.h"
#include "nf/Subscriber.h"

#include "nf/Vector.h"

namespace nf {

template <class T>
class Node : public MessageComponent<T> {
public:
    Node(const char *name) : MessageComponent<T>(), _name(name) {}

    ~Node() {
        
    }

    template <typename M>
    Publisher<M, T> advertise(typename T::type topic) {
        auto publisher = Publisher<M, T>(topic, *this);
        return publisher;
    }

    template <typename M>
    Subscriber<M, T> subscribe(typename T::type topic, std::function<void (M*)> callback) {
        auto subscriber = Subscriber<M, T>(topic, callback, *this);
        return subscriber;
    }

private:
    const char *_name;
};

}

#endif