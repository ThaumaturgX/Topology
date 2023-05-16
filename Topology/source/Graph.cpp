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
