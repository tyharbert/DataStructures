#include "adjlist.hpp"

#include <iostream>

int main()
{
	Graph g1(8);

	g1.add_edge(2, 6);

	std::cout << g1 << std::endl;

    return 0;
}
