#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool SubsetSum_Backtracking(vector<int> set, int sum, int i)
{
	//Target�� Sum�� ������ true return
	if (sum == 0)
	{
		return true;
	}

	//i(vector�� ����)�� vector�� ũ�⸦ �Ѿ�ų�, Sum�� target���� ũ�ٸ� false
	if (i == set.size() || set[i] > sum)
	{
		return false;
	}

	//���� ������ Sum���� �ش� ���ڸ� �� Sum �� || �ش� ���� ����
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
										�ٽ� �ö���� True
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