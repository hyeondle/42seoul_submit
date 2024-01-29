/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:48:22 by Linsio            #+#    #+#             */
/*   Updated: 2023/10/28 18:46:56 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
    } else {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
    }
    return 0;
}
