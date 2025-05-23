// Copyright 2024 xensik. All rights reserved.
//
// Use of this source code is governed by a GNU GPLv3 license
// that can be found in the LICENSE file.

#pragma once

#include "xsk/stdinc.hpp"
#include "xsk/gsc/context.hpp"

namespace xsk::gsc::iw7
{

constexpr usize code_count = 153;
constexpr usize func_count = 806;
constexpr usize meth_count = 1483;
constexpr usize token_count = 13216;
constexpr u32 max_string_id = 0x13FCC;

class context : public gsc::context
{
public:
    context();
};

} // namespace xsk::gsc::iw7
