#pragma once
#include"Graph.h"
#include<vector>
#include<queue>
#include<set>
#include<limits>

using namespace std;

template<typename T>
struct Label
{
	unsigned ID;
	T distance;

	inline bool operator < (const Label<T>& L) const
	{
		return this->distance < L.distance;
	}
	
	inline bool operator > (const Label<T>& L) const
	{
		return this->distance > L.distance;
	}
};

template<typename T>
auto Dijkstra(Graph<T> G, unsigned d_src, unsigned d_dst)
{
	priority_queue<Label<T>, vector<Label<T>>, greater<Label<T>>> heap;
	vector<unsigned> distance(G.getNumberOfEdges(), numeric_limits<T>::max());
	set<unsigned> visited;
	vector<unsigned> parent(G.getNumberOfEdges()); //���� ��Ʈ��ŷ�� ���� �ִܰ�� ã�� ����

	heap.emplace(Label<T>{d_src, 0});

	while (!heap.empty())
	{
		//auto = Label{ ID, distance }
		auto current = heap.top();
		heap.pop(); 

		//���� ������ ������ ���������̸� break;
		if (current.ID == d_dst) { break; }

		//���� ������ �湮 ��Ͽ� ���ٸ�
		if (visited.find(current.ID) == visited.end())
		{
			//���� ������ ������ ���� ��� ������ ����
			for (auto& e : G.getAdjEdges(current.ID))
			{
				auto neighbor = e.dst;
				auto new_distance = current.distance + e.weight;

				//���� �������� �������������� �Ÿ��� ���� ���� ���������� �Ÿ����� �۴ٸ�,
				if (new_distance < distance[neighbor])
				{
					//���������� �Ÿ��� �� ���� ���� ���ο� ��
					distance[neighbor] = new_distance;
					//���� ������ ����� ����(�θ�) �� ���� �ִ� ��
					parent[neighbor] = current.ID;
					//���� ������ ����� ����(neighbor) heap�� �ֱ�
					heap.emplace(Label<T>{ neighbor, new_distance });
				}

			}
			//�ش� ���ǵ��� �����ϸ� �湮 ��Ͽ� ���� �湮 ������ ����
			visited.emplace(current.ID);
		}
	}
	// ��Ʈ��ŷ���� shorest path���ϱ�
	
	//�ִ� ����� ������ ����(����)
	vector<unsigned> shorest_path;
	//������������ ���� ������ üũ�Ͽ� ����������� �ִ� ��θ� ã�� ����
	auto current_vertex = d_dst;

	//������� �������� �ݺ�
	while (current_vertex != d_src)
	{
		shorest_path.emplace_back(current_vertex);
		//d_dst�� ���� ������ ����� �ִܰŸ�(�θ�);
		current_vertex = parent[current_vertex];
	}
	//������� �������� �ݺ��������� ������� ����
	shorest_path.emplace_back(d_src);
	//�����������κ��� ��Ʈ��ŷ���� ã�Ƴ�������, ����� �� reverse
	reverse(shorest_path.begin(), shorest_path.end());

	//����� �ش� ����� ���Ͱ��� ��ȯ
	return shorest_path;
};