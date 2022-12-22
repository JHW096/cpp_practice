#pragma once
#include"Graph.h"
#include<set>
#include<stack>

using namespace std;

template<typename T>
auto Depth_first_search(const Graph<T>& G, unsigned start)
{
	stack<unsigned> stack;
	set<unsigned> visited;
	vector<unsigned> visited_order;
	
	stack.push(start);

	while (!stack.empty())
	{
		auto current = stack.top();
		stack.pop();

		//현재 엣지가 방문기록에 없다면
		if (visited.find(current) == visited.end()) 
		{
			//중복이 허용되지 않는 방문기록에 추가
			visited.insert(current);
			//최종 방문목록 작성
			visited_order.emplace_back(current);

			//다음 도착지의 엣지들을 확인
			for (auto& e : G.getAdjEdges(current))
			{
				//다음 방문할 엣지가 방문기록에 없다면
				if (visited.find(e.dst) == visited.end())
				{
					//스택에 추가
					stack.push(e.dst);
				}
			}
			
		}
	}
	return visited_order;
}
