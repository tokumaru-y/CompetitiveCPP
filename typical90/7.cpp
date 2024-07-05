#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int N;cin >> N;
    vector<ll> A(N);for (int i = 0;i < N;i++) cin >> A[i];
    int Q;cin >> Q;
    sort(A.begin(), A.end());

    for (int i = 0;i < Q;i++) {
        int B;cin >> B;
        auto iter = lower_bound(A.begin(), A.end(), B);
        int dist_from_last = iter - A.begin();

        int f = abs(B - *iter);
        if (dist_from_last == 0) {
            cout << f << endl;
            continue;
        }
        iter--;
        int e = abs(B - *iter);
        int ans = min(f, e);
        cout << ans << endl;

    }
}