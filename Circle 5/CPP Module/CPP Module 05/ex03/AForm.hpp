/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:28:05 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/26 17:28:24 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>

class AForm
{
	public:
		AForm();
		~AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &assign);
		AForm(std::string name, int signGrade, int executeGrade);
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			executeGrade;
	public:
		std::string	getName() const;
		void		setName(std::string name);
		bool		getIsSigned() const;
		int			getSignGrade();
		int			getExecuteGrade() const;
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
	public:
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm &b);

#endif