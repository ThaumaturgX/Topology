#pragma once

#include <vector>

/* 
	Implementation of an undirected graph.
	Uses adjecency matrix to store data.
*/

using Matrix = std::vector<std::vector<bool>>;

class Graph {
public:
	Graph() = delete;

	/* initializes adjecency matrix @param n - number of nodes */
	Graph(size_t n, bool fill_value = false) :
		m_adj(n, std::vector<bool>(n, fill_value)),
		m_node_count(n) 
	{}

	/* copy constructor */
	Graph(const Graph& graph) = default;

	/* move constructor */
	Graph(Graph&& graph) = default;

public:
	/* adds an edge between nodes v1 and v2 
	*  @return true if success else false
	*/
	bool add_edge(size_t v1, size_t v2);

	/* removes an edge between nodes v1 and v2
	*  @return true if success else false
	*/ 
	bool remove_edge(size_t v1, size_t v2); 

	/* returns the adjecency matrix representation of the graph */
	Matrix get_adjecency_matrix() const;

	/* return root product of 2 graphs */
	Graph root_product(const Graph& g) const;

	/* number of vertices in a Graph*/
	size_t node_count() const { return m_node_count; }

private:
	Matrix m_adj;		// adjecency matrix
	size_t m_node_count;	// number of nodes
};