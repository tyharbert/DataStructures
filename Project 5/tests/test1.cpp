#include "adjlist.hpp"

#include <iostream>

int main()
{
	Graph<int> g1(6);

	g1.add_edge(0, 2, 7);
	g1.add_edge(0, 4, 9);
	g1.add_edge(2, 1, 5);
	g1.add_edge(2, 3, 1);
	g1.add_edge(2, 5, 2);
	g1.add_edge(3, 5, 2);
	g1.add_edge(4, 5, 1);
	g1.add_edge(5, 1, 6);

	std::vector<int> path = g1.dijkstra(0, 5);

	std::cout << g1 << std::endl;

	for (int i=0; i < path.size(); i++)
		std::cout << path[i] << " ";
	std::cout << std::endl;

    return 0;
}
