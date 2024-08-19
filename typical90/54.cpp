#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, M;
vector<vector<int>> group;
vector<vector<int>> R;
vector<int>ans;


void input() {
    cin >> N >> M;
    group.resize(N, vector<int>());
    R.resize(M, vector<int>());
    rep(i, M) {
        int K;cin >> K;
        vector<int> tmp(K);
        rep(j, K) {
            int t;cin >> t;t--;R[i].push_back(t);
            group[t].push_back(i);
        }

    }
}

void solve() {
    deque<pair<int, int>> dq;
    vector<bool> usedGroup(M, false);
    dq.push_back(make_pair(0, 0));
    ans.resize(N, -1);
    ans[0] = 0;
    while (!dq.empty()) {
        auto nx = dq.front();dq.pop_front();
        int top = nx.first;int num = nx.second;
        for (int gNum : group[top]) {
            if (usedGroup[gNum])continue;
            for (int j = 0;j < R[gNum].size();j++) {
                int nextTop = R[gNum][j];
                if (ans[nextTop] != -1)continue;

                ans[nextTop] = num + 1;
                dq.push_back(make_pair(nextTop, num + 1));
            }
            usedGroup[gNum] = true;
        }
    }
}

void output() {
    rep(i, N) {
        cout << ans[i] << endl;
    }
}



int main()
{
    input();

    solve();

    output();
}