#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	Data*		original;
	Data*		restored;
	uintptr_t	raw;

	original = &data;
	raw = Serializer::serialize(original);
	restored = Serializer::deserialize(raw);

	if (original == restored)
		std::cout << "Equal\n";
	else
		std::cout << "Different\n";
	return (0);
}
