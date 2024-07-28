#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    else {
        return gcd(b, a % b);
    }
}

ll lcm(ll a, ll b, ll gcd) {
    return a / gcd * b;
}

int main()
{
    ll A, B;cin >> A >> B;
    ll gcdnum = gcd(A, B);
    if (A / gcdnum > 1000000000000000000 / B) {
        cout << "Large" << endl;
    }
    else {
        cout << lcm(A, B, gcdnum) << endl;
    }
}