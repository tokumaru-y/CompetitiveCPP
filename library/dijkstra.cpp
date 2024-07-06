// ref: https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/dijkstra#1.2-%E6%9C%80%E7%9F%AD%E7%B5%8C%E8%B7%AF%E3%82%92%E5%86%8D%E6%A7%8B%E7%AF%89%E3%81%99%E3%82%8B
#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <queue> // std::priority_queue
#include <functional> // std::greater
#include <algorithm> // std::reverse()

constexpr long long INF = (1LL << 60);

struct Edge {
    int to;
    int cost;
};

using Graph = std::vector<std::vector<Edge>>;

using Pair = std::pair<long long, int>;


// graph: 隣接リスト
// distances: startIndexからの最短距離
// path:最短経路を保存する

void Dijkstra(const Graph& graph, std::vector<long long>& distances, int startIndex, int targetIndex, std::vector<int>& path) {

    // 流入してきた頂点を記録する配列
    std::vector<int> p(distances.size(), -1);

    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> q;
    q.emplace((distances[startIndex] = 0), startIndex);

    while (!q.empty()) {
        const long long distance = q.top().first;
        const int from = q.top().second;
        q.pop();

        if (distances[from] < distance) { continue; }

        for (const auto& edge : graph[from]) {
            const long long d = (distances[from] + edge.cost);

            if (d < distances[edge.to]) {
                p[edge.to] = from;

                q.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }

    if (distances[targetIndex] != INF) {
        for (int i = targetIndex; i != -1; i = p[i]) {
            path.push_back(i);
        }
        std::reverse(path.begin(), path.end());
    }
}