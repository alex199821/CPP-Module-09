/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/11 00:02:12 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int applyOperator(int a, int b, char op) {
    if (op == '+') 
        return a + b;
    if (op == '-') 
        return a - b;
    if (op == '*') 
        return a * b;
    if (op == '/') {
        if (b == 0) 
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Invalid operator");
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    std::string arg = argv[1];
    std::istringstream iss(arg);
    std::string token;
    std::vector<std::string> tokens;
    std::deque<char> operatorsAr;

    while (iss >> token)
    {
        if ((token.length() == 1 && isdigit(token[0])) ||
            (token.length() == 1 && isOperator(token[0])))
        {
            tokens.push_back(token);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    
    // for (size_t i = 0; i < arg.size(); i++)
    // {
    //     if (isdigit(arg[i]))
    //     {
    //         digitsAr.push_back(arg[i] - '0');
    //     }
    //     else if (isOperator(arg[i]))
    //     {
    //         operatorsAr.push_back(arg[i]);
    //     }
    // }

    // std::cout << "Operators: ";
    // for (size_t i = 0; i < operatorsAr.size(); ++i)
    // {
    //     std::cout << operatorsAr[i] << " ";
    //     if (operatorsAr[i] == '*' || operatorsAr[i] == '/')
    //     {
    //         // handle precedence if needed
    //     }
    // }
    // std::cout << std::endl;

    // std::cout << "Digits: ";
    // for (size_t i = 0; i < digitsAr.size(); ++i)
    // {
    //     std::cout << digitsAr[i] << " ";
    // }
    // std::cout << std::endl;

    return 0;
}