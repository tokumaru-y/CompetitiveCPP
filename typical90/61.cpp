#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int Q;
vector<pair<int, int>>TX;
deque<int> dq;
vector<int> ans;


void input() {
    cin >> Q;
    TX.resize(Q);
    rep(i, Q) {
        int t, x;cin >> t >> x;
        TX[i] = make_pair(t, x);
    }
}

void solve() {
    for (auto tx : TX) {
        int t = tx.first, x = tx.second;
        if (t == 1) {
            dq.push_front(x);
        }
        else if (t == 2) {
            dq.push_back(x);
        }
        else {
            ans.push_back(dq[x - 1]);
        }
    }
}

void output() {
    rep(i, ans.size())cout << ans[i] << endl;
}

int main()
{
    input();
    solve();
    output();
}