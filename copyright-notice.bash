#!/bin/bash

COPYRIGHT_NOTICE="\
// Copyright 2021 Jan Hermes. All rights reserved.\\
// SPDX-License-Identifier: BSD-3-Clause\\
"

DELIMITER="\\/\\/ COPYRIGHT NOTICE INSERTION POINT"

find . -type f \( -name "*.cpp" -o -name "*.h" \) -print0 |
xargs -0 sed -i "1s|^|${COPYRIGHT_NOTICE}\n|" 