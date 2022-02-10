#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <vector>

class Graph
{
    private:
        int vertexesNumber, edgesNumber;
        std::vector<std::pair<int, int>> edges;
    public:
        Graph(int vertexNumber, int edgesNumber);
        void show();
};

Graph::Graph(int vertexNumber, int edgesNumber) {
    this->vertexesNumber = vertexesNumber;
    this->edgesNumber = edgesNumber;
}

void Graph::show() {
    for(int i = 0; i < this->edgesNumber; i++) {
        std::cout << i << std::endl;
    }
}

#endif