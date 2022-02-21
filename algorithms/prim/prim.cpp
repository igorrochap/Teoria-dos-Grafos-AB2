#include <iostream>
#include <string>
#include <queue>
#include "../../utils/Input.hpp"
#include "../../utils/Graph/Graph.hpp"
#include "../../utils/File.hpp"

#define INFINITY 0x3f3f3f3f

Graph *buildGraph(Input input) {
    File *file = new File(input.getFilename());
    Graph *graph = new Graph(file->getVertexesNumber(), file->getEdgesNumber());
    while(!file->end()) {
        std::string line = file->getLine();
        if(file->lineHasWeight(line)) {
            graph->addEdge(file->getFirstVertex(line), file->getSecondVertex(line), file->getWeight(line));
        } else {
            graph->addEdge(file->getFirstVertex(line), file->getSecondVertex(line));
        }
    }
    return graph;
}

void printCost(std::vector<int> costs) {
    int cost = 0;
    for(int c : costs) {
        if(c != INFINITY) {
            cost += c;
        }
    }
    std::cout << "The cost of the Minimum Spanning Tree is: " << cost << std::endl;
}

std::vector<int> prim(Graph *graph, int initialVertex) {
    std::vector<int> cost(graph->getVertexesNumber() + 1, INFINITY);
    std::vector<int> previous(graph->getVertexesNumber() + 1, -1);
    std::vector<bool> inTree(graph->getVertexesNumber(), false);
    std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heap;

    cost[initialVertex] = 0;
    heap.push(std::make_pair(cost[initialVertex], initialVertex));
    while(!heap.empty()) {
        int expandedVertex = heap.top().second;
        heap.pop();
        inTree[expandedVertex] = true;
        std::vector<std::pair<int, int>>::iterator iterator;
        for(iterator = graph->edges[expandedVertex].begin(); iterator != graph->edges[expandedVertex].end(); iterator++) {
            int vertex = iterator->first;
            int edgeWeight = iterator->second;
            if(!inTree[vertex] && cost[vertex] > edgeWeight) {
                cost[vertex] = edgeWeight;
                heap.push(std::make_pair(cost[vertex], vertex));
                previous[vertex] = expandedVertex;
            }
        }
    }
    printCost(cost);
    return previous;
}

int main(int argc, char *argv[]) {
    Input input;
    input.treat(argc, argv);
    Graph *graph = buildGraph(input);
    std::vector<int> previous = prim(graph, input.getInitialVertex());
    if(input.showPath()) {
        for(int i = 1; i <= graph->getVertexesNumber(); i++) {
            if(previous[i] != -1) {
                std::cout << "(" << previous[i] << ", " << i << ")"<< std::endl;
            }
        }
    }
    return 0;
}