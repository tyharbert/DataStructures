// Tyler Harbert May 2016
// These classes represent the verticies
// and edges to be used in a Graph class

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

static int temp = 0;

// this class is the base class for representing 
// both verticies and edges
class Node {
private:
	Node* next;

public:
	Node(): next(nullptr) {}
	Node(Node* n): next(n) {}
	virtual ~Node() { if(next) delete next; } // delete next if not null
	Node* get_next() { return next; }
	void set_next(Node* n) { next = n; }
	virtual std::ostream& print(std::ostream& os) const { return os << "n"; }
};

// Vertex
// contains a pointer to the first edge
class Vertex: public Node {
public:
	Vertex(): Node() {}
	Vertex(Node* n): Node(n) {}
	virtual ~Vertex() {}
	virtual std::ostream& print(std::ostream& os) const { return os << "v"; }
};

// Unweighted Edge
// this holds the vertex index of
// the connected vertex
class uEdge: public Node {
private:
	int vertex_index;

public:
	uEdge(Node* n, int vi): Node(n), vertex_index(vi) {}
	virtual ~uEdge() {}
	virtual std::ostream& print(std::ostream& os) const { 
		return os << "vi:" << vertex_index;
	}
};

// Weighted Edge
// it accepts a template type to represent
// the weight of an edge
template <typename W>
class Edge: public uEdge {
private:
	W weight;

public:
	Edge(Node* n, int vi, W w): uEdge(n, vi), weight(w) {}
	virtual ~Edge() {}
	virtual std::ostream& print(std::ostream& os) const { 
		return uEdge::print(os) << " w:" << weight;
	}
};

// ostream for node
// this uses a dynamic polymorphism to decide which of the
// derived classes should be printed
inline std::ostream& operator<<(std::ostream& os, const Node& n) {
	return n.print(os);
}

#endif
