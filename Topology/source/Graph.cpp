#include "Graph.h"

constexpr bool between(size_t x, size_t left, size_t right) {
	return x >= left && x <= right;
}

bool Graph::add_edge(size_t v1, size_t v2) {
	if (between(v1, 0, m_node_count - 1) && between(v2, 0, m_node_count - 1)) {
		m_adj[v1][v2] = m_adj[v2][v1] = true;
		return true;
	}
	return false;
}

bool Graph::remove_edge(size_t v1, size_t v2) {
	if (between(v1, 0, m_node_count - 1) && between(v2, 0, m_node_count - 1)) {
		m_adj[v1][v2] = m_adj[v2][v1] = false;
		return true;
	}
	return false;
}

Matrix Graph::get_adjecency_matrix() const {
	return m_adj;
}

Graph Graph::root_product(const Graph& g) const {
	Graph product(m_node_count * g.m_node_count);

	// Copy connections of inital graph to product
	for (size_t i = 0; i < m_node_count - 1; ++i) {
		for (size_t j = i + 1; j < m_node_count; ++j) {
			if (m_adj[i][j])
				product.add_edge(i, j);
		}
	}

	// Iterate over all nodes of the graph that is being multiplied
	for (size_t cur_node = 0, offset = m_node_count-1; cur_node < m_node_count; ++cur_node, offset += g.m_node_count-1) {
		// Consider every edge, use the fact that the graph is undirected
		for (size_t i = 0; i < g.m_node_count - 1; ++i) {
			for (size_t j = i + 1; j < g.m_node_count; ++j) {
				// Replace node 0 of each instance of g with the current node
				// and add offset to other nodes
				const size_t row = i == 0 ? cur_node : i + offset;
				const size_t col = j + offset;
				if (g.m_adj[i][j])
					product.add_edge(row, col);
			}
		}
	}
	return product;
}
