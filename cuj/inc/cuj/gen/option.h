#pragma once

#include <cuj/common.h>

CUJ_NAMESPACE_BEGIN(cuj::gen)

enum class OptimizationLevel
{
    O0,
    O1,
    O2,
    O3
};

struct Options
{
    OptimizationLevel opt_level        = OptimizationLevel::O3;
    bool              fast_math        = false;
    bool              approx_math_func = false;

#if defined(DEBUG) || defined(_DEBUG)
    bool enable_assert = true;
#else
    bool enable_assert = false;
#endif
};

CUJ_NAMESPACE_END(cuj::gen)
