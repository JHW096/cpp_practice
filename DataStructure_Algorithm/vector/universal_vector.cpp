#include<iostream>
#include<vector>
#include<type_traits>

template<typename ... Args> 
//...Parameters : 여러 인자를 받음
auto build_vector(const Args&&... args)
//&& : R-value reference parameter 
-> std::vector<typename std::common_type<Args...>::type>
//trailing return type(후행 리턴 타입) 
{
	using commonType = typename std::common_type<Args...>::type;
	return { std::move<commonType>((Args&&)args)... };
	//parameter(l-value)인 args를 r-value로 캐스팅하여 return
}


int main(void)
{
	auto data = build_vector(1, 'a', 3.2f, false);
	//auto의 타입은 build_vector의 후행리턴 값인 std::vector<common_type>
	//모두 float으로 변환이 가능하여 common_type = float
	for (auto e : data)
	{
		std::cout << e << " ";
	}
	
}

