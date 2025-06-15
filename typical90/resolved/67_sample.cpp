#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll K;
string N;

void input() {
    cin >> N >> K;
}

// convert ten
ll convert1(string N) {
    ll res = 0;
    ll l = N.size();
    rep(i,l){
        res = (N[i] - '0') + res * 8;
    }
    return res;
}

ll convert2(ll n_e) {
    ll res = 0;
    ll i = 1;
    while (n_e > 0) {
        res += (n_e % 9) * i;
        n_e /= 9;
        i *= 10;
    }
    return res;
}

string convert3(ll n_n) {
    string res = "";
    while (n_n > 0) {
        auto t = (n_n % 10) + '0';
        if(t == '8')t='5';
        res += t;
        n_n /= 10;
    }
    reverse(res.begin(), res.end());
    bool is_trim = false;
    int i=0;
    while(!is_trim) {
        if(res[i] == '0') {
            i++;
        } else {
            is_trim = true;
            if(i > 0 ) {
                res = res.substr(i);
            }
        }
    }
    return res;
}

void solve() {
    if(N == "0") {
        return;
    }
    rep(i,K){
        ll n_e = convert1(N);
        ll n_n = convert2(n_e);
        string n_c = convert3(n_n);
        N = n_c;
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