#include"DisjointSet.h"
#include"Kruskal.h"
#include<map>

int main(void)
{
	using T = unsigned;

	Graph<T> G(9);

	std::map<unsigned char, std::vector<std::pair<unsigned char, T>>> edge_map;

	edge_map['A'] = {{'B', 2}, {'F', 3}};
	edge_map['B'] = {{'A', 2}, {'F', 5}, {'D', 1}};
	edge_map['C'] = {{'D', 2}, {'G', 3}};
	edge_map['D'] = {{'B', 1}, {'C', 2}, {'E', 2}, {'F', 4}, {'H', 5}};
	edge_map['E'] = {{'A', 3}, {'B', 5}, {'D', 2}, {'H', 3}};
	edge_map['F'] = {{'D', 4}, {'G', 4}, {'H', 1}};
	edge_map['G'] = {{'C', 3}, {'F', 4}};
	edge_map['H'] = {{'D', 5}, {'E', 3}, {'F', 1}};

	for (auto& i : edge_map)
	{
		for (auto& j : i.second)
		{
			G.add_edge(Edge<T>{i.first, j.first, j.second});
		}
	}

	std::cout << "insert Graph : " << std::endl;
	std::cout << G << std::endl;

	Graph<T> G2 = kruskal(G);
	std::cout << "result Graph : " << std::endl;
	std::cout << G2 << std::endl;
}

