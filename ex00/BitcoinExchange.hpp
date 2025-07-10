/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:57:55 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/10 20:18:40 by auplisas         ###   ########.fr       */
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

struct		CSVParsedLine
{
	std::string dateStr;
	std::string btcValueStr;

	int		dateInt;
	float	btcValue;
};

class BitcoinExchange
{
	// static std::vector<std::string> parseCSVLine(const std::string &line);
	// static void readCSV(const std::string &filename);

  public:
	// Constructors
	BitcoinExchange() = delete;
	BitcoinExchange(const BitcoinExchange &copy) = delete;
	BitcoinExchange &operator=(const BitcoinExchange &copy) = delete;
	~BitcoinExchange() = delete;
	static CSVParsedLine parseSingleLine(const std::string &line, char delimiter);
	static std::vector<CSVParsedLine> readFile(const std::string &filename, char delimiter);
	static bool checkIfLegitDate(const std::string &dateStr);
	static bool checkLegitValues(const CSVParsedLine &input);
	static std::string floatToString(float value);
	static void printResults(const std::vector<CSVParsedLine>& allCSVLines, const std::vector<CSVParsedLine>& allInputLines);

};