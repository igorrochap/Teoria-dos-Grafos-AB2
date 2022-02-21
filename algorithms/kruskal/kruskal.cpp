#include <iostream>
#include <string>
#include <algorithm>
#include "../../utils/Input.hpp"
#include "../../utils/Graph/Graph.hpp"
#include "../../utils/File.hpp"
#include "../../utils/DisjointSet.hpp"

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

bool sortByWeightCondition(std::pair<int, std::pair<int, int>> element1, std::pair<int, std::pair<int, int>> element2) {
    return element1.second.second < element2.second.second;
}

std::vector<std::pair<int, int>> kruskal(Graph *graph) {
    std::vector<std::pair<int, int>> treeEdges;
    std::vector<std::pair<int, std::pair<int, int>>> graphEdges = graph->getEdges();
    int treeCost = 0;
    std::sort(graphEdges.begin(), graphEdges.end(), sortByWeightCondition);
    DisjointSet *disjointSet = new DisjointSet(graph->getVertexesNumber());
    std::vector<std::pair<int, std::pair<int, int>>>::iterator iterator;
    for(iterator = graphEdges.begin(); iterator != graphEdges.end(); iterator++) {
        int vertex1 = iterator->first;
        int vertex2 = iterator->second.first;
        int vertex1InSet = disjointSet->Find(vertex1);
        int vertex2InSet = disjointSet->Find(vertex2);
        if(vertex1InSet != vertex2InSet) {
            int edgeWeight = iterator->second.second;
            treeEdges.push_back({vertex1, vertex2});
            treeCost += edgeWeight;
            disjointSet->Union(vertex1InSet, vertex2InSet);
        }
    }
    std::cout << "The cost of the Minimum Spanning Tree is: " << treeCost << std::endl;
    return treeEdges;
}

int main(int argc, char *argv[]) {
    Input input;
    input.treat(argc, argv);
    Graph *graph = buildGraph(input);
    std::vector<std::pair<int, int>> treeEdges = kruskal(graph);
    if(input.showPath()) {
        std::cout << "Minimum Spanning Tree edges:" << std::endl;
        std::vector<std::pair<int, int>>::iterator iterator;
        for(iterator = treeEdges.begin(); iterator != treeEdges.end(); iterator++) {
            std::cout << "(" << iterator->first << ", " << iterator->second << ")" << std::endl;
        }
    }
    return 0;
}