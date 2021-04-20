#pragma once

#include <optional>

#include <cuj/ir/op.h>

CUJ_NAMESPACE_BEGIN(cuj::ir)

struct Store;
struct Assign;
struct Break;
struct Continue;
struct Block;
struct If;
struct While;

using Statement = Variant<
    Store, Assign, Break, Continue, Block, If, While>;

struct Store
{
    BasicValue dst_ptr;
    BasicValue src_val;
};

struct Assign
{
    BasicTempValue lhs;
    Value          rhs;
};

struct Break
{
    
};

struct Continue
{
    
};

struct Block
{
    std::vector<RC<Statement>> stats;
};

struct If
{
    struct ThenUnit
    {
        BasicValue cond;
        RC<Block>  block;
    };

    std::vector<ThenUnit> then_units;
    RC<Block>             else_block;
};

struct While
{
    RC<Block>  calculate_cond;
    BasicValue cond;
    RC<Block>  body;
};

CUJ_NAMESPACE_END(cuj::ir)
