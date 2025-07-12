/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:33:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/12 19:52:17 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//Modular Functions
int	PmergeMe::returnLarger(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	PmergeMe::returnSmaller(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

//Sorting with deque container
void PmergeMe::printArray(std::deque<int> array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << ",";
	}
	std::cout << std::endl;
}

std::deque<int> PmergeMe::sortTwoNumbers(std::deque<int> array)
{
	int	a;
	int	b;

	std::deque<int> newArray;
	a = array[0];
	b = array[1];
	if (a > b)
	{
		newArray.push_back(b);
		newArray.push_back(a);
	}
	else
	{
		newArray.push_back(a);
		newArray.push_back(b);
	}
	return (newArray);
}

std::deque<int> PmergeMe::returnLargerArray(std::deque<int> array)
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


std::deque<int> PmergeMe::returnSmallerArray(std::deque<int> array)
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

void	PmergeMe::insertInSorted(std::deque<int> &sortedArray, int value, size_t left,
		size_t right)
{
	size_t	mid;

	if (left >= right)
	{
		sortedArray.insert(sortedArray.begin() + left, value);
		return ;
	}
	mid = left + (right - left) / 2;
	if (value < sortedArray[mid])
        PmergeMe::insertInSorted(sortedArray, value, left, mid);
	else
        PmergeMe::insertInSorted(sortedArray, value, mid + 1, right);
}

bool PmergeMe::contains(const std::deque<size_t>& deq, size_t value) {
    for (size_t i = 0; i < deq.size(); ++i) {
        if (deq[i] == value)
            return true;
    }
    return false;
}

std::deque<size_t> PmergeMe::generateJacobsthalNumbers(size_t m)
{
    size_t next;
    std::deque<size_t> jacobsthal = {0, 1};
    while (true)
    {
        next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
        if (next >= m)
            break;
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

std::deque<size_t> PmergeMe::calculateJacobsthalIndices(size_t m)
{
    std::deque<size_t> order;
    if (m == 0)
        return order;
    if (m == 1)
    {
        order.push_back(0);
        return order;
    }

    std::deque<size_t> included;
    std::deque<size_t> jacobsthal = PmergeMe::generateJacobsthalNumbers(m);

    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        size_t index = jacobsthal[i];
        if (index < m && !PmergeMe::contains(included, index))
        {
            order.push_back(index);
            included.push_back(index);
        }
    }

    for (size_t i = 0; i < m; ++i)
    {
        if (!PmergeMe::contains(included, i))
        {
            order.push_back(i);
            included.push_back(i);
        }
    }
    return order;
}

std::deque<int> PmergeMe::conductSort(std::deque<int> array)
{
	size_t	index;

	if (array.size() <= 1)
		return (array);
	std::deque<int> larger = PmergeMe::returnLargerArray(array);
	std::deque<int> smaller = PmergeMe::returnSmallerArray(array);
	std::deque<int> sortedLarger = PmergeMe::conductSort(larger);
	std::deque<size_t> insertOrder = PmergeMe::calculateJacobsthalIndices(smaller.size());
	for (size_t i = 0; i < insertOrder.size(); ++i)
	{
		index = insertOrder[i];
		if (index >= smaller.size())
			break ;
        PmergeMe::insertInSorted(sortedLarger, smaller[index], 0, sortedLarger.size());
	}
	return (sortedLarger);
}

//Sorting with "" container
