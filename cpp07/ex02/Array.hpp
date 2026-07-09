#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		unsigned int	size() const;
		T&				operator[](unsigned int index);
		const T&		operator[](unsigned int index) const;

};

template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{}

/* “()” is used to define that primitive type values are initialized to zero, 
preventing them from being initialized with memory garbage. */
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n)
{}

/* deep copy constructor */
template <typename T>
Array<T>::Array(const Array<T>& other) : _data(new T[other._size]()), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

/* free old _data, alloc new array and deep copy */
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
		return (*this);
	delete[] _data;
	_size = other._size;
	_data = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (_data[index]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return (_data[index]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

#endif /* ARRAY_HPP */