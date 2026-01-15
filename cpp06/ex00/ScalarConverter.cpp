#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

static void	printChar(double value)
{
	if (std::isnan(value) || value < std::numeric_limits<char>::min() || 
		std::isinf(value) || value > std::numeric_limits<char>::max())
		std::cerr << "char:   impossible\n";
	else if (!std::isprint(static_cast<char>(value)))
		std::cerr << "char:   Non displayable\n";
	else
		std::cout << "char:  '" << static_cast<char>(value) << "'\n";
}

static void	printInt(double value)
{
	if (std::isnan(value) || value < std::numeric_limits<int>::min() || 
		std::isinf(value) || value > std::numeric_limits<int>::max())
		std::cerr << "int:    impossible\n";
	else
		std::cout << "int:    " << static_cast<int>(value) << "\n";
}

static void	printFloat(double value)
{
	if (std::isnan(value))
		std::cout << "float:  nanf\n";
	else if (std::isinf(value))
		std::cout << "float:  " << (value < 0 ? "-inff" : "+inff") << "\n";
	else if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cerr << "float:  impossible\n";
	else
		std::cout << "float:  " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
}

static void	printDouble(double value)
{
	if (std::isnan(value))
		std::cout << "double: " << "nan\n";
	else if (std::isinf(value))
		std::cout << "double: " << (value < 0 ? "-inf" : "+inf") << "\n";
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << "\n";
}

static bool	isValidLiteral(double *value, const std::string &literal)
{
	char	*end;

	*value = strtod(literal.c_str(), &end);
	if (end == literal.c_str())
		return (std::cerr << "Invalid literal!\n", false);
	if (*end != '\0')
	{
		if (*end == 'f' && *(end + 1) == '\0')
			return (true);
		else
			return (std::cerr << "Invalid literal!\n", false);			
	}
	return (true);
}

void	ScalarConverter::convert(const std::string &literal)
{
	double	value;

	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		value = static_cast<double>(literal[0]);
	else if (literal == "nan" || literal == "nanf")
		value = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "+inf" || literal == "+inff")
		value = std::numeric_limits<double>::infinity();
	else if (literal == "-inf" || literal == "-inff")
		value = -std::numeric_limits<double>::infinity();
	else if (!isValidLiteral(&value, literal))
		return ;
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
