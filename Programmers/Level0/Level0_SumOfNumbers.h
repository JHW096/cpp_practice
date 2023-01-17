#pragma once
#include "pch.h"

/*
	Title : 다음에 올 숫자
	Level : 0
	Question :
	등차수열 혹은 등비수열 common이 매개변수로 주어질 때, 마지막 원소 다음으로 올 숫자를 return하시오.
*/

int* solution(int num, int total)
{
	int* answer = (int*)malloc(sizeof(int) * num);
	int mid = total / num;

	for (int i = 0; i < num; i++)
	{
		answer[i] = num % 2 == 0 ? mid - (num / 2) + 1 + i : mid - (num / 2) + i;
	}
	return answer;
}



//---------------TEST----------------------//
size_t GetSolutionLength(int* sol, int num)
{
	return sizeof(sol) / sizeof(sol) * num;
}

void TEST_PRINT(int* sol)
{
	size_t len = GetSolutionLength(sol, 4);

	for (auto i = 0; i < len; i++)
	{
		cout << sol[i] << " ";
	}
}