#pragma once
#include"Graph.h"
#include<set>
#include<queue>

template<typename T>
auto breadth_first_search(const Graph<T>& G, unsigned start)
{
	std::queue<unsigned> queue;
	std::set<unsigned> visited; //다음 방문순서 목록 중복x
	std::vector<unsigned> visited_order; //방문 순서 목록
	
	queue.push(start);

	while (!queue.empty())
	{
		auto current = queue.front();
		queue.pop();
		
		//만약 출발지가 다음 방문 목록에 없다면
		if (visited.find(current) == visited.end())
		{
			//다음 방문 순서에 Edge의 Destination를 추가
			visited.insert(current);
			//방문 순서로 현재 출발지점 등록
			visited_order.push_back(current);

			//Destination이 방문 목록에 없다면 Queue에 추가.
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