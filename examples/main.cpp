// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#include "ExampleSystem.h"


ExampleSystem exampleSystem;

void setup() {

    Serial.begin(9600);
    // uncomment to not loose any output
    // while(!Serial);

    exampleSystem.setup();
}

void loop() {

    exampleSystem.update();
}