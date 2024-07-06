#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int N;cin >> N;
    vector<ll> A(N); vector<ll> B(N);
    for (int i = 0;i < N;i++) { cin >> A[i]; }
    for (int i = 0;i < N;i++) { cin >> B[i]; }
    sort(A.begin(), A.end());sort(B.begin(), B.end());
    ll ans = 0;
    for (int i = 0;i < N;i++) { ans += abs(A[i] - B[i]); };
    cout << ans << endl;
}