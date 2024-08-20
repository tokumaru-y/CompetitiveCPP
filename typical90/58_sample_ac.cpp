#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll N, K;
int ans = 0;

void input() {
    cin >> N >> K;
}

int digit_sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve() {
    const int mod = 100000;
    vector<int>nxt(mod);
    rep(i, mod) {
        nxt[i] = (i + digit_sum(i)) % mod;
    }

    vector<int>timeStamp(mod, -1);
    int pos = N, cnt = 0;
    while (timeStamp[pos] == -1) {
        timeStamp[pos] = cnt;
        pos = nxt[pos];
        ++cnt;
    }

    int cycle = cnt - timeStamp[pos];
    if (K >= timeStamp[pos]) {
        K = (K - timeStamp[pos]) % cycle + timeStamp[pos];
    }

    ans = -1;
    rep(i, mod) {
        if (timeStamp[i] == K) {
            ans = i;
        }
    }

    cout << ans << endl;
}

void output() {
    return;
}

int main()
{
    input();
    solve();
    output();
}