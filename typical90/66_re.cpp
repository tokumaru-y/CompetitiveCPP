#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<int>L;
vector<int>R;
double ans = 0.0;


void input() {
    cin >> N;
    rep(i, N) {
        int l, r;cin >> l >> r;
        L.push_back(l);R.push_back(r);
    }
}

void solve() {
    rep(i, N) {
        for (int j = i + 1;j < N;j++) {
            int cnt = 0;int all = 0;
            for (int k = L[i];k <= R[i];k++) {
                for (int s = L[j];s <= R[j];s++) {
                    if (k > s)++cnt;
                    all++;
                }
            }
            ans += double(cnt) / all;
        }
    }
}

void output() {
    cout.precision(15);
    cout << fixed << ans << endl;
}

int main()
{
    input();
    solve();
    output();
}