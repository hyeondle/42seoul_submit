/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:53:08 by hyeondle          #+#    #+#             */
/*   Updated: 2024/01/13 09:53:27 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <ctime>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::list<int> _list;
		double _vectorTime, _listTime;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
	public:
		PmergeMe(int *nums, int size);
	private:
		int getInsertionIndex(std::vector<int>& mainChain, int count, int thisnum);
		int getInsertionIndex(std::list<int>& mainChain, int count, int thisnum);
		void movenums(std::vector<int>& mainChain, std::vector<int>& subChain, int bindex, int j, int count);
		void movenums(std::list<int>& mainChain, std::list<int>& subChain, int bindex, int j, int count);
		void fordJohnson(std::vector<int> &nums, int depth);
		void fordJohnson(std::list<int> &nums, int depth);
		int jacobsthalNumber(int n);
	public:
		void run();
		void print();
};

#endif