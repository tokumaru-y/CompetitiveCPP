#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct Edge {
    int to;
    int cost;
};

using Graph = vector<vector<int>>;
Graph graph(1 << 18, vector<int>());Graph rev_graph(1 << 18, vector<int>());

void dfs(int i, vector<bool>& used, vector<int>& vi) {
    used[i] = true;
    for (int ni : graph[i]) {
        if (used[ni] == false) dfs(ni, used, vi);
    }
    vi.push_back(i);
}

int dfs2(int i, vector<bool>& used, vector<int>& vi) {
    used[i] = true;
    int res = 0;
    for (int ni : rev_graph[i]) {
        if (used[ni] == false) res += dfs2(ni, used, vi);
    }
    res += 1;
    return res;
}


int main()
{
    int N, M;
    cin >> N >> M;
    vector<bool> seen(false, N);
    while (M > 0) {
        M--;
        int A, B; cin >> A >> B;A--;B--;
        graph[A].push_back(B);rev_graph[B].push_back(A);
    }
    vector<bool> used(N, false);vector<int> vi;
    for (int i = 0;i < N;i++) {
        if (used[i] == false)dfs(i, used, vi);
    }

    ll ans = 0;
    reverse(vi.begin(), vi.end());
    for (int i = 0;i < N; i++) used[i] = false;
    for (int ni : vi) {
        if (used[ni]) continue;
        ll cnt = dfs2(ni, used, vi);
        ans += cnt * (cnt - 1) / 2;
    }

    cout << ans << endl;

}