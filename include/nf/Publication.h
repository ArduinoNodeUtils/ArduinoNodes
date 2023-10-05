// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __PUBLICATION_H__
#define __PUBLICATION_H__

namespace nf {
template <typename T>
struct Publication {
    T topic;
    void *message;
};
}
#endif