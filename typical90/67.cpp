#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
string N;
int K;

void input() {
    cin >> N >> K;
}

ll base8ToLong(string N) {
    ll res = 0;
    for (int i = 0;i < N.size();i++) {
        res = res * 8 + int(N[i] - '0');
    }
    return res;
}

string longToBase9(ll N) {
    if (N == 0) { return "0"; }
    string res;
    while (N > 0) {
        res = char(N % 9 + '0') + res;
        N /= 9;
    }
    return res;
}


void solve() {
    for (int i = 0;i < K;i++) {
        N = longToBase9(base8ToLong(N));
        for (int j = 0;j < N.size();j++) {
            if (N[j] == '8') {
                N[j] = '5';
            }
        }
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