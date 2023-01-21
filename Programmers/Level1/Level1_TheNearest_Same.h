#pragma once
#include "pch.h"

/*
	Title : 크기가 작은 부분 문자열
	Level : 1
	Question : 142086
*/

vector<int> solution(string s)
{
	vector<int> answer(s.size(), -1);
	for (int i = 1; i < s.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (s[i] == s[j])
			{
				answer[i] = i - j;
				break;
			}
		}
	}
	return answer;
}
