#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<int>L;
vector<int>R;


void input() {
    cin >> N;
    rep(i, N) {
        int l, r;cin >> l >> r;
        L.push_back(l);R.push_back(r);
    }
}

void solve() {
    double expsum = 0.0;
    for (int i = 0;i < N;i++) {
        for (int j = i + 1;j < N;j++) {
            int cnt = 0;int all = 0;
            for (int k = L[i]; k <= R[i];k++) {
                for (int l = L[j];l <= R[j];l++) {
                    if (k > l)++cnt;
                    ++all;
                }
            }
            expsum += double(cnt) / all;
        }
    }

    cout.precision(15);
    cout << fixed << expsum << endl;

}

void output() {}

int main()
{
    input();
    solve();
    output();
}