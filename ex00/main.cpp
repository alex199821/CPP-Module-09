/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:20:46 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/10 17:25:08 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(void)
{
	auto allCSVLines = BitcoinExchange::readFile("data.csv", ',');
	auto allInputLines = BitcoinExchange::readFile("input.txt", '|');

	(void)allCSVLines;
	(void)allInputLines;

    for (size_t i = 0; i < allInputLines.size(); i++)
    {
        const CSVParsedLine& input = allInputLines[i];
    
        if (input.btcValue < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (input.btcValue > 2147483647.0)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        if (!BitcoinExchange::checkIfLegitDate(input.dateStr))
        {
            std::cout << "Error: bad input => " << input.dateStr << std::endl;
            continue;
        }
    
        for (size_t j = 0; j < allCSVLines.size(); j++)
        {
            const CSVParsedLine& csv = allCSVLines[j];
    
            if (input.dateInt == csv.dateInt)
            {
                std::cout << input.dateStr << " => " << input.btcValue << " = " 
                    << std::fixed << std::setprecision(2)
                    << input.btcValue * csv.btcValue << std::endl;
                break;
            }
            else if (j > 0 && input.dateInt < csv.dateInt && input.dateInt > allCSVLines[j - 1].dateInt)
            {
                std::cout << input.dateStr << " => " << input.btcValue << " = " 
                    << std::fixed << std::setprecision(2)
                    << input.btcValue * allCSVLines[j - 1].btcValue << std::endl;
                break;
            }
        }
    }
    
	return (0);
}