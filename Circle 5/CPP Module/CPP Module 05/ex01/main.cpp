/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:27:41 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/27 12:14:42 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("Jam", 3);
		Form b("Timmy", 4, 8);
		std::cout << a << b;
		a.signForm(b);
		a.decreament();
		std::cout << a;
		a.signForm(b);
		a.decreament();
		std::cout << a;
		a.signForm(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
