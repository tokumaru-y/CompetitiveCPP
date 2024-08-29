#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N, K;
ll ans = 0;

void input() {
    cin >> N >> K;
}

void solve() {
    while (K > 0) {
        ll tmp = 0;
        vector<ll>divList;
        while (N > 0) {
            ll div = N % 9;
            N /= 9;
            divList.push_back(div);
        }
        ll cnt = 1;
        for (int i = 0;i < divList.size();i++) {
            tmp += divList[i] * cnt;
            cnt *= 9;
        }
        ll cTmp = tmp;
        int tCnt = 1;
        while (cTmp > 0) {
            ll divCTmp = cTmp % 10;
            if (divCTmp == 8) {
                tmp -= 3 * tCnt;
            }
            cTmp /= 10;
            tCnt *= 10;
        }
        N = tmp;
        K--;
    }
}

void output() {
    cout << N << endl;
}

int main()
{
    input();
    solve();
    output();
}