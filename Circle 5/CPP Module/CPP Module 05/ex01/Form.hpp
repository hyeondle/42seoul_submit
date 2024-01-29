/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:27:39 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/26 17:27:42 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>

class Form
{
	public:
		Form();
		~Form();
		Form(const Form &copy);
		Form &operator=(const Form &assign);
		Form(std::string name, int signGrade, int executeGrade);
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			executeGrade;
	public:
		std::string	getName();
		void		setName(std::string name);
		bool		getIsSigned();
		int			getSignGrade();
		int			getExecuteGrade();
	public:
		void		beSigned(Bureaucrat admin);
	public:
		class GradeTooHighException:public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException:public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form &b);

#endif