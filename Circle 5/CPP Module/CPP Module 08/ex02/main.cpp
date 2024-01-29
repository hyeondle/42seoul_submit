/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:39:11 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/04 22:05:15 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Current size: " << mstack.size() << std::endl;
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	mstack.push(7);
	mstack.push(8);
	mstack.push(9);
	mstack.push(10);
	mstack.push(11);
	mstack.push(12);

	std::cout << "Stack contents (regular iterator):" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << "Stack contents (const iterator):" << std::endl;
	for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << "Stack contents (reverse iterator):" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << std::endl;
	}

	std::cout << "Stack contents (const reverse iterator):" << std::endl;
	for (MutantStack<int>::const_reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
		std::cout << *rit << std::endl;
	}

	MutantStack<int> copiedStack(mstack);

	std::cout << "Comparing original and copied stack:" << std::endl;
	MutantStack<int>::iterator it_original = mstack.begin();
	MutantStack<int>::iterator it_copied = copiedStack.begin();
	bool isEqual = true;
	while (it_original != mstack.end() && it_copied != copiedStack.end()) {
		if (*it_original != *it_copied) {
			isEqual = false;
			break;
		}
		++it_original;
		++it_copied;
	}
	std::cout << "The stacks are " << (isEqual ? "equal." : "not equal.") << std::endl;

	MutantStack<int> assignedStack;
	assignedStack = mstack;
	std::cout << "Top element of assigned stack: " << assignedStack.top() << std::endl;

	return 0;
}

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }