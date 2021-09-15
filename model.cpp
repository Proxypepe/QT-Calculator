#include "model.h"

// Impliment all logic,

Model::Model()  noexcept : expression(""), sub_expression(""), has_comma(false)
{

}

Model::value_type Model::culc(const_reference first, const_reference second, const_reference action)
{
    auto op1 = first.toDouble();
    auto op2 = second.toDouble();
    double result = 0;
    if (action == "+")
        result = op1 + op2;
    else if (action == "-")
        result = op1 - op2;
    else if (action == "*")
        result = op1 * op2;
    else if (action == "/" && op2 != 0)
        result = op1 / op2;
    culced = true;
    was_op = false;
    has_op = false;
    length = 0;
    return QString::number(result);
}

Model::expressions_type Model::add_digit(const_reference symbol) noexcept
{
    if (was_op)
    {
        expression = "";
        was_op = false;
    }
    else if (!was_op && culced)
    {
        expression      = "";
        sub_expression  = "";
        culced = false;
    }
    if (length < MAX_LENGTH)
    {
        expression += symbol;
        length++;
    }
    return expressions_type(expression, sub_expression);
}

Model::expressions_type Model::add_simple_op(const QString& operation) noexcept
{
    if (!was_op && !culced && !sub_expression.contains(operation) && !has_op)
    {
        sub_expression.append(expression);
        sub_expression.append(" ");
        sub_expression.append(operation);
        length = 0;
        was_op = true;
        has_op = true;
    }
    else if (sub_expression.contains(operation))
    {
        auto splited_sub = sub_expression.split(' ');

        expression = culc(splited_sub[0], expression, splited_sub[1]);
        sub_expression = expression;
        was_op = false;
    }
    else if (was_op && sub_expression.contains(operation))
    {

    }
    return expressions_type(expression, sub_expression);
}

Model::expressions_type Model::calculate() noexcept
{
    auto splited_sub = sub_expression.split(' ');

    if (splited_sub.size() != 1)
    {
        expression = culc(splited_sub[0], expression, splited_sub[1]);
        sub_expression = expression;
        was_op = false;
    }
    return expressions_type(expression, sub_expression);
}

Model::expressions_type Model::clear() noexcept
{
    expression = (expression == '0') ? "0" : "";
    return expressions_type(expression, sub_expression);
}

Model::expressions_type Model::clear_all() noexcept
{
    was_op = false;
    has_op = false;
    culced = false;
    length = 0;
    expression = "";
    sub_expression = "";
    return expressions_type(expression, sub_expression);
}

Model::expressions_type Model::update(Model::const_reference mode, Model::const_reference symbol)
{
    if (mode == "digit")
        add_digit(symbol);
    else if (mode == "simple_op")
        add_simple_op(symbol);
    else if (mode == "calculate")
        calculate();
    else if (mode == "clear")
        clear();
    else if (mode == "clear_all")
        clear_all();
    return expressions_type(expression, sub_expression);
}

