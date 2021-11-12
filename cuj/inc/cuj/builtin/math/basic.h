#pragma once

#include <cuj/ast/ast.h>

CUJ_NAMESPACE_BEGIN(cuj::builtin::math)

enum class IntrinsicBasicMathFunctionType
{
    abs,
    mod,
    remainder,
    exp,
    exp2,
    exp10,
    log,
    log2,
    log10,
    pow,
    sqrt,
    rsqrt,
    sin,
    cos,
    tan,
    asin,
    acos,
    atan,
    atan2,
    ceil,
    floor,
    trunc,
    round,
    isfinite,
    isinf,
    isnan,

    min,
    max
};

const char *intrinsic_basic_math_function_name(
    IntrinsicBasicMathFunctionType type);

f32 abs      (const f32 &x);
f32 mod      (const f32 &x, const f32 &y);
f32 remainder(const f32 &x, const f32 &y);
f32 exp      (const f32 &x);
f32 exp2     (const f32 &x);
f32 exp10    (const f32 &x);
f32 log      (const f32 &x);
f32 log2     (const f32 &x);
f32 log10    (const f32 &x);
f32 pow      (const f32 &x, const f32 &y);
f32 sqrt     (const f32 &x);
f32 rsqrt    (const f32 &x);
f32 sin      (const f32 &x);
f32 cos      (const f32 &x);
f32 tan      (const f32 &x);
f32 asin     (const f32 &x);
f32 acos     (const f32 &x);
f32 atan     (const f32 &x);
f32 atan2    (const f32 &y, const f32 &x);
f32 ceil     (const f32 &x);
f32 floor    (const f32 &x);
f32 trunc    (const f32 &x);
f32 round    (const f32 &x);
i32 isfinite (const f32 &x);
i32 isinf    (const f32 &x);
i32 isnan    (const f32 &x);

f64 abs      (const f64 &x);
f64 mod      (const f64 &x, const f64 &y);
f64 remainder(const f64 &x, const f64 &y);
f64 exp      (const f64 &x);
f64 exp2     (const f64 &x);
f32 exp10    (const f32 &x);
f64 log      (const f64 &x);
f64 log2     (const f64 &x);
f64 log10    (const f64 &x);
f64 pow      (const f64 &x, const f64 &y);
f64 sqrt     (const f64 &x);
f64 rsqrt    (const f64 &x);
f64 sin      (const f64 &x);
f64 cos      (const f64 &x);
f64 tan      (const f64 &x);
f64 asin     (const f64 &x);
f64 acos     (const f64 &x);
f64 atan     (const f64 &x);
f64 atan2    (const f64 &y, const f64 &x);
f64 ceil     (const f64 &x);
f64 floor    (const f64 &x);
f64 trunc    (const f64 &x);
f64 round    (const f64 &x);
i32 isfinite (const f64 &x);
i32 isinf    (const f64 &x);
i32 isnan    (const f64 &x);

template<typename T>
ArithmeticValue<T> min(
    const ast::ArithmeticVariable<T> &lhs, const ast::ArithmeticVariable<T> &rhs)
{
    return select(lhs < rhs, lhs, rhs);
}

template<typename T>
ArithmeticValue<T> max(
    const ast::ArithmeticVariable<T> &lhs, const ast::ArithmeticVariable<T> &rhs)
{
    return select(lhs > rhs, lhs, rhs);
}

i32 min(const i32 &a, const i32 &b);
i64 min(const i64 &a, const i64 &b);
f32 min(const f32 &a, const f32 &b);
f64 min(const f64 &a, const f64 &b);

i32 max(const i32 &a, const i32 &b);
i64 max(const i64 &a, const i64 &b);
f32 max(const f32 &a, const f32 &b);
f64 max(const f64 &a, const f64 &b);

template<typename T>
ArithmeticValue<T> clamp(
    const ast::ArithmeticVariable<T> &x,
    const ast::ArithmeticVariable<T> &min_x,
    const ast::ArithmeticVariable<T> &max_x)
{
    return math::max(min_x, math::min(max_x, x));
}

inline i32 abs  (i32 x) { return select(x >= 0, x, -x);           }
inline i32 sqrt (i32 x) { return cast<i32>(sqrt(cast<f64>(x))); }
inline i32 rsqrt(i32)   { return 0;                               }

CUJ_NAMESPACE_END(cuj::builtin::math)
