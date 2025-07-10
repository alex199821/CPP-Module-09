/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:57:55 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/10 17:02:26 by auplisas         ###   ########.fr       */
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
};