// Tyler Harbert May 2016
// This class represents an adjacency list
// class representation of a weighted graph

#ifndef ADJLIST_HPP
#define ADJLIST_HPP

#include "uadjlist.hpp"

// Graph
// this class represents an unweighted graph
template <typename W>
class Graph: public uGraph {
public:
	Graph(int size): uGraph(size) {}
	virtual ~Graph() {}
	void add_edge(int v1, int v2, W weight, bool directional = true);
	void add_edge(int v1, int v2 , bool d) { add_edge(v1, v2, 0, d); }
	template <typename W1>
	friend std::ostream& operator<<(std::ostream&, const Graph<W1>&);
};

// add_edge
// this function adds a weighted edge
// and it can be directional or undirectional
template <typename W>
void Graph<W>::add_edge(int v1, int v2, W weight, bool directional) {
	Node* n;

	n = verticies[v1];

	// get last node
	while (n->get_next())
		n = n->get_next();

	// add weighted edge if weight supplied
	n->set_next(new Edge<W>(nullptr, v2, weight));

	// recursively add opposite edge
	if (!directional)
		add_edge(v2, v1, weight);
 
}

// this prints a graph in adjacency list form
template <typename W>
std::ostream& operator<<(std::ostream& os, const Graph<W>& g) {
    return os << (uGraph&)g; // call uGraph ostream 
}

#endif
