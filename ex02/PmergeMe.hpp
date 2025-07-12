/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:57:55 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/12 19:50:25 by auplisas         ###   ########.fr       */
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
#include <unordered_set>
#include <vector>

class PmergeMe
{
  public:
	// Constructors
	PmergeMe() = delete;
	PmergeMe(const PmergeMe &copy) = delete;
	PmergeMe &operator=(const PmergeMe &copy) = delete;
	~PmergeMe() = delete;
	// Modular Functions
	static int returnLarger(int a, int b);
	static int returnSmaller(int a, int b);
	// deque Funcitons
	static void printArray(std::deque<int> array);
	static std::deque<int> sortTwoNumbers(std::deque<int> array);
	static std::deque<int> returnLargerArray(std::deque<int> array);
	static std::deque<int> returnSmallerArray(std::deque<int> array);
	static void insertInSorted(std::deque<int> &sortedArray, int value, size_t left,
		size_t right);
	static bool contains(const std::deque<size_t> &deq, size_t value);
	static std::deque<size_t> generateJacobsthalNumbers(size_t m);
	static std::deque<size_t> calculateJacobsthalIndices(size_t m);
	static std::deque<int> conductSort(std::deque<int> array);
};