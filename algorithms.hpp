#include <iostream>
#include <queue>
#include "graph.h"

/* If we don't want to have this templated that's fine too, we will likely just use vertices instead of ints like Geeks for Geeks did */ 
/* Might not be easily doable without explicity using Vertex and such anyways! */

namespace Alg {
    template <class G, class V>
    void shortest_path(G path, V start, V end) {
        //https://www.geeksforgeeks.org/c-program-for-dijkstras-shortest-path-algorithm-greedy-algo-7/
        std::cout << "\nShortest_Path:\n";
    }

    template <class G, class V>
    void bfs(G graph, V start) {
        //https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
        std::cout << "\nBFS\n";
    }

    template <class G>
    void pagerank(G graph,  double alpha, int iterations, double tolerance) {
        //https://www.geeksforgeeks.org/page-rank-algorithm-implementation/
        std::cout << "\nPage_rank\n";
    }
}