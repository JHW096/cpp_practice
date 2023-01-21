#pragma once
#include "pch.h"
/*
	Title : 문자열 정렬하기
	Level : 0
	Question :
	매개변수로 주어진 string을 소문자로 변환하고 알파벳 순으로 정렬하시오.
*/

string solution(string my_string)
{
	string answer{ "" };

	for (auto& ch : my_string)
	{
		ch = tolower(ch);
	}

	sort(my_string.begin(), my_string.end(), less<char>());

	answer = my_string;

	return answer;
}