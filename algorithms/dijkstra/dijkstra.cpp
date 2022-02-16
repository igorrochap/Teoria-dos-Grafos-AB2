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

std::vector<int> dijkstra(Graph *graph, int initialVertex) {
    std::vector<int> distance(graph->getVertexesNumber(), INFINITY);
    std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int>>> minHeap;
    distance[initialVertex] = 0;
    minHeap.push(std::make_pair(distance[initialVertex], initialVertex));
    while(!minHeap.empty()) {
        int expandedVertex = minHeap.top().second;
        minHeap.pop();
        std::vector<std::pair<int, int>>::iterator iterator;
        for(iterator = graph->edges[expandedVertex].begin(); iterator != graph->edges[expandedVertex].end(); iterator++) {
            int currentAdjacentVertex = iterator->first;
            int edgeWeight = iterator->second;
            if(distance[currentAdjacentVertex] > distance[expandedVertex] + edgeWeight) {
                distance[currentAdjacentVertex] = distance[expandedVertex] + edgeWeight;
                minHeap.push(std::make_pair(distance[currentAdjacentVertex], currentAdjacentVertex));
            }
        }
    }
    return distance;
}

int main(int argc, char *argv[]) {
    Input input;
    input.treat(argc, argv);
    Graph *graph = buildGraph(input);
    std::vector<int> distances = dijkstra(graph, input.getInitialVertex());
    for(int i = 1; i <= graph->getVertexesNumber(); i++) {
        if(input.hasFinalVertex()) {
            if(input.getFinalVertex() == i) {
                std::cout << "Distance from " << input.getInitialVertex() << " to " << i << ": "<< distances[i] << std::endl;
                break;
            }
        } else {
            std::cout << "Distance from " << input.getInitialVertex() << " to " << i << ": "<< distances[i] << std::endl;
        }
    }
    return 0;
}