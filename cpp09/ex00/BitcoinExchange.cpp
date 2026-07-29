#include "BitcoinExchange.hpp"

/* OCF */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->_database = other._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/* static fuctions */
static bool	isLeapYear(int year)
{
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

static bool	checkDataFormat(std::string& date)
{
	if(date.size() != 10)
		return (false);
	std::stringstream	ss(date);
	std::string			yStr, mStr, dStr;

	std::getline(ss, yStr, '-');
	std::getline(ss, mStr, '-');
	std::getline(ss, dStr);

	if (yStr.size() != 4 || mStr.size() != 2 || dStr.size() != 2)
		return (false);

	int	y,m,d;
	if(!stringToNumber<int>(yStr, y) || !stringToNumber<int>(mStr, m) || !stringToNumber<int>(dStr, d))
		return (false);
	if (y < 2009 || (m < 1 || m > 12))
		return (false);
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDays = days[m - 1];
	if (m == 2 && isLeapYear(y))
		maxDays = 29;

	return (d >= 1 && d <= maxDays);
}

/* members fuctions */
void	BitcoinExchange::loadDatabase()
{
	std::ifstream	file("data.csv");
	std::string		line;

	if (!file.is_open())
		throw (std::runtime_error("Error: could not open file"));

	bool	firstLine = true;
	while(std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string 		date;
		std::string 		valueStr;
		double				value;

		/* skipping first line */
		if (firstLine)
		{
			firstLine = false;
			if (!line.empty() && !isdigit(static_cast<unsigned char>(line[0])))
				continue;
		}
		if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
			continue;
		if (!checkDataFormat(date) || !stringToNumber<double>(valueStr, value))
			continue;

		_database.insert(std::make_pair(date, value));
	}
}

void	BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream	inFile(filename.c_str());
	std::string		line;

	if (!inFile.is_open())
		throw (std::runtime_error("Error: could not open file"));

	bool	firstLine = true;
	while (std::getline(inFile, line))
	{
		std::stringstream	ss(line);	
		std::string			date, valueStr;
		
		/* skipping first line */
		if (firstLine)
		{
			firstLine = false;
			if (!line.empty() && !isdigit(static_cast<unsigned char>(line[0])))
				continue;
		}
		if (!std::getline(ss, date, ' '))
			continue;
		if (!checkDataFormat(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		/* skipping "|" e ' ' */
		std::getline(ss, valueStr, ' ');
		std::getline(ss, valueStr);
		
		double	value;
		if (!stringToNumber<double>(valueStr, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
 			continue;
		}
		std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
		if (it == _database.begin() && it->first != date)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (it == _database.end() || it->first != date)
			--it;
		std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
	}
}
