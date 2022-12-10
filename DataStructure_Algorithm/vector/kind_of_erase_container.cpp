#include<iostream>
#include<vector>

std::vector<int> exErase1(std::vector<int>& vec, int&& n)
{
	/*
	* erase-remove 구문.
	* remove는 해당 원소를 삭제하고, 컨테이너의 가장 마지막 부분을 return
	* vec.erase(std::remove(vec.begin(), vec.end(), n), vec.end());
	*/
	auto itr = std::remove(vec.begin(), vec.end(), n);
	vec.erase(itr, vec.end());
	return vec;
}

std::vector<int> exErase2(std::vector<int>& vec, int&& n)
{
	/*
	* c++20에 추가된 std::erase_if 기존 erase-remove_if 구문을 쉽게 사용
	*/
	std::erase_if(vec, [&](auto m)->bool{ return n == m; });
	return vec;
}

int main(void)
{
	std::vector<int> vec{ 1, 2, 3, 4, 5 };
	for (const auto& e : exErase2(vec, 3))
	{
		std::cout << e << " ";
	}
}