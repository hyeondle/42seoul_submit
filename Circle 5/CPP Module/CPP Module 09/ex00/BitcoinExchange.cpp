/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:59:58 by Linsio            #+#    #+#             */
/*   Updated: 2024/01/13 09:53:20 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstring>
#include <exception>
#include <string>
#include <sstream>

//					//
//	BitcoinExchange	//
//					//

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)	{	*this = obj;	}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this == &obj)
		return (*this);
	_file = obj._file;
	_db = obj._db;
	return (*this);
}

BitcoinExchange::BitcoinExchange(std::string file)
{
	_file = file;
}

void BitcoinExchange::start()
{
	if (Parser::fileCheck(_file) == false)
		return ;
	_db.initDB();
	Parser::parse(_file, _db);
}

//				//
// BitcoinDB	//
//				//

BitcoinDB::BitcoinDB(){}
BitcoinDB::~BitcoinDB(){}
BitcoinDB::BitcoinDB(const BitcoinDB &obj)	{	*this = obj;	}
BitcoinDB& BitcoinDB::operator=(const BitcoinDB &obj)
{
	if (this == &obj)
		return (*this);
	_db = obj._db;
	return (*this);
}

void BitcoinDB::addDB(std::string date, float price)
{
	_db[date] = price;
}

float BitcoinDB::getCoin(std::string date)
{
	return (_db[date]);
}

void BitcoinDB::show(std::string date, float bitcoin)
{
	// if (Parser::validDate(date) == false)
	// {
	// 	std::cout << "Error: invalid date format. Usage : XXXX-XX-XX" << std::endl;
	// 	return ;
	// }
	std::map<std::string, float>::iterator it = _db.lower_bound(date);
    if (it != _db.end() && it->first == date) {
        std::cout << std::fixed << std::setprecision(2) << date << " => " << bitcoin << " = "<< it->second * bitcoin << std::endl;
    } else {
        if (it != _db.begin()) {
            --it;
            std::cout << std::fixed << std::setprecision(2) << date << " => " << bitcoin << " = "<< it->second * bitcoin << std::endl;
        } else {
            std::cout << "Error: date not found and no previous date available" << std::endl;
        }
    }
}

//			//
//	Parser	//
//			//

Parser::Parser(){}
Parser::~Parser(){}
Parser::Parser(const Parser &obj)	{	*this = obj;	}
Parser& Parser::operator=(const Parser &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

bool Parser::validDate(std::string date)
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	if (date[0] < '0' || date[0] > '9' || date[1] < '0' || date[1] > '9'
		|| date[2] < '0' || date[2] > '9' || date[3] < '0' || date[3] > '9'
		|| date[5] < '0' || date[5] > '9' || date[6] < '0' || date[6] > '9'
		|| date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9')
		return (false);

	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
	// 달력 단위 검사
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);

	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (month == 2) {
        if (isLeapYear && day > 29)
            return false;
        if (!isLeapYear && day > 28)
            return false;
    }

	return (true);
}

bool Parser::validValue(std::string value)
{
	int dot = 0;
	if (value.length() == 0)
		return (false);
	for (int i = 0; i < (int)value.length(); i++)
	{
		if (value[i] < '0' || value[i] > '9' || value[i] == '.')
		{
			if (value[i] == '.')
				dot++;
			if (dot > 1 || value[i] != '.')
				return (false);
		}
	}
	try {
        float number = Parser::stringToFloat(value);
        if (number > 0 && number <= 1000)
            return true;
        else
            return false;
    } catch (std::invalid_argument const &e) {
        return false;
    } catch (std::out_of_range const &e) {
        return false;
    } catch (std::exception const &e) {
		return false;
	}
	return (true);
}

void BitcoinDB::initDB()
{
    std::ifstream file("data.csv");
    std::string line;
	std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date, value;
        std::getline(iss, date, ',');
        std::getline(iss, value);
        if (Parser::validDate(date) && Parser::validValue(value))
		{
			try {
				_db[date] = Parser::stringToFloat(value);
			} catch (std::exception &e) {
				std::cout << "Error: invalid data" << std::endl;
			}
		} else if (Parser::validDate(date) == false) {
			std::cout << "Error: invalid date file format. Usage : XXXX-XX-XX" << std::endl;
			std::cout << "Error Date = " << date << std::endl;
			std::exit(1);
		}
    }
}

void Parser::parse(std::string file, BitcoinDB &db)
{
	std::ifstream _data(file);
	std::string line;

	std::getline(_data, line);
	if (line != "date | value")
	{
		std::cout << "Error: invalid file format" << std::endl;
		return ;
	}
	while (std::getline(_data, line))
	{
		std::string date = line.substr(0, line.find_first_of('|') - 1);
		std::string price = line.substr(line.find_first_of('|') + 2, line.length());
		if (validDate(date) && validValue(price))
		{
			try {
				db.show(date, Parser::stringToFloat(price));
			}
			catch (std::exception &e) {
				std::cout << "Error: invalid data" << std::endl;
			}
		}
		else
			std::cout << "Error: invalid data" << std::endl;
	}
	_data.close();
}

bool Parser::fileCheck(std::string file)
{
	std::ifstream _data(file);
	if (!_data.is_open())
	{
		std::cout << "Error: file not found" << std::endl;
		return (false);
	}
	_data.close();
	return (true);
}

float Parser::stringToFloat(std::string str) {
    std::istringstream iss(str);
    float value;
    if (!(iss >> value)) {
        throw std::exception();
    }
    return value;
}