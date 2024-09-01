#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, Q;
vector<ll>T;
vector<ll>X;vector<ll>Y;vector<ll>V;

void input() {
    cin >> N >> Q;
    T.resize(N);X.resize(N);Y.resize(N);V.resize(N);
    rep(i, N) {
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
    }
}

void solve() {}

void output() {}

int main()
{
    input();
    solve();
    output();
}