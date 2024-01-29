/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:31:17 by Linsio            #+#    #+#             */
/*   Updated: 2024/01/13 09:53:23 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN &obj){*this = obj;}
RPN &RPN::operator=(const RPN &obj)
{
	if (this != &obj)
	{
		this->_stack = obj._stack;
		this->_order = obj._order;
	}
	return (*this);
}

RPN::RPN(std::string str)
{
	this->_order = str;
}

void RPN::parse(std::string str)
{
	std::string::iterator it = str.begin();
	std::string::iterator ite = str.end();
	std::string tmp;

	while (it != ite)
	{
		if (*it == ' ')
		{
			if (tmp.size() > 0)
			{
				this->_order += tmp;
				this->_order += ' ';
				tmp.clear();
			}
		}
		else
			tmp += *it;
		it++;
	}
	if (tmp.size() > 0)
	{
		this->_order += tmp;
		this->_order += ' ';
		tmp.clear();
	}
}

void RPN::push(double value)
{
	this->_stack.push(value);
}

void RPN::pop()
{
	if (this->_stack.size() > 0)
		this->_stack.pop();
}

void RPN::add()
{
	if (this->_stack.size() > 1)
	{
		double a = this->_stack.top();
		this->_stack.pop();
		double b = this->_stack.top();
		this->_stack.pop();
		this->_stack.push(b + a);
	}
	// else if (this->_stack.size() <= 1) {
	// 	std::cout << "ERROR: There is only one or no elements in stack" << std::endl;
	// 	std::exit(1);
	// }
}

void RPN::sub()
{
	if (this->_stack.size() > 1)
	{
		double a = this->_stack.top();
		this->_stack.pop();
		double b = this->_stack.top();
		this->_stack.pop();
		this->_stack.push(b - a);
	}
	// else if (this->_stack.size() <= 1) {
	// 	std::cout << "ERROR: There is only one or no elements in stack" << std::endl;
	// 	std::exit(1);
	// }
}

void RPN::mul()
{
	if (this->_stack.size() > 1)
	{
		double a = this->_stack.top();
		this->_stack.pop();
		double b = this->_stack.top();
		this->_stack.pop();
		this->_stack.push(b * a);
	}
	// else if (this->_stack.size() <= 1) {
	// 	std::cout << "ERROR: There is only one or no elements in stack" << std::endl;
	// 	std::exit(1);
	// }
}

void RPN::div()
{
	if (this->_stack.size() > 1)
	{
		double a = this->_stack.top();
		this->_stack.pop();
		double b = this->_stack.top();
		this->_stack.pop();
		this->_stack.push(b / a);
	}
	// else if (this->_stack.size() <= 1) {
	// 	std::cout << "ERROR: There is only one or no elements in stack" << std::endl;
	// 	std::exit(1);
	// }
}

void RPN::print()
{
	if (this->_stack.size() > 0)
	{
		double a = this->_stack.top();
		std::cout << a << std::endl;
	}
}

void RPN::run()
{
    std::istringstream iss(this->_order);
    std::string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
        {
            this->push(std::stod(token));
        }
        else
        {
            if (token == "+") this->add();
            else if (token == "-") this->sub();
            else if (token == "*") this->mul();
            else if (token == "/") this->div();
            else
            {
                std::cerr << "ERROR: Invalid token: " << token << std::endl;
                std::exit(1);
            }
        }
    }

    this->print();
}