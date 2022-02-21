#ifndef _DISJOINT_SET_HPP_
#define _DISJOINT_SET_HPP_

#include <iostream>
#include <fstream>
#include <string>


class DisjointSet
{
private:
    int size;
    std::vector<int> parent;
    std::vector<int> rank;
public:
    DisjointSet(int size);
    int Find(int vertex);
    void Union(int vertex1, int vertex2);
};

DisjointSet::DisjointSet(int size)  {
    this->size = size;
    parent.resize(this->size);
    rank.resize(this->size);
    for(int i = 1; i <= size; i++) {
        this->rank[i] = 0;
        this->parent[i] = i;
    }
}

int DisjointSet::Find(int vertex) {
    if(vertex != this->parent[vertex]) {
        this->parent[vertex] = this->Find(parent[vertex]);
    }
    return this->parent[vertex];
}

void DisjointSet::Union(int vertex1, int vertex2) {
    vertex1 = this->Find(vertex1);
    vertex2 = this->Find(vertex2);
    if(this->rank[vertex1] >= this->rank[vertex2]) {
        this->parent[vertex2] = vertex1;
        if(this->rank[vertex1] >= this->rank[vertex2]) {
            this->rank[vertex1]++;
        }
    } else {
        this->parent[vertex1] = vertex2;
    }
}

#endif