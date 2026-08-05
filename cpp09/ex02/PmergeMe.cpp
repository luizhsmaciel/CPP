#include "PmergeMe.hpp"

/* OCF */
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _lis(other._lis) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_lis = other._lis;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

/* static functions */
static bool	stringToInt(const std::string& s, int& value)
{
	std::stringstream ss(s);
	ss >> value;
	return (!ss.fail() && ss.eof());
}

static void	printVector(std::vector<int>& vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/* members functions */
/* ./PmergeMe 3 5 9 7 4 */
void	PmergeMe::parserInput(char** av)
{
	for (int i = 1; av[i]; ++i)
	{
		int	value;
		if (!stringToInt(av[i], value) || value < 0)
			throw (std::runtime_error("Error: invalid input"));
		_vec.push_back(value);
		_lis.push_back(value);
	}
}

void	PmergeMe::fordJohnsonSortVector(std::vector<int>& vector)
{
	if (vector.size() <= 1)
		return ;
	
	/* vector.size() == impar */
	bool	hasUnpaired = (vector.size() % 2 != 0);
	int		unpaired = 0;
	if (hasUnpaired)
	{
		unpaired = vector.back();
		vector.pop_back();
	}
	/* fazendo os pares */
	std::vector< std::pair<int, int> > pairs;
	for (size_t i = 0; i < vector.size(); i+=2)
	{
		if (vector[i] > vector[i + 1])
			pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
		else
			pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
	}
	/* vector com os maiores */
	std::vector<int> larger;
	for (size_t i = 0; i < pairs.size(); ++i)
		larger.push_back(pairs[i].first);
	//printVector(larger);
	
	/* recursao parar ordenar os maiores e ja inserir */
	fordJohnsonSortVector(larger);

	std::vector<int> result;
	std::vector<int> smaller;
	std::vector<bool> used(pairs.size(), false);

	for (size_t i = 0; i < larger.size(); ++i) /* percorre o vector larger */
	{
		result.push_back(larger[i]); /* adiciona o maior de cada pair por chamada recursiva */
		for (size_t j = 0; j < pairs.size(); ++j) /* percorre todos os pares */
		{
			if (!used[j] && pairs[j].first == larger[i]) /* se encontrei o maior do par... */
			{
				smaller.push_back(pairs[j].second); /* adicionar o menor no smaller */
				used[j] = true; /* marcar como usado, pois ja adicionei o maior e o menor */
				break;
			}
		}
	}
	/* inserir o primeiro menor da lista por padrao */
	result.insert(result.begin(), smaller[0]);

	/* inserir os menores, pulando o primeiro  */
	for (size_t i = 1; i < smaller.size(); ++i)
	{
		std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), smaller[i]);
		result.insert(pos, smaller[i]);
	}
	/* adicionar o que ficou sem par */
	if (hasUnpaired)
	{
		std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), unpaired);
		result.insert(pos, unpaired);
	}
	vector = result;
}

void	PmergeMe::sort()
{
	std::cout << "Before: ";
	printVector(_vec);

	std::clock_t startVector = std::clock();
	fordJohnsonSortVector(_vec);
	std::clock_t endVector = std::clock();
	double	timeVector = static_cast<double>(endVector - startVector) * 1000000.0 / CLOCKS_PER_SEC;

	//std::clock_t startList = std::clock();
	// fordJohnsonSortList();
	//std::clock_t endList = std::clock();
	//double	timeList = static_cast<double>(endList - startList) * 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "After:  ";
	printVector(_vec);

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << timeVector << " μs" << std::endl;
	//std::cout << "Time to process a range of " << _lis.size() << " elements with std::list   : " << timeList << " μs" << std::endl;
}

void	PmergeMe::run(char** av)
{
	for (size_t i = 0; i < 50; i++)
	{
		_vec.clear();
		parserInput(av);
		sort();
	}
}
