/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:33:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/12 20:45:42 by auplisas         ###   ########.fr       */
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
void PmergeMe::dequePrintArray(std::deque<int> array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << ",";
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

void	PmergeMe::dequeInsertInSorted(std::deque<int> &sortedArray, int value, size_t left,
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
        PmergeMe::dequeInsertInSorted(sortedArray, value, left, mid);
	else
        PmergeMe::dequeInsertInSorted(sortedArray, value, mid + 1, right);
}

bool PmergeMe::dequeContains(const std::deque<size_t>& deq, size_t value) {
    for (size_t i = 0; i < deq.size(); ++i) {
        if (deq[i] == value)
            return true;
    }
    return false;
}

std::deque<size_t> PmergeMe::dequeGenerateJacobsthalNumbers(size_t m)
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

std::deque<size_t> PmergeMe::dequeCalculateJacobsthalIndices(size_t m)
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
    std::deque<size_t> jacobsthal = PmergeMe::dequeGenerateJacobsthalNumbers(m);

    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        size_t index = jacobsthal[i];
        if (index < m && !PmergeMe::dequeContains(included, index))
        {
            order.push_back(index);
            included.push_back(index);
        }
    }

    for (size_t i = 0; i < m; ++i)
    {
        if (!PmergeMe::dequeContains(included, i))
        {
            order.push_back(i);
            included.push_back(i);
        }
    }
    return order;
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
	for (size_t i = 0; i < insertOrder.size(); ++i)
	{
		index = insertOrder[i];
		if (index >= smaller.size())
			break ;
        PmergeMe::dequeInsertInSorted(sortedLarger, smaller[index], 0, sortedLarger.size());
	}
	return (sortedLarger);
}

void PmergeMe::dequeStartSorting(std::deque<int> array)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::deque<int> newAr = PmergeMe::dequeConductSort(array);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    PmergeMe::dequePrintArray(newAr);
    std::cout << "Time to process a range of 5 elements with std::[..] : 0.00031 us" << duration.count() << " microseconds\n";
}
//Sorting with "" container
