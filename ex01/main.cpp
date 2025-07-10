/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 22:07:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/11 01:20:59 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	applyOperator(int a, int b, char operator)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Division by zero");
		return (a / b);
	}
	throw std::runtime_error("Invalid operator");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	std::string arg = argv[1];
	std::istringstream iss(arg);
	std::string token;
	std::vector<std::string> tokens;
	std::deque<int> stack;

	while (iss >> token)
	{
		if ((token.length() == 1 && isdigit(token[0])) || (token.length() == 1
				&& isOperator(token[0])))
		{
			tokens.push_back(token);
		}
		else
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
	}
	for (size_t i = 0; i < tokens.size(); i++)
	{
		if (isdigit(tokens[i][0]))
		{
			stack.push_back(tokens[i][0] - '0');
		}
		else if (isOperator(tokens[i][0]))
		{
			if (stack.size() < 2)
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			int b = stack.back();
			stack.pop_back();
			int a = stack.back();
			stack.pop_back();
			int result = applyOperator(a, b, tokens[i][0]);
			stack.push_back(result);
		}
		else
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
	}

	if (stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::cout << stack.back() << std::endl;
	return (0);
}