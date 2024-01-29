/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:40:03 by Linsio            #+#    #+#             */
/*   Updated: 2024/01/13 09:53:21 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstdio>
# include <map>
# include <iostream>
# include <fstream>

class BitcoinDB
{
	private:
		std::map<std::string, float> _db;
	public:
		BitcoinDB();
		~BitcoinDB();
		BitcoinDB(const BitcoinDB &obj);
		BitcoinDB &operator=(const BitcoinDB &obj);
	public:
		void addDB(std::string date, float price);
		float getCoin(std::string date);
		void show(std::string date, float bitcoin);
		void initDB();
};

class Parser
{
	private:
		Parser();
		~Parser();
		Parser(const Parser &obj);
		Parser &operator=(const Parser &obj);
	public:
		static bool fileCheck(std::string file);
		static void parse(std::string file, BitcoinDB &db);
		static bool validDate(std::string date);
		static bool validValue(std::string value);
		static float stringToFloat(std::string str);
};

class BitcoinExchange
{
	private:
		std::string _file;
		BitcoinDB _db;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);
	public:
		BitcoinExchange(std::string file);
		float getBitcoin();
		void setBitcoin(float bitcoin);
	public:
		void start();
};

#endif