/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:33:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/09 22:23:00 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::vector<std::string> BitcoinExchange::parseCSVLine(const std::string& line) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string field;
    std::string cell;

    std::cout << "[" << line << "] ";

    for (char ch : line) {
        if (ch == ',') {
            result.push_back(cell);
            cell.clear();
        } else {
            cell += ch;
        }
    }
    result.push_back(cell);
    return result;
}

std::vector<std::vector<std::string>> BitcoinExchange::readCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::vector<std::string>> allLines;
    while (std::getline(file, line)) {
        auto fields = parseCSVLine(line);
        allLines.push_back(fields);
    }
    return allLines;
}