#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll N;
vector<vector<ll>> dp;
vector<ll>L,R;
long double ans = 0;

void input() {
    cin >> N;
    dp.resize(N + 1, vector<ll>(110, -1));
    L.resize(N + 1, 0);
    R.resize(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }
}

void solve() {
    rep(i,N-1){
        ll al = L[i];
        ll ar = R[i];
        for(int j=i+1;j<N;j++){
            ll bl = L[j];
            ll br = R[j];
            long double total = (ar - al + 1) * (br - bl + 1);
            long double cnt = 0;
            for(ll k=al;k <= ar; k++){
                if(k <= bl)continue;
                cnt += min(k-1, br) - bl + 1;
            }
            if(cnt == 0)continue;
            ans += cnt / total;
        }
    }
}

void output() {
    cout << fixed << setprecision(10) << ans << endl;
}

int main()
{
    input();
    solve();
    output();
}