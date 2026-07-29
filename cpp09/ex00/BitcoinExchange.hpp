#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_database;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void	loadDatabase();
		void	processInputFile(const std::string& filename);

};

template <typename T>
bool	stringToNumber(const std::string& s, T& value)
{
	std::stringstream ss (s);
	ss >> value;
	return (!ss.fail() && ss.eof());
}

#endif /* BITCOINEXCHANGE_HPP */