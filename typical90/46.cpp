#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };


int main()
{
    int N;cin >> N;
    vector<ll>A(N);vector<ll>B(N);vector<ll>C(N);
    rep(i, N)cin >> A[i];rep(i, N)cin >> B[i];rep(i, N)cin >> C[i];
    vector<int>ACnt(46, 0);    vector<int>BCnt(46, 0);
    vector<int>CCnt(46, 0);
    ll dif = 0;ll AZero = 0, BZero = 0, CZero = 0;
    for (int i = 0;i < N;i++) {
        ll a = A[i];ll b = B[i]; ll c = C[i];
        ACnt[a % 46]++;BCnt[b % 46]++;CCnt[c % 46]++;
        if (a == 0)AZero++;if (b == 0)BZero++;if (c == 0)CZero++;
    }

    ll ans = 0;
    for (int i = 0;i < 46;i++) {
        for (int j = 0;j < 46;j++) {
            for (int k = 0;k < 46;k++) {
                ll tmp = i + j + k;
                if (ACnt[i] == 0 || BCnt[j] == 0 || CCnt[k] == 0)continue;
                if (tmp % 46 == 0)ans += ACnt[i] * BCnt[j] * CCnt[k];
            }
        }
    }

    ans -= AZero * BZero * CZero;

    cout << ans << endl;
}