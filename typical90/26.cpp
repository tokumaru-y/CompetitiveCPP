#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void dfs(int v, vector<int>& variable, vector<bool>& seen, vector<vector<int>>& graph, int varia) {
    variable[v] = varia;
    for (auto nv : graph[v]) {
        if (seen[nv]) continue;
        seen[nv] = true;
        dfs(nv, variable, seen, graph, (varia + 1) % 2);
    };
    return;
}


int main()
{
    int N;cin >> N;
    vector<vector<int>> graph(N, vector<int>());
    rep(i, N - 1) {
        int A, B;cin >> A >> B;
        A--;B--;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    int v = 0;
    vector<int> variable(N, -1);
    vector<bool> seen(N, false);
    rep(i, N) {
        if (seen[i])continue;
        seen[i] = true;
        v = (v + 1) % 2;
        dfs(i, variable, seen, graph, v);
    }

    ll one_cnt = 0;ll zero_cnt = 0;
    rep(i, N) {
        if (variable[i] == 1) {
            one_cnt++;
        }
        else {
            zero_cnt++;
        }
    }
    int limit = N / 2;
    if (one_cnt > zero_cnt) {
        rep(i, N) {
            if (variable[i] == 1) {
                cout << i + 1 << " ";limit--;
            }
            if (limit == 0) break;

        }
    }
    else {
        rep(i, N) {
            if (variable[i] == 0) {
                cout << i + 1 << " ";limit--;
            }
            if (limit == 0) break;

        }
    }
    cout << endl;
}