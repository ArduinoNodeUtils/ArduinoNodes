// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once 

#include <stddef.h>

namespace nf {
    template <typename T, size_t S>
    class TopicType {
    public:
        const static size_t size = S;
        typedef T type;
    };
}
