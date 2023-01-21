#pragma once
#include "pch.h"
/*
	Title : 7의 개수
	Level : 0
	Question :
	매개변수로 주어진 Vector<int> 에서 7의 개수 구하기
*/

//배열의 숫자를 String으로 바꾸어 합친후, string의 개별 char에 대해 '7' 갯수를 검사.
int solution(vector<int> array)
{
	int answer{ };

	string str{ "" };

	for (auto e : array)
	{
		str += to_string(e);
	}

	for (auto e : str)
	{
		if (e == '7')
		{
			answer++;
		}
	}

	return answer;
}
