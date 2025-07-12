/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/12 20:44:56 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::deque<int> numbers = {343, 0, 43, 32344, 34, 7, 43, 564, 56, 68, 43, 99, 1, 54};
	PmergeMe::dequeStartSorting(numbers);
	return (0);
}
