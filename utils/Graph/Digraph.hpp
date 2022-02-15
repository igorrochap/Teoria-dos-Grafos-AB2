#ifndef _DIGRAPH_HPP_
#define _DIGRAPH_HPP_

#include <iostream>
#include <vector>
#include "Graph.hpp"

class Digraph: public Graph 
{
    public:
        using Graph::Graph;
        void addEdge(int vertex1, int vertex2, int weight = 1);
};

void Digraph::addEdge(int vertex1, int vertex2, int weight) {
    this->edges[vertex1].push_back(std::make_pair(vertex2, weight));
}

#endif
