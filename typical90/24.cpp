#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, K;cin >> N >> K;
    vector<ll> A(N);vector<ll> B(N);
    rep(i, N)cin >> A[i];
    rep(i, N)cin >> B[i];
    rep(i, N) {
        ll dif = abs(A[i] - B[i]);
        K -= dif;
        if (K < 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (K % 2 == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}