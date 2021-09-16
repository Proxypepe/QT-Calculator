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
    has_comma = false;
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
    if (expression.size() < MAX_LENGTH)
    {
        expression += symbol;
    }
    return expressions_type(expression, sub_expression);
}

Model::expressions_type Model::add_simple_op(const_reference operation) noexcept
{
    if (!was_op && !culced && !sub_expression.contains(operation) && !has_op)
    {
        sub_expression.append(expression);
        sub_expression.append(" ");
        sub_expression.append(operation);
        was_op = true;
        has_op = true;
        has_comma = false;
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

Model::expressions_type Model::add_dif_op(const_reference op) noexcept
{
    if (!culced)
    {
        if (sub_expression == "")
        {
            expression = culc_dif_op(op);
        }
        else
        {
            sub_expression.append(" ");
            sub_expression.append(culc_dif_op(op));
        }
        culced = true;
    }
    return expressions_type(expression, sub_expression);
}

Model::expressions_type Model::add_comma() noexcept
{
    if  (!has_comma && !culced)
    {
        expression.append(".");
        has_comma = true;
    }
    else if (culced)
    {
        expression = "0.";
        sub_expression = "";
        has_comma = true;
        culced = false;
    }
    return expressions_type(expression, sub_expression);
}

Model::expressions_type Model::calculate() noexcept
{
    auto splited_sub = sub_expression.split(' ');

    if (splited_sub.size() == 2)
    {
        expression = culc(splited_sub[0], expression, splited_sub[1]);
        sub_expression = expression;
        was_op = false;
    }
    else if (splited_sub.size() == 3)
    {
        expression = culc(splited_sub[0], splited_sub[2], splited_sub[1]);
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
    expression = "";
    sub_expression = "";
    return expressions_type(expression, sub_expression);
}

Model::expressions_type Model::deletion() noexcept
{
    auto size = expression.size();
    if (size > 0 && !culced)
    {
        expression = expression.left(size - 1);
    }
    return expressions_type(expression, sub_expression);
}


Model::expressions_type Model::neg_pos() noexcept
{
    if (!culced)
    {
        auto size = expression.size();
        if (expression[0] == '-' && size != 0 && expression != "0")
        {
            expression = expression.right(size - 1);
        }
        else if (size != 0 && expression != "0")
        {
            expression.prepend('-');
        }
    }
    return expressions_type(expression, sub_expression);
}

QString Model::culc_dif_op(const_reference op) noexcept
{
    auto op1 = expression.toDouble();
    QString result = "";
    if (op == "sqr")
    {
        result =  QString::number(pow(op1, 2));
    }
    else if (op == "sqrt")
    {
        result =  QString::number(sqrt(op1));
    }
    else if (op == "one_div")
    {
        result =  QString::number(1/op1);
    }
    return result;
}

Model::expressions_type Model::update(Model::const_reference mode, Model::const_reference symbol)
{
    if (mode == "digit")
        add_digit(symbol);
    else if (mode == "simple_op")
        add_simple_op(symbol);
    else if (mode == "dif_op")
        add_dif_op(symbol);
    else if (mode == "calculate")
        calculate();
    else if (mode == "clear")
        clear();
    else if (mode == "clear_all")
        clear_all();
    else if (mode == "deletion")
        deletion();
    else if (mode == "add_comma")
        add_comma();
    else if (mode == "neg_pos")
        neg_pos();

    return expressions_type(expression, sub_expression);
}

