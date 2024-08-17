#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };

int main()
{
    int N, K;cin >> N >> K;
    vector<pair<ll, ll>> AB;
    rep(i, N) {
        int a, b;cin >> a >> b;
        AB.push_back(make_pair(b, a));
    }
    priority_queue<pair<ll, int>> pq;
    sort(AB.rbegin(), AB.rend());
    rep(i, N) {
        ll a = AB[i].first;
        pq.push(make_pair(a, i));
    }
    ll ans = 0;
    while (K > 0) {
        auto tmp = pq.top();pq.pop();
        ans += tmp.first;
        K--;
        if (tmp.second == -1)continue;
        pq.push(make_pair(AB[tmp.second].second - tmp.first, -1));
    }
    cout << ans << endl;
}