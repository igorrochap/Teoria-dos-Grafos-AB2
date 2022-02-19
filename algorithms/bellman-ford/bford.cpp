#include <iostream>
#include <string>
#include "../../utils/Input.hpp"
#include "../../utils/Graph/Digraph.hpp"
#include "../../utils/File.hpp"

#define INFINITY 0x3f3f3f3f

Digraph *buildGraph(Input input) {
    File *file = new File(input.getFilename());
    Digraph *graph = new Digraph(file->getVertexesNumber(), file->getEdgesNumber());
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

std::vector<int> bellmanFord(Digraph *graph, int initialVertex) {
    std::vector<int> distance(graph->getVertexesNumber() + 1, INFINITY);
    std::vector<int> previous(graph->getVertexesNumber() + 1, INFINITY);
    distance[initialVertex] = 0;
    for(int i = 1; i <= graph->getVertexesNumber() - 1; i++) {
        for(int sourceVertex = 1; sourceVertex <= graph->getVertexesNumber(); sourceVertex++) {
            for(std::vector<std::pair<int, int>>::iterator iterator = graph->edges[sourceVertex].begin(); iterator != graph->edges[sourceVertex].end(); iterator++) {
                int destinationVertex = iterator->first;
                int weightToDestination = iterator->second;
                if(distance.at(destinationVertex) > distance.at(sourceVertex) + weightToDestination) {
                    distance.at(destinationVertex) = distance.at(sourceVertex) + weightToDestination;
                    previous.at(destinationVertex) = sourceVertex;
                }
            }
        }
    }

    return distance;
}

int main(int argc, char *argv[]) {
    Input input;
    input.treat(argc, argv);
    Digraph *graph = buildGraph(input);
    std::vector<int> distances = bellmanFord(graph, input.getInitialVertex());
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