#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;


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

void Dijkstra(const Graph& graph, std::vector<long long>& distances, int startIndex) {


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

                q.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }
}
int main()
{
    int N, M;cin >> N >> M;
    Graph graph(N + 10, vector<Edge>());
    for (int i = 0;i < M;i++) {
        int a, b, c;cin >> a >> b >> c;
        a--;b--;
        graph[a].push_back({ to: b, cost : c });
        graph[b].push_back({ to: a, cost : c });
    };

    vector<ll> distannce_from_one(N + 10, INF);
    distannce_from_one[0] = 0;
    Dijkstra(graph, distannce_from_one, 0);

    vector<ll> distance_from_N(N + 10, INF);
    distance_from_N[N - 1] = 0;
    Dijkstra(graph, distance_from_N, N - 1);


    for (int i = 0;i < N;i++) {
        cout << distannce_from_one[i] + distance_from_N[i] << endl;
    }
}