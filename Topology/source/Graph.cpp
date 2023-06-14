#include "Graph.h"

#include <queue>

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

Matrix Graph::get_adjacency_matrix() const {
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

std::vector<std::vector<int>> Graph::route() {
	// initialize port numbers
	auto port = initialize_ports();

	// for every node
	for (size_t node = 0; node < m_node_count; ++node) {
		// info about whether or not the node was visited
		std::vector<bool> vis(m_node_count, false); 
		// perform BFS
		std::queue<size_t> q({ node });
		while (!q.empty()) {
			size_t n = q.size();
			for (size_t i = 0; i < n; ++i) {
				// get the current element id from the queue
				size_t cur = q.front();
				q.pop();
				vis[cur] = true;

				// iterate over neighbors of current node
				for (size_t neighbor = 0; neighbor < m_node_count; ++neighbor) {
					// if we haven't reached this neighbor yet, we say that
					// the shortest path from 'node' to 'neighbor'
					// goes through 'cur'
					if (m_adj[cur][neighbor] && !vis[neighbor]) {
						// assign the port if it is not already assigned
						if(port[node][neighbor] == -1)
							port[node][neighbor] = port[node][cur];

						// add the neighbor to the next step of BFS
						q.push(neighbor);
					}
				}
			}
		}
	}
	return port;
}

std::vector<std::vector<int>> Graph::initialize_ports() {
	std::vector<std::vector<int>> res(m_node_count, std::vector<int>(m_node_count, -1));
	std::vector<size_t> port_count(m_node_count, 0);

	// iterate over every edge and assign ports
	for (size_t i = 0; i < m_node_count - 1; ++i) {
		for (size_t j = i + 1; j < m_node_count; ++j) {
			if (!m_adj[i][j]) continue;
			res[i][j] = port_count[i]++;
			res[j][i] = port_count[j]++;
		}
	}
	return res;
}
