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
	Graph g1 = gf.qr(13);
	print_matrix(g1.get_adjacency_matrix());
	cout << endl;
	print_matrix(g1.route());
}