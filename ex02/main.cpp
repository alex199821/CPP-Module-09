/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/11 17:48:59 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// int	main(int argc, char **argv)

std::deque<int> sortTwoNumbers(std::deque<int> array)
{
	std::deque<int> newArray;
	int a = array[0];
	int b = array[1];
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
	size_t i = 0;

	while (i + 1 < array.size())
	{
		larger.push_back(returnLarger(array[i], array[i + 1]));
		i += 2;
	}

	// Handle leftover if size is odd
	if (array.size() % 2 == 1)
	{
		larger.push_back(array.back());
	}

	return larger;
}

// std::deque<int> returnLargerArray(std::deque<int> array)
// {
// 	std::deque<int> larger;
// 	for (size_t i = 0; i < array.size(); i=i+2)
// 	{
// 		if (i % 2 == 1)
// 		{
// 			std::cout << "Index is: " << i << std::endl;
// 			larger.push_back(returnLarger(array[i - 1], array[i]));
// 		}
// 		// if (array.size() % 2 == 1 && i == array.size() - 1)
// 		// {
// 		// 	larger.push_back(array[i]);
// 		// }
// 	}
// 	return (larger);
// }

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

void printArray(std::deque<int> array)
{
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << ",";
	}
	std::cout << std::endl;
}

void	conductSort(std::deque<int> array, std::deque<int> smallArray)
{
	(void)smallArray;
	// std::deque<int> newArray = array; 

		// std::deque<int>  sortedArray = sortTwoNumbers(array);
		// std::deque<int>  sortedSmallArray = sortTwoNumbers(smallArray);
		printArray(array);
		std::cout << std::endl;
		// printArray(smallArray);
	
	if (array.size() == 2)
	{
		
		std::deque<int>  sortedArray = sortTwoNumbers(array);
		// std::deque<int>  sortedSmallArray = sortTwoNumbers(smallArray);
		printArray(sortedArray);
		std::cout << std::endl;
		printArray(smallArray);

		return;
	}
	else
	{
		std::deque<int> larger = returnLargerArray(array);
		std::deque<int> smaller = returnSmallerArray(array);
		conductSort(larger, smaller);
	}
}


int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::deque<int> numbers = {43, 54, 34, 564, 99, 1, 68, 7, 56, 343};
	std::deque<int> finalAr = {	1, 7, 34, 43, 54, 56, 68, 99, 343, 564};
	std::deque<int> smallArray;
	conductSort(numbers, smallArray);
	
	return (0);
}

