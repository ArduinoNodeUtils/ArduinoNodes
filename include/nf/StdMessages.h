// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __STD_MESSAGES_H__
#define __STD_MESSAGES_H__

namespace nf {
template <typename T>
class Message {
    public:
    T data;
};

    namespace std_msgs {
    
        class Float : public Message<float>{};
        class Boolean : public Message<bool>{};
    }
}

#endif