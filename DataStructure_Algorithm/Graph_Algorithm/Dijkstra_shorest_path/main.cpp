#include"BFS.h"
#include"DFS.h"
#include"Dijkstra.h"
#include<map>

template<typename T>
auto graph_test()
{
	Graph<T> G(9);

	std::map<unsigned, std::vector<std::pair<unsigned, T>>> edge_map;

	edge_map[1] = { { 2, 2}, { 5, 3} };
	edge_map[2] = { { 1, 2}, { 5, 5}, { 4, 1} };
	edge_map[3] = { { 4, 2}, { 7, 3} };
	edge_map[4] = { { 2, 1}, { 3, 2}, { 5, 2}, { 6, 4}, { 8, 5} };
	edge_map[5] = { { 1, 3}, { 2, 5}, { 4, 2}, { 8, 3} };
	edge_map[6] = { { 4, 4}, { 7, 4}, { 8, 1} };
	edge_map[7] = { { 3, 3}, { 6, 4} };
	edge_map[8] = { { 4, 5}, { 5, 3}, { 6, 1} };
	
	for (auto& i : edge_map)
	{
		for (auto& j : i.second)
		{
			G.add_edge(Edge<T>{i.first, j.first, j.second});
		}
	}
	return G;
}

int main(void)
{
	using T = unsigned;
	auto G = graph_test<T>();
	std::cout << "Graph" << std::endl;
	std::cout << G << std::endl;

	
	std::cout << "Shorest_path" << std::endl;
	for (auto& e : Dijkstra(G, 1, 8))
	{
		std::cout << static_cast<unsigned char>(e + 64) << " ";
	}
} 