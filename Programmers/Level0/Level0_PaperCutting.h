#pragma once
#include "pch.h"

/*
	Title : 종이자르기
	Level : 0
	Question :
	종이의 크기가 M * N 일때, 1 x 1크기로 자르려면 몇 번의 가위질이 필요한지 구하시오.
*/

int solution(int M, int N)
{
	return M * (N - 1) + (M - 1);
}

