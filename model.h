#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <stdint.h>
#include <QString>
#include <QStringList>

class Model
{
public:
    using value_type        = QString;
    using reference         = value_type&;
    using const_reference   = const value_type&;

    using expressions_type = std::pair<value_type, value_type>;

private:
    value_type expression       = "";
    value_type sub_expression   = "";
    char length                 = 0;
    bool has_comma              = false;
    bool has_op                 = false;
    bool culced                 = false;
    bool was_op                 = false;

    const char MAX_LENGTH = 14;

    QString culc (const_reference, const_reference, const_reference);

public:
    Model() noexcept;
    expressions_type add_digit(const_reference) noexcept;
    expressions_type add_simple_op(const_reference) noexcept;
    expressions_type calculate() noexcept;
    expressions_type clear() noexcept;
    expressions_type clear_all() noexcept;

    expressions_type update(const_reference, const_reference = "");
};

#endif // MODEL_H

