#pragma once
#include "pch.h"
/*
	Title : 크기가 작은 부분 문자열
	Level : 1
	Question :
	복잡함으로 문제 번호 147355 확인
*/

int solution(string t, string p)
{
	int answer{ };
	for (int i = 0; i <= t.size() - p.size(); i++)
	{
		t.substr(i, p.size()) <= p ? answer++ : answer;
	}
	return answer;
}