#ifndef DEF_GRAPH
#define DEF_GRAPH

#include <vector>
#include <map>
#include "Node.hpp"


class Graph
{
    public:

    std::map<int, bool> m_buffers;

    Graph(std::vector<Node*> nodes);

    void displayFinalBuffers();
    int getFirstFreeBuffer();
    void setBuffer(int i, bool v);

    void calculate_buffers(Node* start);

    private:

    std::vector<Node*> m_nodes;
};

#endif