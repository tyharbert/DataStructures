#ifndef ADJLIST_HPP
#define ADJLIST_HPP

#include "node.hpp"

#include <iostream>


class Graph {
private:
	Vertex** verticies;
	int size;

public:
	Graph(int);
	~Graph();
	void add_edge(int, int);
	friend std::ostream& operator<<(std::ostream&, const Graph&);
};

#endif
