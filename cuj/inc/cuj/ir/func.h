#pragma once

#include <map>
#include <string>
#include <vector>

#include <cuj/ir/stat.h>

CUJ_NAMESPACE_BEGIN(cuj::ir)

struct Function
{
    enum class Type
    {
        Default,
        Host,
        Device,
        Kernel,
    };

    struct Arg
    {
        int alloc_index;
    };

    Type        type;
    std::string name;

    std::vector<Arg>              args;
    std::map<int, RC<Allocation>> index_to_allocs;

    RC<Block> body;
};

CUJ_NAMESPACE_END(cuj::ir)
