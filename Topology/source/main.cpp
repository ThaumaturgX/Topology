#include <iostream>
#include "Graph.h"

using namespace std;

void print_matrix(const Matrix &matrix) {
	for (const auto& v : matrix) {
		for (const auto& val : v) {
			cout << val << " ";
		}
		cout << endl;
	}
}

int main() {
	Graph g(3);

	g.add_edge(0, 2);
	g.add_edge(0, 1);
	g.add_edge(1, 2);

	auto mat = g.get_adjecency_matrix();
	print_matrix(mat);
}