#pragma once
#include "pch.h"
/*
	Title : 잘라서 배열로 저장하기
	Level : 0
	Question :
	주어진 문자열을 주어진 숫자로 잘라 배열에 저장하기
*/

vector<string> solution(string my_str, int n)
{
	vector<string> answer;

	string str{ "" };
	for (int i = 0; i < my_str.size(); i++)
	{
		str += my_str[i];
		if (str.size() == n)
		{
			answer.push_back(str);
			str = "";
		}
	}
	
	if (str[0] != NULL)
	{
		answer.push_back(str);
	}

	return answer;
}

/*
	처음부터 substr을 쓸려했지만 남는 문자열까지 알아서 처리해줄지는 몰랐다.
*/
vector<string> OtherSolution(string my_str, int n)
{
	vector<string> answer;
	for (int i = 0; i < my_str.size(); i+=n)
	{
		answer.push_back(my_str.substr(i, n));
	}

}