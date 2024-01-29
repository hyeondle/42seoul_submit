/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:53:10 by hyeondle          #+#    #+#             */
/*   Updated: 2024/01/13 09:53:26 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
	if (this == &obj)
		return *this;
	_vector = obj._vector;
	_list = obj._list;
	_vectorTime = obj._vectorTime;
	_listTime = obj._listTime;
	return *this;
}

PmergeMe::PmergeMe(int *nums, int size) {
	for (int i = 0; i < size; i++) {
		_vector.push_back(nums[i]);
		_list.push_back(nums[i]);
	}
}

int PmergeMe::jacobsthalNumber(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
}

int PmergeMe::getInsertionIndex(std::vector<int>& mainChain, int count, int thisnum) {
	std::vector<int> temp;

	int tempSize = mainChain.size() / count;
	for (int i = 0; i < tempSize; i++) {
		temp.push_back(mainChain[i * count]);
	}
	int left = 0;
	int right = tempSize;
	int mid;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (temp[mid] <= thisnum) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}

int PmergeMe::getInsertionIndex(std::list<int>& mainChain, int count, int thisnum) {
    std::list<int> temp;
    std::list<int>::iterator it = mainChain.begin();
    int tempSize = mainChain.size() / count;
    for (int i = 0; i < tempSize; i++) {
        temp.push_back(*it);
        std::advance(it, count);
    }
    int left = 0;
    int right = tempSize;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        std::list<int>::iterator midIt = temp.begin();
        std::advance(midIt, mid);
        if (*midIt <= thisnum) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

void PmergeMe::movenums(std::vector<int>& mainChain, std::vector<int>& subChain, int bindex, int j, int count) {
	std::vector<int> temp;
	for (int i = 0; i < count; i++) {
		temp.push_back(subChain[(j - 1) * count + i]);
	}
	for (int i = 0; i < count; i++) {
		mainChain.insert(mainChain.begin() + bindex * count + i, temp[i]);
	}
}

void PmergeMe::movenums(std::list<int>& mainChain, std::list<int>& subChain, int bindex, int j, int count) {
    std::list<int> temp;
    std::list<int>::iterator it = subChain.begin();
	std::advance(it, (j - 1) * count - 1);
    for (int i = 0; i < count; i++) {
		std::advance(it, 1);
        temp.push_back(*it);
    }
	std::list<int>::iterator it1 = mainChain.begin();
	std::advance(it1, bindex * count);
	std::list<int>::iterator it2 = temp.begin();
	for (int i = 0; i < count; i++) {
		mainChain.insert(it1, *it2);
		std::advance(it2, 1);
	}
}

void PmergeMe::fordJohnson(std::vector<int> &nums, int depth) {
	int k = nums.size();
	int oddcheck = 0;
	int count = 1 << depth;
	int n = k / count;
	if (n != 1 && n % 2 == 1) {
		oddcheck = 1;
		n--;
	}
	if (n > 1)
	{
		for (int i = 0; i < n; i = i + 2) {
			if (nums[i * count] > nums[(i + 1) * count]) {
				continue;
			}
			else {
				for (int j = 0; j < count; j++) {
					std::swap(nums[i * count + j], nums[(i + 1) * count + j]);
				}
			}
		}
	}
	else if (n <= 1) {
		return;
	}
	fordJohnson(nums, depth + 1);
	std::vector<int> mainChain;
	std::vector<int> subChain;
	for (int i = 0; i < n; i = i + 2) {
		for (int j = 0; j < count; j++) {
			mainChain.push_back(nums[i * count + j]);
		}
	}
	for (int i = 0; i < n; i = i + 2) {
		for (int j = 0; j < count; j++) {
			subChain.push_back(nums[i * count + count + j]);
		}
	}
	if (oddcheck == 1) {
		for (int j = 0; j < count; j++) {
			subChain.push_back(nums[n * count + j]);
		}
	}
	//insertion
	int jcount = 1;
	int jacobprev = jacobsthalNumber(jcount);
	int jacob = jacobsthalNumber(jcount);
	int bsize = subChain.size() / count;
	int bindex, thisnum;
	thisnum = subChain[(jacob - 1) * count];
	bindex = getInsertionIndex(mainChain, count, thisnum);
	movenums(mainChain, subChain, bindex, jacob, count);
	while (jacob <= bsize) {
		for (int j = jacob; j > jacobprev; j--) {
			thisnum = subChain[(j - 1) * count];
			bindex = getInsertionIndex(mainChain, count, thisnum);
			movenums(mainChain, subChain, bindex, j, count);
		}
		jcount++;
		jacob = jacobsthalNumber(jcount);
		jacobprev = jacobsthalNumber(jcount - 1);
	}
	if (jacob > bsize) {
		for (int j = bsize; j > jacobprev; j--) {
			thisnum = subChain[(j - 1) * count];
			bindex = getInsertionIndex(mainChain, count, thisnum);
			movenums(mainChain, subChain, bindex, j, count);
		}
	}
	for (int i = 0; i < (int)mainChain.size(); i++) {
		nums[i] = mainChain[i];
	}
}

void PmergeMe::fordJohnson(std::list<int> &nums, int depth) {
    int k = nums.size();
    int oddcheck = 0;
    int count = 1 << depth;
    int n = k / count;
    if (n != 1 && n % 2 == 1) {
        oddcheck = 1;
        n--;
    }
    if (n > 1)
	{
        std::list<int>::iterator it = nums.begin();
        for (int i = 0; i < n; i = i + 2) {
            std::list<int>::iterator it1 = it;
			std::list<int>::iterator it2 = it;
            std::advance(it1, count * i);
			std::advance(it2, count * (i + 1));
            if (*it1 > *it2) {
                continue;
            } else {
                for (int j = 0; j < count; j++) {
                    std::swap(*it1, *it2);
					std::advance(it1, 1);
					std::advance(it2, 1);
                }
            }
        }
    } else if (n <= 1) {
        return;
    }
    fordJohnson(nums, depth + 1);

    std::list<int> mainChain;
    std::list<int> subChain;
    std::list<int>::iterator it = nums.begin();
    for (int i = 0; i < n; i = i + 2) {
        for (int j = 0; j < count; j++) {
			std::list<int>::iterator it1 = nums.begin();
			std::advance(it1, i * count + j);
            mainChain.push_back(*it1);
        }
    }
    for (int i = 0; i < n; i = i + 2) {
        for (int j = 0; j < count; j++) {
			std::list<int>::iterator it2 = nums.begin();
			std::advance(it2, i * count + count + j);
            subChain.push_back(*it2);
        }
    }
    if (oddcheck == 1) {
        for (int j = 0; j < count; j++) {
			std::list<int>::iterator it = nums.begin();
			std::advance(it, n * count + j);
			subChain.push_back(*it);
        }
    }

    // Insertion logic
    int jcount = 1;
    int jacobprev = jacobsthalNumber(jcount);
    int jacob = jacobsthalNumber(jcount);
    int bsize = subChain.size() / count;
    int bindex, thisnum;
	it = subChain.begin();
	std::advance(it, (jacob - 1) * count);
	thisnum = *it;
	bindex = getInsertionIndex(mainChain, count, thisnum);
	movenums(mainChain, subChain, bindex, jacob, count);
	std::list<int>::iterator subIt;
    while (jacob <= bsize) {
        subIt = subChain.begin();
        std::advance(subIt, (jacob - 1) * count);
        for (int j = jacob; j > jacobprev; j--) {
            thisnum = *subIt;
            bindex = getInsertionIndex(mainChain, count, thisnum);
            movenums(mainChain, subChain, bindex, j, count);
            std::advance(subIt, -count);
        }
        jcount++;
        jacob = jacobsthalNumber(jcount);
		jacobprev = jacobsthalNumber(jcount - 1);
    }
    if (jacob > bsize) {
        subIt = subChain.begin();
        std::advance(subIt, (bsize - 1) * count);
        for (int j = bsize; j > jacobprev; j--) {
            thisnum = *subIt;
            bindex = getInsertionIndex(mainChain, count, thisnum);
            movenums(mainChain, subChain, bindex, j, count);
            std::advance(subIt, -count);
        }
    }

    for (int i = 0; i < (int)mainChain.size(); i++)
		nums.pop_front();
	it = mainChain.end();
    for (int i = mainChain.size() - 1; i >= 0; i--) {
		std::advance(it, -1);
		nums.push_front(*it);
	}
}

void PmergeMe::run() {
	clock_t start, end;

	start = clock();
	fordJohnson(_vector, 0);
	end = clock();
	_vectorTime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
	start = clock();
	fordJohnson(_list, 0);
	end = clock();
	_listTime = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::print() {
	int size = _vector.size();
	if (size < 7) {
		for (int i = 0; i < (int)_vector.size(); i++) {
			std::cout << _vector[i] << " ";
		}
	} else {
		for (int i = 0; i < 4; i++) {
			std::cout << _vector[i] << " ";
		}
		std::cout << "[...]";;
	}

	////show all nums sorted
	// for (int i = 0; i < _vector.size(); i++) {
	// 	std::cout << _vector[i] << " ";
	// }

	std::cout << std::endl;
	std::cout << std::setprecision(5);
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _vectorTime << " ms" << std::endl;
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << _listTime << " ms" << std::endl;
}