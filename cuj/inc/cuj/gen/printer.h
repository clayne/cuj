#pragma once

#include <map>

#include <cuj/ir/prog.h>
#include <cuj/util/indented_string_builder.h>

CUJ_NAMESPACE_BEGIN(cuj::gen)

class IRPrinter
{
public:

    void set_indent(std::string indent);

    void print(const ir::Program &prog);

    std::string get_result() const;

private:

    void print(const ir::Function &func);

    void print(const ir::StructType *type);

    void print(const ir::Statement &stat);

    void print(const ir::Store &store);

    void print(const ir::Assign &assign);

    void print(const ir::Break &break_s);

    void print(const ir::Continue &continue_s);

    void print(const ir::Block &block);

    void print(const ir::If &if_s);

    void print(const ir::While &while_s);

    std::string get_typename(const ir::Type *type) const;

    std::string get_typename(ir::BuiltinType type) const;

    std::string get_typename(const ir::ArrayType &type) const;

    std::string get_typename(const ir::PointerType &type) const;

    std::string get_typename(const ir::StructType &type) const;

    std::string to_string(const ir::Value &value) const;

    std::string to_string(const ir::BasicValue &val) const;

    std::string to_string(const ir::BasicTempValue &val) const;

    std::string to_string(const ir::BasicImmediateValue &val) const;
    
    std::map<int, std::string> alloc_names_;

    std::map<const ir::StructType *, std::string> struct_names_;

    IndentedStringBuilder str_;
};

CUJ_NAMESPACE_END(cuj::gen)
