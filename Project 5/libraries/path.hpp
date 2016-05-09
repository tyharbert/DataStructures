// Tyler Harbet May 2016
// this is used to track the shortest
// path to the destination in dijkstra

#ifndef PATH_HPP
#define PATH_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Path {
private:
	int* path;
	int size;

public:
	Path(int s): size(s), path(new int[s]) {
		for (int i=0; i < size; i++)
			path[i] = -1;
	}
	~Path() { delete[] path; }
	void add(int source, int dest);
	std::vector<int> get(int source, int dest);
	friend std::ostream& operator<<(std::ostream&, const Path&);
};

// this sets the destinations value to
// its source so it can be traced backwards
// from dest to source
inline void Path::add(int source, int dest) {
	path[dest] = source;
}

// this gets the shortest path from
// source to dest
std::vector<int> Path::get(int source, int dest) {
	std::vector<int> v;

	while (dest != source) {
		v.push_back(dest);
		dest = path[dest];
	}

	v.push_back(source);

	std::reverse(v.begin(), v.end());

	return v;
}

// this prints the path
std::ostream& operator<<(std::ostream& os, const Path& p) {
    for (int i=0; i < p.size; i++)
    	os << p.path[i] << " ";

    return os << std::endl;
}

#endif
