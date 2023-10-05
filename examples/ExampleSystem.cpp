// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#include "ExampleSystem.h"
#include "nf/Node.h"
#include "nf/SystemComponent.h"
#include "nf/StdMessages.h"

class ExampleSensor : public nf::SystemComponent<ExampleTopic> {
public:
    ExampleSensor()
        : nf::SystemComponent<ExampleTopic>{"example_sensor"},
        _examplePublisher{getNodeHandle().advertise<nf::std_msgs::Float>(Topics::MotorPower)} {

    }

    void update() {
        nf::std_msgs::Float upd;
        upd.data = 0;
        _examplePublisher.publish(upd);
    }

    void setup() {

    }

private:
    nf::Publisher<nf::std_msgs::Float, ExampleTopic> _examplePublisher;
};

ExampleSystem::ExampleSystem() : 
    nf::System<ExampleTopic, 1>("example_system") {

        auto exampleSensor = ExampleSensor();

        this->addComponent(exampleSensor);
    }