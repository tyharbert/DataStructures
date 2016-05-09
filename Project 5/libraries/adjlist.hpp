// Tyler Harbert May 2016
// This class represents an adjacency list
// class representation of a weighted graph

#ifndef ADJLIST_HPP
#define ADJLIST_HPP

#include "uadjlist.hpp"
#include "path.hpp"

#include <limits>

// Graph
// this class represents an unweighted graph
template <typename W>
class Graph: public uGraph {
private:
	int min_vertex(W* w, bool* v);

public:
	Graph(int size): uGraph(size) {}
	virtual ~Graph() {}
	void add_edge(int v1, int v2, W weight, bool directional = true);
	void add_edge(int v1, int v2 , bool d) { add_edge(v1, v2, 0, d); }
	std::vector<int> dijkstra(int source, int dest);
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

// dijkstra
// this runs dijkstra's algorithm to 
// find the shortest path from the source
// to the destination

// Adapted form ODS version to retrive 
// shortest path to a specific destination
// https://canvas.instructure.com/courses/995719/assignments/4287854
template <typename W>
std::vector<int> Graph<W>::dijkstra(int source, int dest) {
	W* weight = new W[size];
	bool* visited = new bool[size];
	Path path(size);

	// intialize to infinity and false
	for (int i=0; i < size; i++) {
		weight[i] = std::numeric_limits<W>::max();
		visited[i] = false;
	}

	weight[source] = 0;

	for (int i=0; i < size; i++) {
		int current = min_vertex(weight, visited); // get min vertex
		
		visited[current] = true; // mark as visited

		if (weight[current] == std::numeric_limits<W>::max()) return std::vector<int>(); // unreachable

		if (current == dest) break; // path to destination found

		Edge<W>* e = (Edge<W>*)verticies[current]->get_next();

		while (e) {
			int vi = e->get_vertex_index();
			W w = e->get_weight();

			// if weight to a location is less from current vertex
			if (weight[vi] > weight[current] + w) {
				weight[vi] = weight[current] + w;
				path.add(current, vi);
			}

			e = (Edge<W>*)e->get_next();
		}
	}

	return path.get(dest);
}

// min_vertex
// gets the least vertex not yet visited
template <typename W>
int Graph<W>::min_vertex(W* w, bool* v) {
	int min = -1;

	for (int i=0; i < size; i++)
		if (!v[i]) // if not visited
			if (min == -1 || w[i] < w[min]) // weight less than min
				min = i;

	return min;
}

// this prints a graph in adjacency list form
template <typename W>
std::ostream& operator<<(std::ostream& os, const Graph<W>& g) {
    return os << (uGraph&)g; // call uGraph ostream 
}

#endif
