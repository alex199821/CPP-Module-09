/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:33:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/13 00:52:53 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Modular Functions
bool PmergeMe::isValidInteger(const std::string &string)
{
	size_t	start;

	if (string.empty())
		return (false);
	start = 0;
	if (string[0] == '-')
	{
		if (string.size() == 1)
			return (false);
		start = 1;
	}
	for (size_t i = start; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
			return (false);
	}
	return (true);
}

std::deque<int> PmergeMe::parseAndValidateArgs(int argc, char **argv)
{
	int	number;

	std::deque<int> result;
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		if (!PmergeMe::isValidInteger(arg))
		{
			std::cout << "Invalid arguments" << std::endl;
			exit(1);
		}
		number = std::stoi(arg);
		result.push_back(number);
	}
	return (result);
}

int PmergeMe::returnLarger(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int PmergeMe::returnSmaller(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

// Sorting with deque container
void PmergeMe::dequePrintArray(std::string descriptor, std::deque<int> array)
{
	std::cout << descriptor;
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

std::deque<int> PmergeMe::dequeReturnLargerArray(std::deque<int> array)
{
	std::deque<int> larger;
	for (size_t i = 0; i + 1 < array.size(); i += 2)
	{
		larger.push_back(PmergeMe::returnLarger(array[i], array[i + 1]));
	}
	if (array.size() % 2 == 1)
	{
		larger.push_back(array.back());
	}
	return (larger);
}

std::deque<int> PmergeMe::dequeReturnSmallerArray(std::deque<int> array)
{
	std::deque<int> smaller;
	for (size_t i = 0; i < array.size(); i++)
	{
		if (i % 2 == 1)
		{
			smaller.push_back(PmergeMe::returnSmaller(array[i - 1], array[i]));
		}
	}
	return (smaller);
}

void PmergeMe::dequeInsertInSorted(std::deque<int> &sortedArray, int value,
	size_t left, size_t right)
{
	size_t	mid;

	if (left >= right)
	{
		sortedArray.insert(sortedArray.begin() + left, value);
		return ;
	}
	mid = left + (right - left) / 2;
	if (value < sortedArray[mid])
		PmergeMe::dequeInsertInSorted(sortedArray, value, left, mid);
	else
		PmergeMe::dequeInsertInSorted(sortedArray, value, mid + 1, right);
}

bool PmergeMe::dequeContains(const std::deque<size_t> &deq, size_t value)
{
	for (size_t i = 0; i < deq.size(); i++)
	{
		if (deq[i] == value)
			return (true);
	}
	return (false);
}

std::deque<size_t> PmergeMe::dequeGenerateJacobsthalNumbers(size_t m)
{
	size_t	next;

	std::deque<size_t> jacobsthal = {0, 1};
	while (true)
	{
		next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next >= m)
			break ;
		jacobsthal.push_back(next);
	}
	return (jacobsthal);
}

std::deque<size_t> PmergeMe::dequeCalculateJacobsthalIndices(size_t m)
{
	size_t	index;

	std::deque<size_t> order;
	if (m == 0)
		return (order);
	if (m == 1)
	{
		order.push_back(0);
		return (order);
	}
	std::deque<size_t> included;
	std::deque<size_t> jacobsthal = PmergeMe::dequeGenerateJacobsthalNumbers(m);
	for (size_t i = 0; i < jacobsthal.size(); i++)
	{
		index = jacobsthal[i];
		if (index < m && !PmergeMe::dequeContains(included, index))
		{
			order.push_back(index);
			included.push_back(index);
		}
	}
	for (size_t i = 0; i < m; i++)
	{
		if (!PmergeMe::dequeContains(included, i))
		{
			order.push_back(i);
			included.push_back(i);
		}
	}
	return (order);
}

std::deque<int> PmergeMe::dequeConductSort(std::deque<int> array)
{
	size_t	index;

	if (array.size() <= 1)
		return (array);
	std::deque<int> larger = PmergeMe::dequeReturnLargerArray(array);
	std::deque<int> smaller = PmergeMe::dequeReturnSmallerArray(array);
	std::deque<int> sortedLarger = PmergeMe::dequeConductSort(larger);
	std::deque<size_t> insertOrder = PmergeMe::dequeCalculateJacobsthalIndices(smaller.size());
	for (size_t i = 0; i < insertOrder.size(); i++)
	{
		index = insertOrder[i];
		if (index >= smaller.size())
			break ;
		PmergeMe::dequeInsertInSorted(sortedLarger, smaller[index], 0,
			sortedLarger.size());
	}
	return (sortedLarger);
}

void PmergeMe::dequeStartSorting(std::deque<int> array)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::deque<int> newAr = PmergeMe::dequeConductSort(array);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end
			- start);
	PmergeMe::dequePrintArray("After: ", newAr);
	std::cout << "Time to process a range of " << array.size() << " elements with std::deque : " << duration.count() << " us\n";
}
// Sorting with forwardlist container

