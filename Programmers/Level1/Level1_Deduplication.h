#pragma once
#include"pch.h"
/*
	Title : 같은 숫자는 싫어
	Level : 1
	Question : 12906
*/

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	answer.push_back(arr[0]);
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] != arr[i - 1])
		{
			answer.emplace_back(arr[i]);
		}
	}
	return answer;
}

//other solution
vector<int> OhterSolution(vector<int> arr)
{
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	return arr;
}