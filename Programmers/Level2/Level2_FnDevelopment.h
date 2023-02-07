#pragma once
#include"pch.h"
/*
	Title : 기능 개발
	Level : 2
	Question : 42586
*/

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;

	queue<int> queue;
	for (size_t i = 0; i < progresses.size(); i++)
	{
		int date{ 0 };
		while (progresses[i] < 100)
		{
			progresses[i] += speeds[i];
			date++;
		}
		queue.push(date);
		date = 0;
	}
	
	int front = queue.front();
	int count{ 0 };
	while (!queue.empty())
	{
		if (front >= queue.front())
		{
			queue.pop();
			count++;
		}
		else
		{
			answer.push_back(count);
			front = queue.front();
			count = 0;
		}
	}
	answer.push_back(count);

	return answer;
}