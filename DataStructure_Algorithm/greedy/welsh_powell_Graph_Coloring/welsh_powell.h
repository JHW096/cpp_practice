#pragma once
#include"Graph.h"
#include<set>
#include<algorithm>
#include<unordered_map>

std::unordered_map<unsigned, std::string> color_map{
	{1, "Red"}, { 2, "Blue"}, {3, "Green"},
	{4, "Yellow"}, {5, "Black"}, {6, "White"}
};

template<typename T>
auto welshPowellColoring(const Graph<T>& G)
{
	auto size = G.getVertices(); //Graph.Size

	std::vector<std::pair<unsigned char, size_t>> degrees; //Pair<Edge, degree>

	for (unsigned char i = 'A'; i < 'A' + size; i++)
	{
		degrees.push_back(std::make_pair(i, G.getFromEdge(i).size()));
	}

	std::sort(degrees.begin(), degrees.end(), [](const auto& a, const auto& b)
	{
		return a.second > b.second;
	}); //내림차순 of size_t

	std::cout << std::endl;
	for (auto const i : degrees)
	{
		std::cout << "" << i.first << " (" << i.second << ")" << std::endl;
	}

	std::vector<unsigned> assigned_colors(size);
	auto color_count = 1;

	//algorithm start
	while (true)
	{
		for (auto const d : degrees)
		{
			if (assigned_colors[static_cast<unsigned>(d.first - 65)] != 0)
			{
				continue;
			}

			auto edges_from_d = G.getFromEdge(d.first);
			std::set<unsigned> neighbors;

			for (auto& e : edges_from_d)
			{
				neighbors.insert(assigned_colors[static_cast<unsigned>(e.dst - 65)]);
			}
			
			if (neighbors.find(color_count) == neighbors.end())
			{
				assigned_colors[static_cast<unsigned>(d.first - 65)] = color_count;
			}
		}
		color_count++;

		if (std::find(assigned_colors.begin() + 1, assigned_colors.end(), 0) ==
			assigned_colors.end())
		{
			break;
		}
	}
	
	return assigned_colors;

}

template <typename T>
void print_colors(std::vector<T>& colors)
{
	for (auto i = 'A'; i < 'A' + colors.size(); i++)
	{
		std::cout << i << ": " << color_map[colors[i - 'A']] << std::endl;
	}
}