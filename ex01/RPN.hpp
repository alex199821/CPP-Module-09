/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:57:55 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/10 22:55:33 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>


class RPN
{

  public:
	// Constructors
	RPN() = delete;
	RPN(const RPN &copy) = delete;
	RPN &operator=(const RPN &copy) = delete;
	~RPN() = delete;
	// bool checkValidity();
	std::list<int>  parseNumbers();
	std::list<char>  parseOperations();

};