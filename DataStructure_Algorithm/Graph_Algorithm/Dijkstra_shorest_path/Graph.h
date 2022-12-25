#pragma once
#include<iostream>
#include<vector>

template<typename T>
struct Edge
{
	unsigned src;
	unsigned dst;
	T weight;

	inline bool operator < (const Edge<T>& e)
	{
		return this->weight < e.weight;
	}

	inline bool operator > (const Edge<T>& e)
	{
		return this->weight > e.weight;
	}
};

template<typename T>
class Graph
{
private:

	unsigned m_N;
	std::vector<Edge<T>> m_edge_list;

public:

	Graph(unsigned N) : m_N{ N } { }

	auto getNumberOfEdges() const
	{
		return m_N;
	}

	auto& getEdges() const
	{
		return m_edge_list;
	}

	auto getAdjEdges(unsigned v) const
	{
		std::vector<Edge<T>> adj_edges;

		for (auto& e : m_edge_list)
		{
			if (v == e.src)
			{
				adj_edges.emplace_back(e);
			}
		}

		return adj_edges;
	}

	void add_edge(Edge<T>&& e)
	{
		m_edge_list.emplace_back(e);
	}

	template<typename U>
	friend std::ostream& operator << (std::ostream& os, const Graph<U>& G);
};

template<typename U>
std::ostream& operator << (std::ostream& os, const Graph<U>& G)
{
	for (unsigned i = 1; i < G.getNumberOfEdges(); i++)
	{
		os << "Start : " << static_cast<unsigned char>(i + 64) << " = ";
		for (auto& e : G.getAdjEdges(i))
		{
			os << "[dst=" << static_cast<unsigned char>(e.dst+ 64) << ", " 
				<< "weight=" << e.weight << "] ";
		}
		os << std::endl;		
	}
	return os;
}