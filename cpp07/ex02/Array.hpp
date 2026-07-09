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

		void			push_back(const T& value);
		void			pop_back();
		void			remove_at(unsigned int index);

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

/* extra fuctions */
/*
template <typename T>
void Array<T>::push_back(const T& value)
{
	T* newData = new T[_size + 1]();
	for (unsigned int i = 0; i < _size; i++)
		newData[i] = _data[i];
	newData[_size] = value;
	delete[] _data;
	_data = newData;
	_size += 1;
}

template <typename T>
void Array<T>::pop_back()
{
	if (_size == 0)
		throw std::exception();
	T* newData = new T[_size - 1]();
	for (unsigned int i = 0; i < _size - 1; i++)
		newData[i] = _data[i];
	delete[] _data;
	_data = newData;
	_size -= 1;
}

template <typename T>
void Array<T>::remove_at(unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	T* newData = new T[_size - 1]();
	for (unsigned int i = 0; i < index; i++)
		newData[i] = _data[i];
	for (unsigned int i = index; i < _size - 1; i++)
		newData[i] = _data[i + 1];
	delete[] _data;
	_data = newData;
	_size -= 1;
}
*/

#endif /* ARRAY_HPP */