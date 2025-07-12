/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/13 00:09:40 by macbook          ###   ########.fr       */
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
	std::forward_list<int> fowardListInput = PmergeMe::convertDequeToForwardList(dequeInput);
	PmergeMe::dequePrintArray("Before: ",dequeInput);
	PmergeMe::dequeStartSorting(dequeInput);
	PmergeMe::forwardListStartSorting(fowardListInput);
	return (0);
}
