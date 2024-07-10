#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll A, B, C;cin >> A >> B >> C;
    ll a = gcd(A, B);
    ll gg = gcd(a, C);
    ll ans = (A / gg - 1) + (B / gg - 1) + (C / gg - 1);

    cout << ans << endl;
}