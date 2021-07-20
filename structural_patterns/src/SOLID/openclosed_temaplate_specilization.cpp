//
// Created by sajith on 7/19/21.
//

#include <iostream>

class DirectedGraph
{
};

class UnDirectedGraph
{
};


template<typename Graph>
struct GraphAlgorithm
{
    const Graph graph;

    void search()
    {
        std::cout << "Some search algorithm for graph\n";
    }
};


template<>
struct GraphAlgorithm<DirectedGraph>
{
    const DirectedGraph graph;

    void search()
    {
        std::cout << "Some search algorithm only for Directed graph\n";
    }
};


template<typename Graph>
void run(const Graph &graph)
{
    GraphAlgorithm<Graph> algorithm{graph};
    algorithm.search();
}



int main()
{
    run(UnDirectedGraph{});
    run(DirectedGraph{});
    return 0;
}