#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int UNKNOWN = -1;
const int FOUNDMAX = 1000;

bool SubsetSum_Memoization(vector<int>& set, int sum, int i, vector<vector<int>>& memo)
{
	//�� Ʈ��ŷ ������� ���ҵ��� ���� �ϳ� �� ���鼭 0�� �Ǹ� true
	if (sum == 0)
	{
		return true;
	}

	//�ݺ� Ƚ���� ������ ���� �Ѿ�ų�, ���� ���Ҹ� �� �� �� �հ��� ���� �� �۴ٸ� false
	if (i == set.size() || set[i] > sum)
	{
		return false;
	}

	//cache���� ���ŵ��� �ʾҴٸ�,
	if (memo[i][sum] == UNKNOWN)
	{
		//�ش� ���Ҹ� sum���� ���� 
		bool append = SubsetSum_Memoization(set, sum - set[i], i + 1, memo);
		//�ش� ���� ����
		bool ignore = SubsetSum_Memoization(set, sum, i + 1, memo);

		
		memo[i][sum] = append || ignore;
	}
	
	return memo[i][sum];
}
/*
									Fn(58, 0)
	          Fn(45, 1)									 Fn(58, 0)
	Fn(29, 2)			Fn(45, 1)			   Fn(29, 1)           Fn(58, 1)
	False, False       True, False 			True, Fn(29, 2) // Fn(13, 2) Fn(58, 2)

*/

void TEST()
{
	vector<int> set{ 13, 29, 45, 79 };
	int sum = 58;
	vector<vector<int>> memo(set.size(), vector<int>(FOUNDMAX, UNKNOWN));

	bool found = SubsetSum_Memoization(set, sum, 0, memo);

	if (found)
	{
		cout << "Found! : " << sum << endl;
	}
	else
	{
		cout << "unFound" << endl;
	}
	
}