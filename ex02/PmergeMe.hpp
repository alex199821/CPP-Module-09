/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:57:55 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/12 20:34:53 by auplisas         ###   ########.fr       */
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
	static void dequePrintArray(std::deque<int> array);
	static std::deque<int> dequeReturnLargerArray(std::deque<int> array);
	static std::deque<int> dequeReturnSmallerArray(std::deque<int> array);
	static void dequeInsertInSorted(std::deque<int> &sortedArray, int value, size_t left,
		size_t right);
	static bool dequeContains(const std::deque<size_t> &deq, size_t value);
	static std::deque<size_t> dequeGenerateJacobsthalNumbers(size_t m);
	static std::deque<size_t> dequeCalculateJacobsthalIndices(size_t m);
	static std::deque<int> dequeConductSort(std::deque<int> array);
	static void dequeStartSorting(std::deque<int> array);
};