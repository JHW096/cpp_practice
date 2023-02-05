#pragma once
#include"pch.h"
/*
	Title : ÃÖ´ñ°ª°ú ÃÖ¼Ú°ª
	Level : 2
	Question : 154538
*/

string solution(string s)
{
	string answer{ "" };
	vector<int> vec;
	std::string temp{ "" };
	
	for (auto e : s)
	{
		if (e != ' ')
		{
			temp.push_back(e);
		}
		else
		{
			vec.push_back(stoi(temp));
			temp.clear();
		}
	}
	vec.push_back(stoi(temp));
	answer += to_string(*min_element(vec.begin(), vec.end()));
	answer += ' ';
	answer += to_string(*max_element(vec.begin(), vec.end()));

	return answer;
}
