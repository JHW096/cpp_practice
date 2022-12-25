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
	vector<unsigned> parent(G.getNumberOfEdges()); //향후 백트랙킹을 통해 최단경로 찾기 위함

	heap.emplace(Label<T>{d_src, 0});

	while (!heap.empty())
	{
		//auto = Label{ ID, distance }
		auto current = heap.top();
		heap.pop(); 

		//현재 도착한 지점이 도착지점이면 break;
		if (current.ID == d_dst) { break; }

		//현재 지점이 방문 기록에 없다면
		if (visited.find(current.ID) == visited.end())
		{
			//현재 도착한 지점에 대한 모든 정점에 대해
			for (auto& e : G.getAdjEdges(current.ID))
			{
				auto neighbor = e.dst;
				auto new_distance = current.distance + e.weight;

				//현재 지점부터 다음지점까지의 거리가 원래 다음 지점까지의 거리보다 작다면,
				if (new_distance < distance[neighbor])
				{
					//다음지점의 거리는 더 작은 수인 새로운 값
					distance[neighbor] = new_distance;
					//다음 지점의 연결된 지점(부모) 는 현재 있는 값
					parent[neighbor] = current.ID;
					//다음 힙에서 출발할 지역(neighbor) heap에 넣기
					heap.emplace(Label<T>{ neighbor, new_distance });
				}

			}
			//해당 조건들을 만족하면 방문 목록에 현재 방문 지역을 저장
			visited.emplace(current.ID);
		}
	}
	// 백트래킹으로 shorest path구하기
	
	//최단 기록을 저장할 벡터(집합)
	vector<unsigned> shorest_path;
	//도작지점으로 부터 역으로 체크하여 출발지점까지 최단 경로를 찾기 위함
	auto current_vertex = d_dst;

	//출발지점 직전까지 반복
	while (current_vertex != d_src)
	{
		shorest_path.emplace_back(current_vertex);
		//d_dst의 다음 지점은 저장된 최단거리(부모);
		current_vertex = parent[current_vertex];
	}
	//출발지점 직전까지 반복했음으로 출발지점 저장
	shorest_path.emplace_back(d_src);
	//도착지점으로부터 백트랙킹으로 찾아냈음으로, 저장된 값 reverse
	reverse(shorest_path.begin(), shorest_path.end());

	//저장된 해당 경로의 벡터값을 반환
	return shorest_path;
};