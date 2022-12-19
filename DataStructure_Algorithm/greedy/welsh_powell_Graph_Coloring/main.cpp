#include"welsh_powell.h"
#include<map>

int main(void)
{
	using T = unsigned;

	Graph<T> G(8);

	std::map<unsigned char, std::vector<std::pair<unsigned char, T>>> edge_map;
	edge_map['A'] = { {'B', 0}, {'E', 0} };
	edge_map['B'] = { {'A', 0}, {'D', 0}, {'E', 0} };
	edge_map['C'] = { {'D', 0}, {'G', 0} };
	edge_map['D'] = { {'B', 0}, {'C', 0}, {'E', 0}, {'F', 0}, {'H', 0} };
	edge_map['E'] = { {'A', 0}, {'B', 0}, {'D', 0}, {'H', 0} };
	edge_map['F'] = { {'D', 0}, {'G', 0}, {'H', 0} };
	edge_map['G'] = { {'C', 0}, {'F', 0} };
	edge_map['H'] = { {'D', 0}, {'E', 0}, {'F', 0} };

	for (auto& i : edge_map)
	{
		for (auto& j : i.second)
		{
			G.add_edge(Edge<T>{i.first, j.first, j.second});
		}
	}

	std::cout << "insert Graph" << std::endl;
	std::cout << G << std::endl;

	auto colors = welshPowellColoring<T>(G);
	std::cout << std::endl << "Graph Coloring" << std::endl;
	print_colors(colors);
}