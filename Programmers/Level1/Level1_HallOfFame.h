#pragma once
#include "pch.h"
/*
	Title : 명예의 전당(1)
	Level : 1
	Question : 138477
*/

vector<int> solution(int k, vector<int> score)
{
	vector<int> answer;
	vector<int> vec;
	for (size_t i = 0; i < score.size(); i++)
	{
		vec.emplace_back(score[i]);
		sort(vec.begin(), vec.end());

		i < k ?
			answer.emplace_back(*min_element(vec.begin(), vec.end())) :
			answer.emplace_back(vec[vec.size() - k]);
	}
	return answer;
}