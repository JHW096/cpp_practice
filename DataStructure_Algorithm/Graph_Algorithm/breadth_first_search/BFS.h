#pragma once
#include"Graph.h"
#include<set>
#include<queue>

template<typename T>
auto breadth_first_search(const Graph<T>& G, unsigned start)
{
	std::queue<unsigned> queue;
	std::set<unsigned> visited; //���� �湮���� ��� �ߺ�x
	std::vector<unsigned> visited_order; //�湮 ���� ���
	
	queue.push(start);

	while (!queue.empty())
	{
		auto current = queue.front();
		queue.pop();
		
		//���� ������� ���� �湮 ��Ͽ� ���ٸ�
		if (visited.find(current) == visited.end())
		{
			//���� �湮 ������ Edge�� Destination�� �߰�
			visited.insert(current);
			//�湮 ������ ���� ������� ���
			visited_order.push_back(current);

			//Destination�� �湮 ��Ͽ� ���ٸ� Queue�� �߰�.
			for (auto& e : G.getAdjEdges(current))
			{
				if (visited.find(e.dst) == visited.end())
				{
					queue.push(e.dst);
				}
				
			}
		}
	}
	return visited_order;
}