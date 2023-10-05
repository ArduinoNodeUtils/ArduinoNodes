// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __NF__SYSTEM_COMPONENT_H__
#define __NF__SYSTEM_COMPONENT_H__


#include "Component.h"
#include "Node.h"

namespace nf {
    template <typename T>
    class SystemComponent : public Component {
    public: 
        SystemComponent(const char* name) : _nodeHandle{name} {}
        Node<T>& getNodeHandle()  {
            return _nodeHandle;
        }

	    virtual ~SystemComponent() = default;

    private:
        Node<T> _nodeHandle;
    };
}
#endif