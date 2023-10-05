// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

namespace nf {
class Component {
	public:
	virtual ~Component() = default;
	virtual void setup() = 0;
	virtual void update() = 0;
	// virtual String info() const = 0;
};

}
