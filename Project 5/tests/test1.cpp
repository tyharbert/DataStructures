#include "adjlist.hpp"

#include <iostream>

int main()
{
	Graph<int> g1(8);

	g1.add_edge(2, 6, 44);
	g1.add_edge(2, 4, 78, false);

	std::cout << g1 << std::endl;

    return 0;
}
