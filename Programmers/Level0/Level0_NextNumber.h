#pragma once
#include "pch.h"

/*
	Title : 연속된 수의 합
	Level : 0
	Question :
	두 정수 num과 total이 주어질 때, 연속된 수 num개를 더한 값이 total이 되는 배열 or 포인터를 오름차수로 만드시오.
*/

int solution(int common[], size_t common_len)
{
	//수열의 맨 끝
	int answer = common[common_len - 1]; 
	int gap;

	/*
		0, 1, 2를 이용한 등차 중앙을 이용
		TestCase { 1, 2, 4 } 의 경우는 int로 나눌때 등차로 인식될 수 있음으로
		등차 중앙의 값이 이상하지 않도록 조건 추가
	*/
	if ((common[0] + common[2]) % 2 == 0 && (common[0] + common[2]) / 2 == common[1])
	{
		gap = common[1] - common[0];
		answer += gap;
	}
	else
	{
		gap = common[1] / common[0];
		answer *= gap;
	}
	return answer;
}