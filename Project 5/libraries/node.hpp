#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node {
private:
	Node* next;

public:
	Node(): next(nullptr) {}
	Node(Node* n): next(n) {}
	Node* get_next() { return next; }
	void set_next(Node* n) { next = n; }
	virtual std::ostream& print(std::ostream& os) const { return os << "n"; }
};

class Vertex: public Node {
public:
	Vertex(): Node() {}
	Vertex(Node* n): Node(n) {}
	virtual std::ostream& print(std::ostream& os) const { return os << "v"; }
};

class uEdge: public Node {
private:
	int vertex_index;

public:
	uEdge(Node* n, int vi): Node(n), vertex_index(vi) {}
	virtual std::ostream& print(std::ostream& os) const { 
		return os << "vi:" << vertex_index;
	}
};

template <typename W>
class Edge: public uEdge {
private:
	W weight;

public:
	Edge(Node* n, W w, int vi): uEdge(n, vi), weight(w) {}
	virtual std::ostream& print(std::ostream& os) const { 
		return os << uEdge::print(os) << " w:" << weight;
	}
};

// ostream for node
// this uses a dynamic polymorphism to decide which of the
// derived classes should be printed
inline std::ostream& operator<<(std::ostream& os, const Node& n) {
	return n.print(os);
}

#endif
