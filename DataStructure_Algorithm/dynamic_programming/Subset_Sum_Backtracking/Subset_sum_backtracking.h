#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool SubsetSum_Backtracking(vector<int> set, int sum, int i)
{
	//Target이 Sum과 같으면 true return
	if (sum == 0)
	{
		return true;
	}

	//i(vector의 순번)이 vector의 크기를 넘어가거나, Sum이 target보다 크다면 false
	if (i == set.size() || set[i] > sum)
	{
		return false;
	}

	//다음 순번은 Sum에서 해당 인자를 뺀 Sum 값 || 해당 다음 인자
	return SubsetSum_Backtracking(set, sum - set[i], i + 1) ||
		SubsetSum_Backtracking(set, sum, i + 1);
}
/*
										fn(58, 0) : F
								fn(45, 1) : F || fn(58, 1) : F
				fn(16, 2) : F || fn(45, 2) : F	//	fn(29, 2) : F || fn(58, 2) : F
	fn(-, 3) : F || fn(16, 3) : F // fn(0, 3) : T || fn(45, 3) : F
												.
												.
												.
										다시 올라오면 True
*/

void TEST()
{
	vector<int> vec{ 13, 29, 45, 79 };
	int target{ 58 };
	bool found = SubsetSum_Backtracking(vec, target, 0);

	if (found)
	{
		cout << "found" << endl;
	}
	else
	{
		cout << "unFound" << endl;
	}
}