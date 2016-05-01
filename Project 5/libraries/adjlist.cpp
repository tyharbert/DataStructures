#include "adjlist.hpp"


// constructor
Graph::Graph(int s): size(s) {
	verticies = new Vertex*[s];

	for (int i=0; i < s; i++)
		verticies[i] = new Vertex();
}

// TODO: destructor
Graph::~Graph() {

}

// TODO: implement weighted and unweighted graphs
void Graph::add_edge(int v1, int v2) {
	Node* n;

	for (int i=0; i < 2; i++) {
		n = verticies[v1];

		// get last node
		while(n->get_next())
			n = n->get_next();

		n->set_next(new uEdge(nullptr, v2));

		std::swap(v1, v2); // undirectional
	}
 
}

// prints a matrix
std::ostream& operator<<(std::ostream& os, const Graph& g) {
	Node* n;

	// loop through all verticies
	for (int i = 0; i < g.size; i++) {
		n = g.verticies[i]; // set to vertex
		
		// loop through edges
		while (n) {
			os << *n << " ";
			n = n->get_next();
		}
		os << std::endl;
	}

    return os;
}

