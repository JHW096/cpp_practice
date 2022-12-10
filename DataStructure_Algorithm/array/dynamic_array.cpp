#include<iostream>
#include<sstream>
#include<algorithm>

template<typename T>
class dynamic_array
{
private:
	T* mp_data;
	size_t m_size;

public:
	dynamic_array(int size) 
	{
		m_size = size;
		mp_data = new T[m_size];
	}

	~dynamic_array()
	{
		delete[] mp_data;
	}

public:
	//복사 생성자
	dynamic_array(const dynamic_array<T>& other)
	{
		m_size = other.m_size;
		mp_data = new T[m_size];

		for (int i = 0; i < m_size; i++)
		{
			mp_data[i] = other[i];
		}
	}

public:

	T& operator[](int index)
	{
		return mp_data[index];
	}

	const T& operator[](int index) const
	{
		return mp_data[index];
	}

	T& at(int index)
	{
		if (index < m_size)
		{
			return mp_data[index];
		}
		throw "Index out of ragne";
	}

	size_t size() const
	{
		return m_size;
	}

	T* begin()
	{
		return mp_data;
	}

	const T* begin() const
	{
		return mp_data;
	}

	T* end()
	{
		return mp_data + m_size;
	}

	const T* end() const
	{
		return mp_data + m_size;
	}

};


int main(void)
{
	dynamic_array<int> arr(3);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;

	for (auto e : arr)
	{
		std::cout << e << std::endl;
	}

	std::cout << arr.at(2);
	
	dynamic_array<int> arr2(3);
	arr2 = arr;

	for (auto e : arr2)
	{
		std::cout << e << std::endl;
	}
	
}