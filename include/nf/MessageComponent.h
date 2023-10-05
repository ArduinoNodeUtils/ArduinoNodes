// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __NF__MESSAGE_COMPONENT_H__
#define __NF__MESSAGE_COMPONENT_H__

#include "nf/MessageBroker.h"

namespace nf {

template <class T>
class MessageComponent {
public:
    MessageComponent() {}

    ~MessageComponent() {
        
    }

    MessageBroker<T>& getMessageBroker() {
        return this->_messageBroker;
    }

    void setMessageBroker(MessageBroker<T>& messageBroker) {
        this->_messageBroker = messageBroker;
    }

private:
    MessageBroker<T>& _messageBroker{MessageBroker<T>::DefaultMessageBroker};
};

}
#endif