#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

class DisjointSet
{
private:

	struct Node
	{
		unsigned char id;
		unsigned rank;
		unsigned char parent;

		Node(unsigned char n_id) : id{ n_id }, rank{ 0 }, parent{ n_id } { }

		bool operator != (const Node& node)
		{
			return this->id != node.id;
		}

		bool operator ==(const Node& node)
		{
			return this->id == node.id; 
		}
	};

	std::vector<Node> m_nodes;

public:

	DisjointSet(int N)
	{
		m_nodes.reserve(N);
	}

	void make_set(const unsigned char& x)
	{
		m_nodes.emplace_back(x);
	}

	unsigned char find_node_parent(unsigned char x)
	{
		auto node_it = std::find_if(m_nodes.begin(), m_nodes.end(),
			[x](auto other) { return other.id == x; });

		auto node_id = (*node_it).id;

		while (node_id != m_nodes[static_cast<unsigned>(node_id - 65)].parent)
		{
			node_id = m_nodes[static_cast<unsigned>(node_id - 65)].parent;
		}

		return node_id;
	}

	void union_find(unsigned char x, unsigned char y)
	{
		auto root_x = find_node_parent(x);
		auto root_y = find_node_parent(y);

		if (root_x == root_y)
		{
			return;
		}

		if (m_nodes[static_cast<unsigned>(root_x - 65)].rank >
			m_nodes[static_cast<unsigned>(root_y - 65)].rank)
		{
			std::swap(root_x, root_y);
		}

		m_nodes[static_cast<unsigned>(root_x - 65)].parent =
			m_nodes[static_cast<unsigned>(root_y - 65)].parent; 

		m_nodes[static_cast<unsigned>(root_y - 65)].rank++;
	}
};