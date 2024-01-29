/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.HPP                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:41:59 by hyeondle          #+#    #+#             */
/*   Updated: 2024/01/13 09:53:25 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN
{
	private:
		std::stack<double> _stack;
		std::string _order;
	public:
		RPN();
		~RPN();
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);
	public:
		RPN(std::string str);
		void parse(std::string str);
		void push(double value);
		void pop();
		void add();
		void sub();
		void mul();
		void div();
		void print();
		void run();
};

#endif