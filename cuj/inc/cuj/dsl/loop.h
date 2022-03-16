#pragma once

#include <type_traits>

#include <cuj/dsl/arithmetic.h>
#include <cuj/utils/uncopyable.h>

CUJ_NAMESPACE_BEGIN(cuj::dsl)

class LoopBuilder : public Uncopyable
{
public:

    template<typename F>
    void operator+(F &&body_func);
};

class WhileBuilder : public Uncopyable
{
    RC<core::Block> cond_block_;
    core::Expr      cond_;

public:

    template<typename F>
        requires (!std::is_same_v<WhileBuilder, std::remove_cvref_t<F>>)
    explicit WhileBuilder(F &&cond_func);

    template<typename F>
    void operator+(F &&body_func);
};

template<typename IT>
class ForRangeBuilder : public Uncopyable
{
    static_assert(is_cuj_arithmetic_v<IT>);

    IT &idx_, beg_, end_;

public:

    ForRangeBuilder(IT &idx, IT beg, IT end);

    template<typename F>
    void operator+(F &&body_func);
};

struct ForRangeCondVar
{
    operator bool() const
    {
        static thread_local bool ret = false;
        ret = !ret;
        return ret;
    }
};

inline void _add_break_statement();
inline void _add_continue_statement();

#define CUJ_LOOP ::cuj::dsl::LoopBuilder{}+[&]()->void
#define CUJ_WHILE(COND)                                                         \
    ::cuj::dsl::WhileBuilder(                                                   \
        [&]()->::cuj::dsl::num<bool>{return(COND);})+[&]()->void
#define CUJ_FORRANGE(I, BEG, END)                                               \
    for(::cuj::dsl::remove_var_wrapper_t<decltype(::cuj::dsl::var(BEG))>        \
        I = BEG; ::cuj::dsl::ForRangeCondVar();)                                \
        ::cuj::dsl::ForRangeBuilder<decltype(I)>(I, BEG, END)+[&]

#define $loop CUJ_LOOP
#define $while CUJ_WHILE
#define $forrange CUJ_FORRANGE

#define CUJ_BREAK    (::cuj::dsl::_add_break_statement())
#define CUJ_CONTINUE (::cuj::dsl::_add_continue_statement())
#define $break    CUJ_BREAK
#define $continue CUJ_CONTINUE

CUJ_NAMESPACE_END(cuj::dsl)
