#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, K;
ll P;
vector<ll>A;
ll ans = 0;

void input() {
    cin >> N >> K >> P;
    A.resize(N);
    rep(i, N)cin >> A[i];
}

void solve() {
    int half = N / 2;
    vector<vector<ll>>bitA(half + 1, vector<ll>());
    for (int bit = 0;bit < (1 << half);bit++) {
        ll tmp = 0;int cnt = 0;
        for (int i = 0;i < half;i++) {
            if ((bit & (1 << i))) {
                tmp += A[i];
                cnt++;
            }
        }
        bitA[cnt].push_back(tmp);
    }
    vector<vector<ll>>bitB(N - half + 1, vector<ll>());
    for (int bit = 0;bit < (1 << (N - half));bit++) {
        ll tmp = 0;ll cnt = 0;
        for (int i = 0;i < (N - half);i++) {
            if ((bit & (1 << i))) {
                tmp += A[i + half];
                cnt++;
            }
        }
        bitB[cnt].push_back(tmp);
    }
    rep(i, half + 1) { sort(bitA[i].begin(), bitA[i].end()); };
    rep(i, N - half + 1) { sort(bitB[i].begin(), bitB[i].end()); };

    for (int i = 0;i <= min(half, K);i++) {
        auto ba = bitA[i];
        for (int j = 0;j < (int)ba.size();j++) {
            ll t = ba[j];
            if (P - t < 0)continue;
            if (K - i >= bitB.size())continue;
            auto ind = upper_bound(bitB[K - i].begin(), bitB[K - i].end(), P - t) - bitB[K - i].begin();
            ans += ind;
        }
    }
}

void output() {
    cout << ans << endl;
}

int main() {
    input();
    solve();
    output();
}