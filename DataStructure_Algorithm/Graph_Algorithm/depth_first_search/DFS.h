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

		//���� ������ �湮��Ͽ� ���ٸ�
		if (visited.find(current) == visited.end()) 
		{
			//�ߺ��� ������ �ʴ� �湮��Ͽ� �߰�
			visited.insert(current);
			//���� �湮��� �ۼ�
			visited_order.emplace_back(current);

			//���� �������� �������� Ȯ��
			for (auto& e : G.getAdjEdges(current))
			{
				//���� �湮�� ������ �湮��Ͽ� ���ٸ�
				if (visited.find(e.dst) == visited.end())
				{
					//���ÿ� �߰�
					stack.push(e.dst);
				}
			}
			
		}
	}
	return visited_order;
}
