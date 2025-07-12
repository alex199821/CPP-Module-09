/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/12 17:47:51 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::deque<int> sortTwoNumbers(std::deque<int> array)
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

int	returnLarger(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	returnSmaller(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

std::deque<int> returnLargerArray(std::deque<int> array)
{
	std::deque<int> larger;
	for (size_t i = 0; i + 1 < array.size(); i += 2)
	{
		larger.push_back(returnLarger(array[i], array[i + 1]));
	}
	if (array.size() % 2 == 1)
	{
		larger.push_back(array.back());
	}
	return (larger);
}

std::deque<int> returnSmallerArray(std::deque<int> array)
{
	std::deque<int> smaller;
	for (size_t i = 0; i < array.size(); i++)
	{
		if (i % 2 == 1)
		{
			smaller.push_back(returnSmaller(array[i - 1], array[i]));
		}
	}
	return (smaller);
}

void	insertInSorted(std::deque<int> &sortedArray, int value, size_t left,
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
		insertInSorted(sortedArray, value, left, mid);
	else
		insertInSorted(sortedArray, value, mid + 1, right);
}

void	printArray(std::deque<int> array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << ",";
	}
	std::cout << std::endl;
}

void	printArraySizeT(std::deque<size_t> array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << ",";
	}
	std::cout << std::endl;
}

bool contains(const std::deque<size_t>& deq, size_t value) {
    for (size_t v : deq) {
        if (v == value) return true;
    }
    return false;
}

std::deque<size_t> generateJacobsthalNumbers(size_t m)
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

std::deque<size_t> calculateJacobsthalIndices(size_t m)
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
    std::deque<size_t> jacobsthal = generateJacobsthalNumbers(m);

    for (size_t i = 0; i < jacobsthal.size(); ++i)
    {
        size_t index = jacobsthal[i];
        if (index < m && !contains(included, index))
        {
            order.push_back(index);
            included.push_back(index);
        }
    }

    for (size_t i = 0; i < m; ++i)
    {
        if (!contains(included, i))
        {
            order.push_back(i);
            included.push_back(i);
        }
    }
    return order;
}

std::deque<int> conductSort(std::deque<int> array)
{
	size_t	index;

	if (array.size() <= 1)
		return (array);
	std::deque<int> larger = returnLargerArray(array);
	std::deque<int> smaller = returnSmallerArray(array);
	std::deque<int> sortedLarger = conductSort(larger);
	std::deque<size_t> insertOrder = calculateJacobsthalIndices(smaller.size());
	for (size_t i = 0; i < insertOrder.size(); ++i)
	{
		index = insertOrder[i];
		if (index >= smaller.size())
			break ;
		insertInSorted(sortedLarger, smaller[index], 0, sortedLarger.size());
	}
	return (sortedLarger);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::deque<int> numbers = {343, 43, 32344, 34, 7, 564, 56, 68, 99, 1, 54};
	std::deque<int> newAr = conductSort(numbers);
	printArray(newAr);
	return (0);
}