std::forward_list<int> PmergeMe::convertDequeToForwardList(const std::deque<int> &input)
{
	std::forward_list<int> result;
	auto iterator = result.before_begin();
	for (size_t i = 0; i < input.size(); i++)
		iterator = result.insert_after(iterator, input[i]);
	return (result);
}

std::forward_list<int> PmergeMe::forwardListReturnLargerArray(const std::forward_list<int> &list)
{
	int		first;
	int		second;

	std::forward_list<int> result;
	auto it = list.begin();
	while (it != list.end())
	{
		first = *it++;
		if (it != list.end())
		{
			second = *it++;
			result.push_front(returnLarger(first, second));
		}
		else
		{
			result.push_front(first);
		}
	}
	result.reverse();
	return (result);
}

std::forward_list<int> PmergeMe::forwardListReturnSmallerArray(const std::forward_list<int> &list)
{
	int		first;
	int		second;

	std::forward_list<int> result;
	auto it = list.begin();
	while (it != list.end())
	{
		first = *it++;
		if (it != list.end())
		{
			second = *it++;
			result.push_front(returnSmaller(first, second));
		}
	}
	result.reverse();
	return (result);
}

void PmergeMe::forwardListInsertInSorted(std::forward_list<int> &sorted,
	int value)
{
	auto it = sorted.before_begin();
	auto next = sorted.begin();
	while (next != sorted.end() && *next < value)
	{
		it++;
		next++;
	}
	sorted.insert_after(it, value);
}

bool PmergeMe::forwardListContains(const std::forward_list<size_t> &list,
	size_t value)
{
	for (size_t val : list)
		if (val == value)
			return (true);
	return (false);
}

std::forward_list<size_t> PmergeMe::forwardListGenerateJacobsthalNumbers(size_t m)
{
	size_t	next;

	std::forward_list<size_t> list = {0, 1};
	auto it1 = list.begin();
	auto it2 = std::next(list.begin());
	while (true)
	{
		next = *it2 + 2 * (*it1);
		if (next >= m)
			break ;
		list.push_front(next);
		it1 = list.begin();
		it2 = std::next(it1);
	}
	list.reverse();
	return list;
}

std::forward_list<size_t> PmergeMe::forwardListCalculateJacobsthalIndices(size_t m)
{
	std::forward_list<size_t> order;
	if (m == 0)
		return order;
	if (m == 1)
		return {0};
	std::forward_list<size_t> included;
	std::forward_list<size_t> jacobsthal = forwardListGenerateJacobsthalNumbers(m);
	for (size_t val : jacobsthal)
	{
		if (val < m && !forwardListContains(included, val))
		{
			order.push_front(val);
			included.push_front(val);
		}
	}
	for (size_t i = 0; i < m; i++)
	{
		if (!forwardListContains(included, i))
		{
			order.push_front(i);
			included.push_front(i);
		}
	}
	order.reverse();
	return order;
}

std::forward_list<int> PmergeMe::forwardListConductSort(const std::forward_list<int> &list)
{
	if (std::next(list.begin()) == list.end())
		return list;

	std::forward_list<int> larger = forwardListReturnLargerArray(list);
	std::forward_list<int> smaller = forwardListReturnSmallerArray(list);

	std::forward_list<int> sorted = forwardListConductSort(larger);
	std::forward_list<size_t> order = forwardListCalculateJacobsthalIndices(std::distance(smaller.begin(), smaller.end()));

	std::forward_list<int> smallerCopy;
	for (std::forward_list<int>::const_iterator it = smaller.begin(); it != smaller.end(); it++)
		smallerCopy.push_front(*it);
	smallerCopy.reverse();

	for (std::forward_list<size_t>::const_iterator it = order.begin(); it != order.end(); it++)
	{
		size_t idx = *it;
		size_t i = 0;
		std::forward_list<int>::const_iterator it_val = smallerCopy.begin();
		while (i < idx && it_val != smallerCopy.end())
		{
			it_val++;
			i++;
		}
		if (it_val != smallerCopy.end())
			forwardListInsertInSorted(sorted, *it_val);
	}

	return sorted;
}

void PmergeMe::forwardListPrintArray(std::string descriptor, const std::forward_list<int>& list) {
    std::cout << descriptor;
    for (int val : list)
        std::cout << val << " ";
    std::cout << "\n";
}

void PmergeMe::forwardListStartSorting(const std::forward_list<int> &list)
{
	auto start = std::chrono::high_resolution_clock::now();
	std::forward_list<int> sorted = forwardListConductSort(list);
	// forwardListPrintArray("Before: ", sorted);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Time to process a range of " << std::distance(list.begin(), list.end()) << " elements with std::forward_list : " << duration.count() << " us\n";
}