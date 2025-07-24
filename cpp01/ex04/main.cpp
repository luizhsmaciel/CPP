#include <iostream>
#include <fstream>
#include <string>

std::string	trim(const std::string &str)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = str.length();
	while (start < end && isspace(str[start]))
		start++;
	while(end > start && isspace(str[end - 1]))
		end--;
	return (str.substr(start, end - start));
}

std::string	ReplaceInLine(const std::string &line, const std::string &s1, const std::string &s2)
{
	std::string	newLine;
	size_t		start;
	size_t		found;

	start = 0;
	newLine = "";
	while ((found = line.find(s1, start)) != std::string::npos)
	{
		newLine += line.substr(start, found - start);
		newLine += s2;
		start = found + s1.length();
	}
	newLine += line.substr(start);
	return (newLine);
}

int	main(int ac, char **av)
{
	std::string line;
	std::string filename;
	std::string	outputFilename;

	if (ac != 4)
		return (std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl, 1);
	if (std::string(av[2]).empty())
		return (std::cerr << "Error: s1 cannot be empty!" << std::endl, 1);
	filename = trim(av[1]);
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
		return (std::cerr << "Error opening file!" << std::endl, 1);
	outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile)
	{
		inputFile.close();
		return (std::cerr << "Error creating output file!" << std::endl, 1);
	}
	while (!inputFile.eof())
	{
		std::getline(inputFile, line);
		std::string newLine = ReplaceInLine(line, av[2], av[3]);
		if (!inputFile.eof())
			outputFile << newLine << '\n';
		else
			outputFile << newLine;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}
