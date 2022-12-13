#include<iostream>
#include<vector>

template<typename T>
std::vector<T> merge(std::vector<T>& arr1, std::vector<T>& arr2)
{
	std::vector<T> merged_arr;

	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end())
	{
		if (*iter1 < *iter2)
		{
			merged_arr.emplace_back(*iter1);
			iter1++;
		}
		else
		{
			merged_arr.emplace_back(*iter2);
			*iter2++;
		}
	}

	if (iter1 != arr1.end())
	{
		for (; iter1 != arr1.end(); iter1++)
		{
			merged_arr.emplace_back(*iter1);
		}
	}
	else
	{
		for (; iter2 != arr2.end(); iter2++)
		{
			merged_arr.emplace_back(*iter2);
		}
	}
	
	return merged_arr;

}

template<typename T>
std::vector<T> sort_merge(std::vector<T> arr)
{
	if (arr.size() > 1)
	{
		auto mid = arr.size() / 2;
		
		auto left_half = sort_merge<T>(std::vector<T>(arr.begin(), arr.begin() + mid));
		auto right_half = sort_merge<T>(std::vector<T>(arr.begin() + mid, arr.end()));

		return merge<T>(left_half, right_half);
	}

	return arr;
	
}



int main(void)
{
	std::vector<int> vec{ 2, 6, 7, 3, 1, 9, 5, 4, 8 };
	
	for (auto e : sort_merge(vec))
	{
		std::cout << e << " ";
	}

	
}