#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
public:
	Array() : _array(new T()), _n(0)
	{};
	
	Array(unsigned int n) : _array(new T[n]()), _n(n)
	{};

	Array(const Array& arg) : _n(arg._n)
	{
		int idx;
		T* ret = new T();

		idx = 0;
		while (idx < arg._n)
		{
			ret->_array[idx] = arg._array[idx];
			idx++;
		}
		this->_array = ret;
	};

	Array& operator=(const Array& arg)
	{
		int idx;

		idx = 0;
		this->_n = arg._n;
		while (idx < this->_n)
		{
			this->_array[idx] = arg._array[idx];
			idx++;
		}
		return (*this);
	};

	~Array()
	{
		delete [] this->_array;
	}

	const unsigned int size(void)
	{
		return (this->_n);
	};

private:
	T* _array;
	int _n;
};

#endif