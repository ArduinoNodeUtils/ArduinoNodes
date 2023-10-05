// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#include "nf/System.h"
#include <unity.h>


void test_system_setup(void) {
    // auto calc = calculateSteering(256, {0, 256}, {0, 512});
    // TEST_ASSERT_EQUAL(512, calc);

    // calc = calculateSteering(0, {0, 256}, {0, 512});
    // TEST_ASSERT_EQUAL(0, calc);

    // calc = calculateSteering(128, {0, 256}, {0, 512});
    // TEST_ASSERT_EQUAL(256, calc);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_system_setup);
    UNITY_END();
}