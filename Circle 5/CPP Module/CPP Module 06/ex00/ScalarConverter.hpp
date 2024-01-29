/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:47:40 by Linsio            #+#    #+#             */
/*   Updated: 2023/10/28 18:58:54 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &src);
    public:
        static void convert(const std::string &literal);
    private:
        static void toChar(double value);
        static void toInt(double value);
        static void toFloat(double value);
        static void toDouble(double value);
        static bool impossible(std::string literal);
};

#endif