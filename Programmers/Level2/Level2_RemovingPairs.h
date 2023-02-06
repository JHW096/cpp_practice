#pragma once
#include"pch.h"
/*
	Title : 짝지어 제거하기
	Level : 2
	Question : 12973
*/

int solution(string s)
{
	stack<char> stack;
	for (const auto& c : s)
	{
		if (!stack.empty())
		{
			if (!stack.empty())
			{
				stack.top() == c ? stack.pop() : stack.push(c);
			}
		}
		else
		{
			stack.push(c);
		}
	}

	return stack.empty() ? 1 : 0;
}