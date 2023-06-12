#include "GraphFactory.h"

Graph GraphFactory::c(size_t n, const std::vector<size_t>& distances) {
	Graph g(n);

	// Connect neighboring nodes
	for (size_t i = 0; i < n; ++i) {
		g.add_edge(i, (i + 1) % n);
	}
	
	// Make connections for every distance
	for (const size_t& distance : distances) {
		for (size_t i = 0; i < n; ++i) {
			g.add_edge(i, (i + distance) % n);
		}
	}

	return g;
}
