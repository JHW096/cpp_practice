#pragma once
#include"pch.h"
/*
	Title : 올바른 괄호
	Level : 2
	Question : 12941
*/

bool solution(string s)
{
	stack<char> stack;
	stack.push(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			stack.push(s[i]);
		}
		if (!stack.empty())
		{
			if (stack.top() == '(' && s[i] == ')')
			{
				stack.pop();
			}
		}
	}
	
	return stack.empty() ? true : false;
}