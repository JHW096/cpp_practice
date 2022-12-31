#pragma once
#include<iostream>
#include<vector>
#include<algorithm>


#define DEBUG 1
//Debug가 true면 PRINT // Debug 0 출력x / Debug 1 출력 o
#if DEBUG
#define PRINT(x) cerr << x
#else
#define PRINT(x)
#endif

using namespace std;

//이진트리식으로 생각해보면,
void GetAllSubsets(vector<int> set, vector<int> subset, int index,
	vector<vector<vector<int>>>& allSubset)
{
	//해당 level이 되면 subset을 allsubjet에 추가
	if (index == set.size())
	{
		allSubset[subset.size()].push_back(subset);
		return;
	}
	
	//다음 level에서 set의 다음 인수를 조사
	//좌측 GetAllSubset은 조사하지 않고 다음 Level로 이동
	//우측 GetAllSubset은 해당 index를 집합에 추가하고 다음 Level로 이동
	//따라서 함수 호출은 2^n승 모든 항목에 대해서 조사하는 전수조사
	GetAllSubsets(set, subset, index + 1, allSubset);

	subset.push_back(set[index]);
	GetAllSubsets(set, subset, index + 1, allSubset);

}

//전수확인(BruteForce)
bool SubsetSum_BruteForce(vector<int> set, int target)
{
	//부분 집합 모두를 저장하는 allSubsets
	vector<vector<vector<int>>> allSubsets(set.size() + 1);

	GetAllSubsets(set, { }, 0, allSubsets);

	for (int size = 0; size <= set.size(); size++)
	{
		PRINT("부분 집합의 원소 개수: " << size << endl);

		for (auto subset : allSubsets[size])
		{
			PRINT("\t{ ");

			int sum = 0;
			for (auto number : subset)
			{
				sum += number;
				PRINT(number << " ");
			}
			PRINT("} = " << sum << endl);

			if (sum == target)
			{
				return true;
			}
		}
		
	}
	return false;
}