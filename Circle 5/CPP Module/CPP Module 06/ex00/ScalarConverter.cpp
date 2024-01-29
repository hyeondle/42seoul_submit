/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:47:57 by Linsio            #+#    #+#             */
/*   Updated: 2023/10/28 19:12:40 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) {  *this = src;    }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
    if (this != &rhs) {
        *this = rhs;
    }
    return *this;
}

void ScalarConverter::convert(const std::string &literal) {
    int valueI = 0;
    double value = 0.0;

    if (literal == "inf" || literal == "+inf" || literal == "-inf" || literal == "nan" ||
        literal == "inff" || literal == "+inff" || literal == "-inff" || literal == "nanf")
    {
        value = atof(literal.c_str());
    }
    else
    {
        if (!impossible(literal))
        {
            std::cout << "input error" << std::endl;
            return;
        }
        long long int longValue = atoll(literal.c_str());
        if (longValue < INT_MIN || longValue > INT_MAX)
        {
            std::cout << "char: overflow!" << std::endl;
            std::cout << "int: overflow!" << std::endl;
            toFloat(static_cast<double>(longValue));
            toDouble(static_cast<double>(longValue));
            return;
        }
        value = static_cast<double>(longValue);
    }
    toChar(value);
    toInt(value);
    toFloat(value);
    toDouble(value);
}

bool ScalarConverter::impossible(std::string literal)
{
    int flag, flag2;

    flag = 0;
    flag2 = 0;
    for (int i = 0; i < static_cast<int>(literal.size()); i++)
    {
        if ((isdigit(literal[i]) || literal[i] == '.' || literal[i] == 'f') && flag2 != 1)
        {
            if (literal[i] == '.')
                flag++;
            if (literal[i] == 'f')
                flag2++;
            if (flag == 2 || flag2 == 2)
                return false;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void ScalarConverter::toChar(double value)
{
    if (isnan(value) || isinf(value)) {
        std::cout << "char: impossible" << std::endl;
    } else if (value < CHAR_MIN || value > CHAR_MAX) {
        std::cout << "char: overflow!" << std::endl;
    } else {
        char c = static_cast<char>(value);
        if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
}

void ScalarConverter::toInt(double value)
{
    if (isnan(value) || isinf(value)) {
        std::cout << "int: impossible" << std::endl;
    } else if (value < INT_MIN || value > INT_MAX) {
        std::cout << "int: overflow!" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::toFloat(double value)
{
    if (isinf(value)) {
        std::cout << "float: " << value << "f" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
}

void ScalarConverter::toDouble(double value)
{
    std::cout << "double: " << value << std::endl;
}
