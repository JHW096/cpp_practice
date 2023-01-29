#pragma once
#include "pch.h"
/*
	Title : ªÔ√—ªÁ
	Level : 1
	Question : 131705
*/

int solution(vector<int> number)
{
	int answer{ };

	for (int i = 0; i < number.size() - 2; i++)
	{
		for (int j = i + 1; j < number.size() - 1; j++)
		{
			for (int k = j + 1; k < number.size(); k++)
			{
				number[i] + number[j] + number[k] == 0 ? answer++ : answer = answer;
			}
		}
	}
	
	return answer;
}