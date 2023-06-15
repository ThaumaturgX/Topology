#include "GraphFactory.h"

#include <unordered_set>

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

Graph GraphFactory::complete(size_t n) {
	return Graph(n, true);
}

bool is_prime_power(size_t n) {
	if (n == 0) return false;
	if (n == 1)	return true; // 1 is considered a prime power

	for (size_t i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			return n == 1;
		}
	}
	return true;
}

Graph GraphFactory::qr(size_t q) {
	// Check the condition for Paley graphs
	if (!is_prime_power(q) || q % 4 != 1) return Graph(0);

	std::unordered_set<size_t> quardratic_residues;
	for (size_t i = 1; i < q; ++i) {
		quardratic_residues.insert(i * i % q);
	}

	return this->c(q, std::vector<size_t>(quardratic_residues.begin(), quardratic_residues.end()));
}

Graph GraphFactory::torus(size_t n, size_t m) {
	Graph g(n * m);

	// iterate over every node and make connections
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			const size_t current_node = i * m + j;
			g.add_edge(current_node, (j == m - 1 ? current_node - m + 1 : current_node + 1)); // connect to the right
			g.add_edge(current_node, (i == n - 1 ? j : current_node + m));				// connect below
		}
	}

	// handle edge cases: m == 1 or n == 1
	for (size_t i = 0; i < n * m; ++i) {
		g.remove_edge(i, i);
	}

	return g;
}
