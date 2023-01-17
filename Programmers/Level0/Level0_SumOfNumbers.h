#pragma once
#include "pch.h"

/*
	Title : ������ �� ����
	Level : 0
	Question :
	�������� Ȥ�� ������ common�� �Ű������� �־��� ��, ������ ���� �������� �� ���ڸ� return�Ͻÿ�.
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