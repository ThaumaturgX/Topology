#include <iostream>
#include "GraphFactory.h"

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
	GraphFactory gf;
	Graph g = gf.c(9, { 1, 3, 4 });

	print_matrix(g.get_adjecency_matrix());
}