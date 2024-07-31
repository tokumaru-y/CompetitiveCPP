#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll A, B, C;cin >> A >> B >> C;
    ll g = gcd(gcd(A, B), C);
    ll ans = (A / g - 1) + (B / g - 1) + (C / g - 1);
    cout << ans << endl;
}