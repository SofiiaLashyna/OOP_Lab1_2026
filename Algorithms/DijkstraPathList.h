#ifndef DIJKSTRAPATHLIST_H
#define DIJKSTRAPATHLIST_H

#include "GraphList.h"
#include "Queue.h"
#include <vector>
#include <climits>
#include <algorithm>

template<typename T>
class DijkstraPathList {
public:
    std::vector<int> findShortestPath(GraphList<T>& g, int startId, int endId) {
        int start = g.findIndexById(startId);
        int end = g.findIndexById(endId);
        if (start == -1 || end == -1) return {};

        int V = g.getVertices().size();
        std::vector<int> dist(V, INT_MAX);
        std::vector<int> parent(V, -1);
        dist[start] = 0;

        Queue<int> q;
        q.push(start, 0);

        while (!q.empty()) {
            auto [u, d] = q.popMin();

            if (d > dist[u]) continue;
            if (u == end) break;

            for (auto &[v, w]: g.adjacencyList[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    q.push(v, dist[v]);
                }
            }
        }

        if (dist[end] == INT_MAX) return {};

        std::vector<int> path;
        for (int cur = end; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        std::reverse(path.begin(), path.end());
        return path;
    }
};

#endif //DIJKSTRAPATHLIST_H