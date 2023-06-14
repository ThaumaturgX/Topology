#include <iostream>
#include "GraphFactory.h"

using namespace std;

template<typename T>
void print_matrix(const T &matrix) {
	for (const auto& v : matrix) {
		for (const auto& val : v) {
			cout << val << " ";
		}
		cout << endl;
	}
}

int main() {
	GraphFactory gf;
	Graph g1(3, true);
	Graph g2 = gf.c(7, { 1, 2 });
	print_matrix(g2.get_adjacency_matrix());
	cout << endl;
	print_matrix(g2.route());
}