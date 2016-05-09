#include "adjlist.hpp"

#include <iostream>

// gets weight from distance in feet and speed
// in miles per hour
double get_weight(double distance, double speed);

int main()
{
	Graph<double> g1(16);

	g1.add_edge(0, 1, get_weight(1531.12, 25), false);
	g1.add_edge(1, 2, get_weight(456.38, 25), false);
	g1.add_edge(2, 3, get_weight(811.32, 15), false);
	g1.add_edge(3, 4, get_weight(655.74, 25), false);
	g1.add_edge(4, 5, get_weight(967.09, 15), false);
	g1.add_edge(4, 6, get_weight(860.72, 25), false);
	g1.add_edge(5, 7, get_weight(659.31, 15), false);
	g1.add_edge(6, 7, get_weight(899.94, 25), false);
	g1.add_edge(7, 8, get_weight(1163.35, 25), false);
	g1.add_edge(8, 9, get_weight(976.01, 15), false);
	g1.add_edge(8, 10, get_weight(974.17, 25), false);
	g1.add_edge(9, 11, get_weight(558.20, 15), false);
	g1.add_edge(10, 11, get_weight(295.96, 25), false);
	g1.add_edge(11, 12, get_weight(188.34, 25), false);
	g1.add_edge(12, 13, get_weight(990.03, 25), false);
	g1.add_edge(13, 14, get_weight(241.36, 25), false);
	g1.add_edge(14, 15, get_weight(265.95, 25), false);
	g1.add_edge(15, 0, get_weight(923.74, 25), false);

	std::vector<int> path = g1.dijkstra(0, 8);

	for (int i=0; i < path.size(); i++)
		std::cout << path[i] << " ";
	std::cout << std::endl;

    return 0;
}

// gets weight from distance in feet and speed
// in miles per hour
double get_weight(double distance, double speed) {
	distance *= 0.000189394; // convert feet to miles

	return distance*speed;
}