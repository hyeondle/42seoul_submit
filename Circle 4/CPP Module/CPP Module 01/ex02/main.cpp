/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:51 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/22 10:24:21 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string motherbrain = "HI THIS IS BRAIN";
	std::string *stringPTR = &motherbrain;
	std::string &stringREF = motherbrain;

	std::cout << "Address of var : " << std::hex << &motherbrain << std::endl;
	std::cout << "Address of ptr : " << std::hex << &stringPTR << std::endl;
	std::cout << "Address of ref : " << std::hex << &stringREF << std::endl;

	std::cout << "Value of var : " << motherbrain << std::endl;
	std::cout << "Value of ptr : " << *stringPTR << std::endl;
	std::cout << "Value of ref : " << stringREF << std::endl;
}