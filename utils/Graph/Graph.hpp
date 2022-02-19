#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <vector>

class Graph
{
    protected:
        int vertexesNumber, edgesNumber;
    public:
        std::vector<std::vector<std::pair<int, int>>> edges;
        Graph(int vertexNumber, int edgesNumber);
        void addEdge(int vertex1, int vertex2, int weight = 1);
        int getVertexesNumber();
        int getEdgesNumber();
        void show();
};

Graph::Graph(int vertexesNumber, int edgesNumber) {
    this->vertexesNumber = vertexesNumber;
    this->edgesNumber = edgesNumber;
    while(this->edges.size() <= this->vertexesNumber){
		this->edges.push_back({});
	}
}

void Graph::addEdge(int vertex1, int vertex2, int weight) {
    this->edges[vertex1].push_back(std::make_pair(vertex2, weight));
    this->edges[vertex2].push_back(std::make_pair(vertex1, weight));
}

void Graph::show() {
    for(int currentVertex = 1; currentVertex <= edgesNumber; currentVertex++){
		std::cout << "vertex " << currentVertex << ":" << std::endl;
		for(auto iterator = this->edges[currentVertex].begin(); iterator != this->edges[currentVertex].end(); iterator++) {
            int vertex = iterator->first;
            int weight = iterator->second;
            std::cout << "adjacency: vertex " << vertex << " with weight " << weight << std::endl;
        }
        std::cout << std::endl;
	}
}

int Graph::getVertexesNumber() {
    return this->vertexesNumber;
}



int Graph::getEdgesNumber() {
    return this->edgesNumber;
}

#endif