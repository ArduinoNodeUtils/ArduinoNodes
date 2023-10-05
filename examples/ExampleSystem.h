// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#ifndef __EXAMPLE_SYSTEM_H__
#define __EXAMPLE_SYSTEM_H__

#include "nf/Topic.h"
#include "nf/System.h"

constexpr auto TOPICS_START_LINE = __LINE__;
enum class Topics : int {
    MotorPower,
    Orientation 
};
constexpr auto TOPICS_SIZE = __LINE__ - TOPICS_START_LINE - 3;
// clang-format on

class ExampleTopic : public nf::TopicType<Topics, TOPICS_SIZE> {};


class ExampleSystem : public nf::System<ExampleTopic, 1> {
public:
    ExampleSystem();
};

#endif 