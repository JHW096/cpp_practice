#pragma once
#include"DisjointSet.h"
#include"Graph.h"
#include<queue>
#include<vector>

template<typename T>
Graph<T> kruskal(const Graph<T>& G)
{
	std::priority_queue<Edge<T>, std::vector<Edge<T>>, std::greater<Edge<T>>> min_heap;

	for (auto e : G.get_edge_list())
	{
		min_heap.push(e);
	}

	auto N = G.get_vertices();
	DisjointSet disjointset(N);

	for (unsigned char i = 'A'; i < 'A' + N; i++)
	{
		disjointset.make_set(i);
	}

	Graph<T> graph(N);

	while (!min_heap.empty())
	{
		auto e = min_heap.top();
		min_heap.pop();

		if (disjointset.find_node_parent(e.source) != disjointset.find_node_parent(e.destination))
		{
			graph.add_edge(Edge<T>{e.source, e.destination, e.weight});
			disjointset.union_find(e.source, e.destination);
		}
	}
	return graph;

}