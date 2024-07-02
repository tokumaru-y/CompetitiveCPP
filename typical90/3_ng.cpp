#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// これでは二股以上に分かれている場合に予期しない挙動になるのでNG

void dfs(int top, int prev, bool reverse, vector<int>& deapth, vector<vector<int>>& AB) {
    if (reverse) {
        for (int i = 0;i < (int)AB[top].size();i++) {
            int next = AB[top][i];
            if (next == prev || deapth[next] > deapth[top] + 1) continue;
            deapth[next] = deapth[top] + 1;
            dfs(next, top, reverse, deapth, AB);
        }
    }
    else {
        bool is_all = true;
        for (int i = 0;i < (int)AB[top].size();i++) {
            int next = AB[top][i];
            if (deapth[next] != -1) continue;
            is_all = false;
            deapth[next] = 0;
            dfs(next, top, reverse, deapth, AB);
        }

        if (is_all) {
            dfs(top, -1, true, deapth, AB);
        }

    }
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> AB(N, vector<int>());
    for (int i = 0;i < N - 1;i++) {
        int a, b;cin >> a >> b;
        a--;b--;
        AB[a].push_back(b);AB[b].push_back(a);
    }

    vector<int> deapth(N, -1);
    deapth[0] = 0;
    dfs(0, -1, false, deapth, AB);

    int max = *max_element(begin(deapth), end(deapth));

    cout << max + 1 << endl;
}