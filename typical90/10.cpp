#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int N;cin >> N;
    vector<ll> one(N + 10, 0);vector<ll> two(N + 10, 0);
    for (int i = 0;i < N;i++) {
        int c, p;cin >> c >> p;
        one[i + 1] = one[i];
        two[i + 1] = two[i];
        if (c == 1) {
            one[i + 1] = one[i] + p;
        }
        else {
            two[i + 1] = two[i] + p;
        }
    }

    int Q;cin >> Q;
    while (Q > 0) {
        Q--;
        int L, R;cin >> L >> R;
        cout << one[R] - one[L - 1];
        cout << " ";
        cout << two[R] - two[L - 1] << endl;
    }

}