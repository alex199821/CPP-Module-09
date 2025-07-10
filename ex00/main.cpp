/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:20:46 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/10 19:55:24 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	std::ifstream file(argv[1]);
	if (!file.is_open() || argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open())
	{
		std::cout << "Error: could not open file ./data.csv." << std::endl;
		return (1);
	}
	file.close();
	auto allCSVLines = BitcoinExchange::readFile("data.csv", ',');
	auto allInputLines = BitcoinExchange::readFile(argv[1], '|');
	BitcoinExchange::printResults(allCSVLines, allInputLines);

	return (0);
}