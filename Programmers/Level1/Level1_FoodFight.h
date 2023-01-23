#pragma once
#include "pch.h"
/*
	Title : 푸드파이트 대회
	Level : 1
	Question : 134240
*/

string solution(vector<int> food)
{
	string answer{ "" };
	string str{ "" };
	for (size_t i = 1; i < food.size(); i++)
	{
		for (size_t j = 0; j < food[i] / 2; j++)
		{
			str += to_string(i);
		}
	}
	answer += str;
	answer += "0";
	reverse(str.begin(), str.end());
	answer += str;

	return answer;
}