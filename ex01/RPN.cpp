/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:33:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/11 01:31:00 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOperator(int a, int b, char oper)
{
	if (oper == '+')
		return (a + b);
	if (oper == '-')
		return (a - b);
	if (oper == '*')
		return (a * b);
	if (oper == '/')
	{
		if (b == 0)
			throw std::runtime_error("Division by zero");
		return (a / b);
	}
	throw std::runtime_error("Invalid operator");
}

int RPN::processRpn(const std::string arg)
{
	int	b;
	int	a;
	int	result;

	std::istringstream iss(arg);
	std::string token;
	std::vector<std::string> tokens;
	std::deque<int> stack;
	while (iss >> token)
	{
		if ((token.length() == 1 && isdigit(token[0])) || (token.length() == 1
				&& RPN::isOperator(token[0])))
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
		else if (RPN::isOperator(tokens[i][0]))
		{
			if (stack.size() < 2)
			{
				std::cout << "Error" << std::endl;
				return (1);
			}
			b = stack.back();
			stack.pop_back();
			a = stack.back();
			stack.pop_back();
			result = RPN::applyOperator(a, b, tokens[i][0]);
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
    return (stack.back());
}
