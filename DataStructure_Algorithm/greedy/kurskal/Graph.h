#pragma once
#include<iostream>
#include<vector>
#include<ostream>

template<typename T>
struct Edge
{
	unsigned char source;
	unsigned char destination;
	T weight;

	bool operator < (const Edge<T>& e) const
	{
		return this->weight < e.weight;
	}

	bool operator > (const Edge<T>& e) const
	{
		return this->weight > e.weight;
	}
};

template<typename T>
class Graph
{
private:
	unsigned m_vertices;
	std::vector<Edge<T>> m_edge_list;

public:
	Graph(unsigned N) : m_vertices{ N } { }

	auto get_vertices() const
	{
		return m_vertices;
	}

	auto get_edge_list() const
	{
		return m_edge_list;
	}
		
	auto get_edge_from(unsigned char v) const
	{
		std::vector<Edge<T>> edges_from_v;
		for (auto& e : m_edge_list)
		{
			if (e.source == v)
			{
				edges_from_v.emplace_back(e);
			}
		}
		return edges_from_v;
	}

	void add_edge(Edge<T>&& e)
	{
		if (e.source >= 'A' && e.source <= 'A' + m_vertices && e.destination >= 'A' && e.destination <= 'A' + m_vertices)
		{
			m_edge_list.emplace_back(e);
		}
		else
		{
			std::cerr << "Error" << std::endl;
		}

	}

	template<typename U>
	friend std::ostream& operator <<(std::ostream& os, const Graph<U>& G);

};

template<typename U>
std::ostream& operator <<(std::ostream& os, const Graph<U>& G)
{
	for (unsigned char i = 'A'; i < 'A' + G.get_vertices() - 1; i++)
	{
		os << "src " << i << " : ";
		auto edges = G.get_edge_from(i);
		for (auto& e : edges)
		{
			os << "{ des : " << e.destination << ", T : " << e.weight << " } ";
		}
		os << std::endl;
	}
	return os;
}

