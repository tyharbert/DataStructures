// Tyler Harbert May 2016
// This class represents an adjacency list
// class representation of a graph

#ifndef ADJLIST_HPP
#define ADJLIST_HPP

#include "node.hpp"

// Graph
// this class represents a generic graph
template <typename W>
class Graph {
private:
	Vertex** verticies;
	int size;

public:
	Graph(int);
	~Graph();
	void add_edge(int v1, int v2, W weight = 0, bool directional = true);
	template <typename W1>
	friend std::ostream& operator<<(std::ostream&, const Graph<W1>&);
};

// Graph constructor
template <typename W>
Graph<W>::Graph(int s): size(s) {
	verticies = new Vertex*[s];

	for (int i=0; i < s; i++)
		verticies[i] = new Vertex();
}

// Graph destructor
template <typename W>
Graph<W>::~Graph() {
	Node* n, d;

	// loop through all verticies
	for (int i=0; i < size; i++) {
		// the destructor is set up to delete a 
		// full chain of Node objects recursively
		delete verticies[i];
	}

	delete verticies;
}

// add_edge
// this function adds an edge it can add a weighted edge if
// a positive value is supplied and it can add both directional
// and undirectional edges
template <typename W>
void Graph<W>::add_edge(int v1, int v2, W weight, bool directional) {
	Node* n;

	n = verticies[v1];

	// get last node
	while (n->get_next())
		n = n->get_next();

	// add weighted edge if weight supplied
	if (weight > 0)
		n->set_next(new Edge<W>(nullptr, v2, weight));
	else
		n->set_next(new uEdge(nullptr, v2));

	// recursively add opposite edge
	if (!directional)
		add_edge(v2, v1, weight);
 
}

// this prints a graph in adjacency list form
template <typename W>
std::ostream& operator<<(std::ostream& os, const Graph<W>& g) {
	Node* n;

	// loop through all verticies
	for (int i = 0; i < g.size; i++) {
		n = g.verticies[i]; // set to vertex

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
