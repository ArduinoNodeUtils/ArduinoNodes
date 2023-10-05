// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <stdexcept>

#include "Node.h"
#include "Component.h"
#include "SystemComponent.h"
#include "Vector.h"
#include "MessageBroker.h"


namespace nf {

template <typename T, size_t S>
class System : public Component {
public:
    System(const char *name) : _name(name) {

    }

	virtual ~System() = default;

    void addComponent(SystemComponent<T>& component) {
        // if (this->_components.getSize() >= S) {
        //     throw std::runtime_error("the system size is too small, initialize it with a bigger value");
        // }
        this->_components.add(&component);
    }

    void addComponent(SystemComponent<T>* component) {
        // if (this->_components.getSize() >= S) {
        //     throw std::runtime_error("the system size is too small, initialize it with a bigger value");
        // }
        this->_components.add(component);
    }

    const Vector<SystemComponent<T> *, S>& getComponents() {
        // const Vector<SystemComponent<T> *>, S>& = _components;
        return _components;
    }


    void update() {
        for (auto component : _components) {
            component->update();
        }
        _messageBroker.run();
    }

    void setup() {
        for (auto component: _components) {
            component->setup();
        }
        _messageBroker.run();
    }
private:
    const char* _name;

    MessageBroker<T>& _messageBroker{MessageBroker<T>::DefaultMessageBroker};
    Vector<SystemComponent<T> *, S> _components;
};

// template <typename T, size_t S>
// System<T, S>::~System() {}
// 
}
#endif