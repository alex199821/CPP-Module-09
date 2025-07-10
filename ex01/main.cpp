/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/10 22:48:50 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int	main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::string arg = argv[1];

	std::forward_list<int> digitsAr;
	std::forward_list<char> operatorsAr; 
	for(size_t i = 0; i < arg.size(); i++)
	{
		std::cout << arg[i] << std::endl;
		if(isdigit(arg[i]))
		{
			digitsAr.push_front(arg[i]- '0');
		}
		if(isOperator(arg[i]))
		{
			operatorsAr.push_front(arg[i]);
		}
	}
	for(size_t i = 0; i < arg.size(); i++)
	{
		
	}
	return (0);
}