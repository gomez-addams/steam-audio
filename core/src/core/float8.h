//
// Copyright 2017-2023 Valve Corporation.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#pragma once

#include "platform.h"

#if defined(IPL_ENABLE_FLOAT8)

// --------------------------------------------------------------------------------------------------------------------
// float8
// --------------------------------------------------------------------------------------------------------------------

#if ( defined(__clang__) || defined(__GNUC__) ) && ( defined(IPL_CPU_X86) || defined(IPL_CPU_X64) )
#define IPL_FLOAT8_ATTR __attribute__((target("avx")))
#else
#define IPL_FLOAT8_ATTR
#endif

#if defined(IPL_CPU_X86) || defined(IPL_CPU_X64)
#include "avx_float8.h"
#endif

#endif

namespace ipl {

namespace float8
{
    template <typename T>
    inline bool isAligned(const T* p)
    {
        return ((reinterpret_cast<size_t>(p) & 0x1f) == 0);
    }
}

}
