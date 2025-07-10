/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/10 23:03:08 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    std::string arg = argv[1];

    std::deque<int> digitsAr;
    std::deque<char> operatorsAr;

    for (size_t i = 0; i < arg.size(); i++)
    {
        if (isdigit(arg[i]))
        {
            digitsAr.push_back(arg[i] - '0');
        }
        else if (isOperator(arg[i]))
        {
            operatorsAr.push_back(arg[i]);
        }
    }

    std::cout << "Operators: ";
    for (size_t i = 0; i < operatorsAr.size(); ++i)
    {
        std::cout << operatorsAr[i] << " ";
        if (operatorsAr[i] == '*' || operatorsAr[i] == '/')
        {
            // handle precedence if needed
        }
    }
    std::cout << std::endl;

    std::cout << "Digits: ";
    for (size_t i = 0; i < digitsAr.size(); ++i)
    {
        std::cout << digitsAr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}