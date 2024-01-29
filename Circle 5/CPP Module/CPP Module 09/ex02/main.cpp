/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:53:12 by hyeondle          #+#    #+#             */
/*   Updated: 2024/01/13 09:53:24 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) {

	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " [<number> ...]" << std::endl;
		return 0;
	}

	int number;
	int *nums = new int[argc - 1];
	for (int i = 1; i < argc; i++) {
		number = atoi(argv[i]);
		if (number <= 0) {
			std::cout << "Invalid input" << std::endl;
			delete [] nums;
			return 0;
		}
		nums[i - 1] = number;
	}

	if (argc < 8) {
		std::cout << "Before:	";
		for (int i = 0; i < argc - 1; i++) {
			std::cout << nums[i] << " ";
		}
		std::cout << std::endl;
	} else {
		std::cout << "Before:	";
		for (int i = 0; i < 4; i++) {
			std::cout << nums[i] << " ";
		}
		std::cout << "[...]" << std::endl;
	}

	//// show all nums unsorted
	// std::cout << "Before:	";
	// for (int i = 0; i < argc - 1; i++) {
	// 	std::cout << nums[i] << " ";
	// }
	// std::cout << std::endl;

	PmergeMe sets = PmergeMe(nums, argc - 1);
	sets.run();

	std::cout << "After:	";
	sets.print();

	delete [] nums;
}