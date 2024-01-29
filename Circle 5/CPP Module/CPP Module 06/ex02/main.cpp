/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:26:05 by Linsio            #+#    #+#             */
/*   Updated: 2023/10/28 18:48:46 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Identifier.hpp"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    for(int i = 0; i < 5; ++i) {
        Base* instance = generate();
        std::cout << "Pointer identification: ";
        identify(instance);
        std::cout << "Reference identification: ";
        identify(*instance);
        delete instance;
    }
    return 0;
}