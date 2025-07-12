/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/12 23:41:26 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	std::deque<int> dequeInput = PmergeMe::parseAndValidateArgs(argc, argv);
	PmergeMe::dequePrintArray("Before: ",dequeInput);
	PmergeMe::dequeStartSorting(dequeInput);
	return (0);
}
