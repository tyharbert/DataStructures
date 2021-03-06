// Tyler Harbert May 2016
// This class represents an adjacency list
// class representation of a graph

#ifndef UADJLIST_HPP
#define UADJLIST_HPP

#include "node.hpp"

// uGraph
// this class represents an unweighted graph
class uGraph {
protected:
	Vertex** vertices;
	int size;

public:
	uGraph(int);
	virtual ~uGraph();
	virtual void add_edge(int v1, int v2, bool directional = true);
	friend std::ostream& operator<<(std::ostream&, const uGraph&);
};

// uGraph constructor
uGraph::uGraph(int s): size(s) {
	vertices = new Vertex*[s];

	for (int i=0; i < s; i++)
		vertices[i] = new Vertex();
}

// uGraph destructor
uGraph::~uGraph() {
	// loop through all vertices
	for (int i=0; i < size; i++) {
		// the destructor is set up to delete a 
		// full chain of Node objects recursively
		delete vertices[i];
	}

	delete vertices;
}

// add_edge
// this function adds an unweighted edge
// and it can be directional or undirectional
void uGraph::add_edge(int v1, int v2, bool directional) {
	Node* n;

	n = vertices[v1];

	// get last node
	while (n->get_next())
		n = n->get_next();

	// add edge
	n->set_next(new uEdge(nullptr, v2));

	// recursively add opposite edge
	if (!directional)
		add_edge(v2, v1);
 
}

// this prints a graph in adjacency list form
std::ostream& operator<<(std::ostream& os, const uGraph& g) {
	Node* n;

	// loop through all vertices
	for (int i = 0; i < g.size; i++) {
		n = g.vertices[i]; // set to vertex

		// print vertex
		os << *n << i;
		n = n->get_next();
		
		// loop through edges
		while (n) {
			os << " -> " << *n;
			n = n->get_next();
		}
		os << std::endl;
	}

    return os;
}

#endif
