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
    if (N == 0) {
        return "0";
    }

    string res;
    while (N > 0) {
        res = char((N % 9) + '0') + res;
        N /= 9;
    }
    return res;
}


void solve() {
    while (K > 0) {
        N = longToBase9(base8ToLong(N));
        for (int i = 0;i < N.size();i++) {
            if (N[i] == '8') {
                N[i] = '5';
            }
        }
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