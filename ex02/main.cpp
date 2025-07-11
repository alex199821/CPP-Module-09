/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/11 15:19:00 by auplisas         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::deque<int> numbers = {43, 54, 34, 564, 99, 1, 68, 7, 56, 343, 76};
	std::deque<int> larger;
	std::deque<int> smaller;
	std::deque<int> sorted; 
	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (i % 2 == 0)
		{
			larger.push_back(numbers[i]);
		}
		else
		{
			smaller.push_back(numbers[i]);
		}
	}

	std::deque<int> test = sortTwoNumbers(23, 43);
	std::cout << test[0] << std::endl;
	std::cout << test[1] << std::endl;
	return (0);
}


std::deque<int> numbers = {43, 54, 34, 564, 99, 1, 68, 7, 56, 343, 76};

43, 54
34, 564, 
99, 1,
68, 7, 
56, 343, 
76

54, 564, 99, 68, 343, 76, 
43, 34, 1, 7, 56, 

54, 564,
99, 68,
343, 76

564, 99, 343, 
54, 68, 76, 

