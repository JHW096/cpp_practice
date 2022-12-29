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
	//min_heap, dec : 방문 지역중 최소값 찾기 위함
	priority_queue<Label<T>, vector<Label<T>>, greater<Label<T>>> heap;
	//최대 거리max로 설정
	vector<T> distance(G.getNumberOfEdges(), numeric_limits<T>::max());
	//방문 기록
	set<unsigned> visited;
	//최종 결과인 신장트리
	vector<unsigned> MST;

	//출발지
	heap.emplace(Label<T>{ p_src, 0 });

	while (!heap.empty())
	{
		auto current = heap.top();
		heap.pop();

		//현재 노드가 방문한 적이 없다면
		if (visited.find(current.ID) == visited.end())
		{
			//신장트리에 현재 노드 추가
			MST.emplace_back(current.ID);

			//현재 방문중인 노드와 연결된 노드들에 대해서
			for (auto& e : G.getAdjEdges(current.ID))
			{
				//현재 연결된 노드의 도착지
				auto neighbor = e.dst;
				//현재 노드와 연결된 노드까지의 거리
				auto new_distance = e.weight;

				//만약에 현재 노드와 연결된 노드의 길이 < 다음 노드의 거리
				if (new_distance < distance[neighbor])
				{
					//힙에 추가
					heap.emplace(Label<T>{ neighbor, new_distance});
					//다음 노드까지의 거리 = 현재 노드의 거리
					distance[neighbor] = new_distance;
				}
			}
			//방문 목록 추가
			visited.insert(current.ID);
		}
	}
	return MST;
}