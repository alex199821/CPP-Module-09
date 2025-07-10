/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:33:47 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/10 20:47:08 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
		dateStrTemp.erase(dateStrTemp.find_last_not_of(" \t\r\n") + 1);
	std::string numericDateStr = dateStrTemp;
	numericDateStr.erase(std::remove(numericDateStr.begin(),
			numericDateStr.end(), '-'), numericDateStr.end());
	btcValue = std::strtof(btcValueStr.c_str(), nullptr);
	result.btcValue = std::round(btcValue * 100.0f) / 100.0f;
	result.dateInt = std::atoi(numericDateStr.c_str());
	result.dateStr = dateStrTemp;
	result.btcValueStr = btcValueStr;
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

bool checkIfOnlyDigits(const std::string& value)
{
	if (value.empty()) return false;
	bool dotSeen = false;

	for (size_t i = 0; i < value.length(); ++i)
	{
		if(value[i] == ' ')
			continue;
		if (value[i] == '.') {
			if (dotSeen) return false;
			dotSeen = true;
		}
		else if (!std::isdigit(value[i])) {
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::checkLegitValues(const CSVParsedLine& input ) {
	if (input.btcValue < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (input.btcValue > 1000.0)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	if (!BitcoinExchange::checkIfLegitDate(input.dateStr))
	{
		std::cout << "Error: bad input => " << input.dateStr << std::endl;
		return (false);
	}
	if(!checkIfOnlyDigits(input.btcValueStr))
	{
		std::cout << "Error: wrong number format." << std::endl;
		return (false);
	}
	return (true);
}


std::string BitcoinExchange::floatToString(float value)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << value;
    std::string str = oss.str();

    while (!str.empty() && str.back() == '0')
        str.pop_back();

    if (!str.empty() && str.back() == '.')
        str.pop_back();

    return str;
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

void BitcoinExchange::printResults(const std::vector<CSVParsedLine>& allCSVLines, const std::vector<CSVParsedLine>& allInputLines)
{

	for (size_t i = 0; i < allInputLines.size(); i++)
	{
		const CSVParsedLine &input = allInputLines[i];
		if (BitcoinExchange::checkLegitValues(input) == false)
			continue ;

		for (size_t j = 0; j < allCSVLines.size(); j++)
		{
			const CSVParsedLine &csv = allCSVLines[j];

			if (input.dateInt == csv.dateInt)
			{
				std::cout << input.dateStr << " => " << BitcoinExchange::floatToString(input.btcValue) << " = " << BitcoinExchange::floatToString(input.btcValue
					* csv.btcValue) << std::endl;
				break ;
			}
			else if (input.dateInt < csv.dateInt
				&& input.dateInt > allCSVLines[j - 1].dateInt)
			{
				std::cout << input.dateStr << " => " << BitcoinExchange::floatToString(input.btcValue) << " = " << BitcoinExchange::floatToString(input.btcValue
					* allCSVLines[j - 1].btcValue) << std::endl;
				break ;
			}
			else if (input.dateInt < allCSVLines[0].dateInt)
			{
				std::cout << input.dateStr << " => " << BitcoinExchange::floatToString(input.btcValue) << " = " << BitcoinExchange::floatToString(input.btcValue
					* allCSVLines[0].btcValue) << std::endl;
				break ;
			}
			else if (input.dateInt > allCSVLines[allCSVLines.size()
				- 1].dateInt)
			{
				std::cout << input.dateStr << " => " << BitcoinExchange::floatToString(input.btcValue) << " = " << BitcoinExchange::floatToString(input.btcValue
					* allCSVLines[allCSVLines.size() - 1].btcValue) << std::endl;
				break ;
			}
		}
	}
}
