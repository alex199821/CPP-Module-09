/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:57:55 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/11 01:30:18 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

class RPN
{
  public:
	// Constructors
	RPN() = delete;
	RPN(const RPN &copy) = delete;
	RPN &operator=(const RPN &copy) = delete;
	~RPN() = delete;
	static bool isOperator(char c);
	static int applyOperator(int a, int b, char oper);
	static int processRpn(const std::string arg);
};