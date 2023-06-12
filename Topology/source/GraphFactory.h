#pragma once

#include "Graph.h"


class GraphFactory {
public:
	Graph c(size_t n, const std::vector<size_t>& distances);
};
