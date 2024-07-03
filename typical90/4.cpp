#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int H, W;cin >> H >> W;
    vector<vector<int>> B(H, vector<int>(W));
    for (int i = 0;i < H;i++) {
        for (int j = 0;j < W;j++) {
            cin >> B[i][j];
        }
    }
    vector<int> h_sum(H, 0);vector<int> w_sum(W, 0);
    vector<vector<int>> ans(H, vector<int>(W));
    for (int h = 0;h < H;h++) {
        for (int w = 0;w < W;w++) {
            h_sum[h] += B[h][w];
            w_sum[w] += B[h][w];
        }
    }

    for (int i = 0;i < H;i++) {
        for (int j = 0;j < W;j++) {
            ans[i][j] = h_sum[i] + w_sum[j] - B[i][j];
        }
    }

    for (auto a : ans) {
        for (int i = 0;i < a.size();i++) {
            cout << a[i] << " ";
            if (i == W - 1) {
                cout << endl;
            }
        }
    }
}