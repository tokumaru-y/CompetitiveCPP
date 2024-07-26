#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;cin >> N;
    vector<vector<int>> A(N, vector<int>(N, 0));
    rep(i, N) {
        rep(j, N) {
            int a;cin >> a;
            A[i][j] = a;
        }
    }

    int M;cin >> M;
    vector<vector<int>> ng_list(N, vector<int>());
    rep(i, M) {
        int x, y;cin >> x >> y;
        x--;y--;
        ng_list[x].push_back(y);ng_list[y].push_back(x);
    }
    vector<int> order;rep(i, N) { order.push_back(i); };
    int ans = 1 << 26;
    do {
        bool is_ok = true;
        rep(i, N - 1) {
            int a = order[i];int b = order[i + 1];
            if (find(ng_list[a].begin(), ng_list[a].end(), b) != ng_list[a].end()) {
                // found ng element
                is_ok = false;
                break;
            }
        }
        if (is_ok) {
            int tmp_sum = 0;
            rep(i, N) { tmp_sum += A[order[i]][i]; };
            ans = min(ans, tmp_sum);
        }
    } while (next_permutation(order.begin(), order.end()));

    if (ans == 1 << 26) { cout << -1 << endl; }
    else { cout << ans << endl; }
}