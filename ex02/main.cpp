/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/11 16:41:50 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// int	main(int argc, char **argv)

std::deque<int> sortTwoNumbers(int a, int b)
{
	std::deque<int> array;
	if (a > b)
	{
		array.push_back(b);
		array.push_back(a);
	}
	else
	{
		array.push_back(a);
		array.push_back(b);
	}
	return (array);
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
	for (size_t i = 0; i < array.size(); i++)
	{
		if (i % 2 == 1)
		{
			larger.push_back(returnLarger(array[i - 1], array[i]));
		}
		if (array.size() % 2 == 1 && i == array.size() - 1)
		{
			larger.push_back(array[i]);
		}
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

void	conductSort(std::deque<int> array)
{
	if (array.size() == 2)
	{
		for (size_t i = 0; i < array.size(); i++)
		{
			std::cout << array[i] << ",";
		}
		std::cout << std::endl;
		break ;
	}
	else
	{
		std::deque<int> larger = returnLargerArray(array);
		conductSort(array);
	}
}


int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::deque<int> numbers = {43, 54, 34, 564, 99, 1, 68, 7, 56, 343, 76};
	std::cout << numbers.size() << std::endl;
	std::deque<int> larger = returnLargerArray(numbers);
	std::deque<int> smaller = returnSmallerArray(numbers);
	std::cout << "Larger Array" << std::endl;
	for (size_t i = 0; i < larger.size(); i++)
	{
		std::cout << larger[i] << ",";
	}
	std::cout << std::endl;
	std::cout << "Smaller Array" << std::endl;
	for (size_t i = 0; i < smaller.size(); i++)
	{
		std::cout << smaller[i] << ",";
	}
	std::cout << std::endl;
	// std::deque<int> sorted;
	// for (size_t i = 0; i < numbers.size(); i++)
	// {
	// 	if (i % 2 == 0)
	// 	{
	// 		larger.push_back(numbers[i]);
	// 	}
	// 	else
	// 	{
	// 		smaller.push_back(numbers[i]);
	// 	}
	// }
	// std::deque<int> test = sortTwoNumbers(23, 43);
	// std::cout << test[0] << std::endl;
	// std::cout << test[1] << std::endl;
	return (0);
}

// std::deque<int> numbers = {43, 54, 34, 564, 99, 1, 68, 7, 56, 343, 76};

// 43, 54
// 34, 564,
// 99, 1,
// 68, 7,
// 56, 343,
// 76

// 54, 564, 99, 68, 343, 76,
// 43, 34, 1, 7, 56,

// 54, 564,
// 99, 68,
// 343, 76

// 564, 99, 343,
// 54, 68, 76,
