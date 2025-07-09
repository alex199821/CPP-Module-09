/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:20:46 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/09 22:10:26 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main()
{
    auto allLines = BitcoinExchange::readCSV("data.csv");
    (void)allLines;
    // for (const auto& lineFields : allLines) {
    //     for (const auto& field : lineFields) {
    //         std::cout << "[" << field << "] ";
    //     }
    //     std::cout << "\n";
    // }
    return (0);
}