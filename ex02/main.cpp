/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/12 14:29:38 by auplisas         ###   ########.fr       */
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

void insertInSortedRecursive(std::deque<int>& sortedArray, int value, size_t left, size_t right)
{
	if (left >= right)
	{
		sortedArray.insert(sortedArray.begin() + left, value);
		return;
	}

	size_t mid = left + (right - left) / 2;

	if (value < sortedArray[mid])
		insertInSortedRecursive(sortedArray, value, left, mid);
	else
		insertInSortedRecursive(sortedArray, value, mid + 1, right);
}

void insertInSorted(std::deque<int>& sortedArray, int value)
{
	insertInSortedRecursive(sortedArray, value, 0, sortedArray.size());
}

std::deque<int> conductSort(std::deque<int> array)
{
	if (array.size() <= 1)
		return (array);
	std::deque<int> larger = returnLargerArray(array);
	std::deque<int> smaller = returnSmallerArray(array);
	std::deque<int> sortedLarger = conductSort(larger);
	for (size_t i = 0; i < smaller.size(); ++i)
	{
		insertInSorted(sortedLarger, smaller[i]);
	}
	return (sortedLarger);
}

void	printArray(std::deque<int> array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << ",";
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::deque<int> numbers = {343, 43, 34, 7, 564, 56, 68, 99, 1, 54};
	std::deque<int> newAr = conductSort(numbers);
	printArray(newAr);
	return (0);
}

// void	insertInSorted(std::deque<int> &sortedArray, int value)
// {
// 	auto index = std::lower_bound(sortedArray.begin(), sortedArray.end(),value);
// 	sortedArray.insert(index, value);
// }