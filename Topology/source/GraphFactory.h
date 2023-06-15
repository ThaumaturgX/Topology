#pragma once

#include "Graph.h"


class GraphFactory {
public:
	Graph c(size_t n, const std::vector<size_t>& distances);
	Graph complete(size_t n);
	Graph qr(size_t q);
};
