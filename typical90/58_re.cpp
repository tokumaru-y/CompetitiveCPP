#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll N, K;
vector<int>timeStamp;
vector<int>nextPos;
int ans;


void input() {
    cin >> N >> K;
}

int digitSum(int x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve() {
    const int mod = 100000;
    timeStamp.resize(mod, -1);
    nextPos.resize(mod);
    rep(i, mod) {
        nextPos[i] = (i + digitSum(i)) % mod;
    }

    int now = N;int cnt = 0;
    while (timeStamp[now] == -1) {
        timeStamp[now] = cnt;
        now = nextPos[now];
        cnt++;
    }

    int cycle = cnt - timeStamp[now];
    if (K >= timeStamp[now])K = (K - timeStamp[now]) % cycle + timeStamp[now];

    rep(i, mod) {
        if (timeStamp[i] == K)ans = i;
    }
}

void output() {
    cout << ans << endl;
}

int main()
{
    input();
    solve();
    output();
}