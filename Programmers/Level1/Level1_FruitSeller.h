#pragma once
#include "pch.h"
/*
	Title : 과일장수
	Level : 1
	Question : 135808
*/

int solution(int k, int m, vector<int> score)
{
	int answer{ };
	sort(score.begin(), score.end(), greater<int>());
	vector<int> arr;
	for (size_t i = 0; i < score.size(); i++)
	{
		arr.emplace_back(score[i]);
		if (arr.size() == m)
		{
			answer += arr[m - 1] * m;
			arr = { };
		}
	}
	return answer;
}

/*
	4 1 2 2 4 4 4 4 1 2 4 2
	sort = 4 4 4 4 4 4 2 2 2 2 1 1 

	arr{ 444 } 12
	
	
*/