#pragma once
#include"Graph.h"
#include<set>
#include<vector>
#include<limits>
#include<queue>

using namespace std;

template<typename T> 
struct Label
{
	unsigned ID;
	T weight;

	inline bool operator > (const Label<T>& L) const
	{
		return this->weight > L.weight;
	}

	inline bool operator < (const Label<T>& L) const 
	{
		return this->weight < L.weight;
	}
};

template<typename T> 
auto prim_MST(const Graph<T> G, unsigned p_src)
{
	//min_heap, dec : �湮 ������ �ּҰ� ã�� ����
	priority_queue<Label<T>, vector<Label<T>>, greater<Label<T>>> heap;
	//�ִ� �Ÿ�max�� ����
	vector<T> distance(G.getNumberOfEdges(), numeric_limits<T>::max());
	//�湮 ���
	set<unsigned> visited;
	//���� ����� ����Ʈ��
	vector<unsigned> MST;

	//�����
	heap.emplace(Label<T>{ p_src, 0 });

	while (!heap.empty())
	{
		auto current = heap.top();
		heap.pop();

		//���� ��尡 �湮�� ���� ���ٸ�
		if (visited.find(current.ID) == visited.end())
		{
			//����Ʈ���� ���� ��� �߰�
			MST.emplace_back(current.ID);

			//���� �湮���� ���� ����� ���鿡 ���ؼ�
			for (auto& e : G.getAdjEdges(current.ID))
			{
				//���� ����� ����� ������
				auto neighbor = e.dst;
				//���� ���� ����� �������� �Ÿ�
				auto new_distance = e.weight;

				//���࿡ ���� ���� ����� ����� ���� < ���� ����� �Ÿ�
				if (new_distance < distance[neighbor])
				{
					//���� �߰�
					heap.emplace(Label<T>{ neighbor, new_distance});
					//���� �������� �Ÿ� = ���� ����� �Ÿ�
					distance[neighbor] = new_distance;
				}
			}
			//�湮 ��� �߰�
			visited.insert(current.ID);
		}
	}
	return MST;
}