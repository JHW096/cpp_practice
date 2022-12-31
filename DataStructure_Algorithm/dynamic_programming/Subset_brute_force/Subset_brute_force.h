#pragma once
#include<iostream>
#include<vector>
#include<algorithm>


#define DEBUG 1
//Debug�� true�� PRINT // Debug 0 ���x / Debug 1 ��� o
#if DEBUG
#define PRINT(x) cerr << x
#else
#define PRINT(x)
#endif

using namespace std;

//����Ʈ�������� �����غ���,
void GetAllSubsets(vector<int> set, vector<int> subset, int index,
	vector<vector<vector<int>>>& allSubset)
{
	//�ش� level�� �Ǹ� subset�� allsubjet�� �߰�
	if (index == set.size())
	{
		allSubset[subset.size()].push_back(subset);
		return;
	}
	
	//���� level���� set�� ���� �μ��� ����
	//���� GetAllSubset�� �������� �ʰ� ���� Level�� �̵�
	//���� GetAllSubset�� �ش� index�� ���տ� �߰��ϰ� ���� Level�� �̵�
	//���� �Լ� ȣ���� 2^n�� ��� �׸� ���ؼ� �����ϴ� ��������
	GetAllSubsets(set, subset, index + 1, allSubset);

	subset.push_back(set[index]);
	GetAllSubsets(set, subset, index + 1, allSubset);

}

//����Ȯ��(BruteForce)
bool SubsetSum_BruteForce(vector<int> set, int target)
{
	//�κ� ���� ��θ� �����ϴ� allSubsets
	vector<vector<vector<int>>> allSubsets(set.size() + 1);

	GetAllSubsets(set, { }, 0, allSubsets);

	for (int size = 0; size <= set.size(); size++)
	{
		PRINT("�κ� ������ ���� ����: " << size << endl);

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