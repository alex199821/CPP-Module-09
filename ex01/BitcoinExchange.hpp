/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:57:55 by auplisas          #+#    #+#             */
/*   Updated: 2025/07/09 21:03:18 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
    static std::vector<std::string> parseCSVLine(const std::string &line);
    static void readCSV(const std::string &filename);

};