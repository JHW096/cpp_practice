#include"BFS.h"
#include<map>

template<typename T>
auto BFS_test()
{
	Graph<T> G(9);

	std::map<unsigned, std::vector<std::pair<unsigned, T>>> edge_map;

	edge_map[1] = { { 2, 0}, { 5, 0} };
	edge_map[2] = { { 1, 0}, { 5, 0}, { 4, 0} };
	edge_map[3] = { { 4, 0}, { 7, 0} };
	edge_map[4] = { { 2, 0}, { 3, 0}, { 5, 0}, { 6, 0}, { 8, 0} };
	edge_map[5] = { { 1, 0}, { 2, 0}, { 4, 0}, { 8, 0} };
	edge_map[6] = { { 4, 0}, { 7, 0}, { 8, 0} };
	edge_map[7] = { { 3, 0}, { 6, 0} };
	edge_map[8] = { { 4, 0}, { 5, 0}, { 6, 0} };
	
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
	auto G = BFS_test<T>();
	std::cout << "Graph" << std::endl;
	std::cout << G << std::endl;

	std::cout << "BFS order" << std::endl;
	auto bfs = breadth_first_search(G, 1);
	for (auto v : bfs)
	{
		std::cout << static_cast<unsigned char>(v + 64) << " ";
	}
} 