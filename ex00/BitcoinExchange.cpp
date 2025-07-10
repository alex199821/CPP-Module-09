/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:33:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/10 17:33:29 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// struct		CSVParsedLine
// {
// 	std::string dateStr;
// 	int		dateInt;
// 	float	value;
// };

CSVParsedLine BitcoinExchange::parseSingleLine(const std::string &line,
	char delimiter)
{
	CSVParsedLine	result;
	float			btcValue;

	std::string btcValueStr;
	std::string dateStrTemp;
	std::stringstream ss(line);
	std::getline(ss, dateStrTemp, delimiter);
	std::getline(ss, btcValueStr);
	if (delimiter == '|' && !btcValueStr.empty())
		dateStrTemp.erase(dateStrTemp.size() - 1);
	std::string numericDateStr = dateStrTemp;
	numericDateStr.erase(std::remove(numericDateStr.begin(),
			numericDateStr.end(), '-'), numericDateStr.end());
	btcValue = std::strtof(btcValueStr.c_str(), nullptr);
	result.btcValue = std::round(btcValue * 100.0f) / 100.0f;
	result.dateInt = std::atoi(numericDateStr.c_str());
	result.dateStr = dateStrTemp;
	return (result);
}

std::vector<CSVParsedLine> BitcoinExchange::readFile(const std::string &filename,
	char delimiter)
{
	CSVParsedLine	fields;

	std::ifstream file(filename);
	std::string line;
	std::vector<CSVParsedLine> allLines;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		fields = parseSingleLine(line, delimiter);
		allLines.push_back(fields);
	}
	return (allLines);
}

bool BitcoinExchange::checkIfLegitDate(const std::string &dateStr) {
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
        return false;

    std::string yearStr = dateStr.substr(0, 4);
    std::string monthStr = dateStr.substr(5, 2);
    std::string dayStr = dateStr.substr(8, 2);

    for (size_t i = 0; i < 4; ++i)
        if (!isdigit(yearStr[i]))
            return false;
    if (!isdigit(monthStr[0]) || !isdigit(monthStr[1]) ||
        !isdigit(dayStr[0]) || !isdigit(dayStr[1]))
        return false;

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeap && month == 2)
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}
