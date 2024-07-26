#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, K;cin >> N >> K;vector<ll> A(N);
    rep(i, N)cin >> A[i];
    int left = 0;int right = 0;
    int kind_cnt = 0;int ans = 0;int tmp_cnt = 0;
    unordered_map<int, int>table;
    while (right < N) {
        if (table.count(A[right]) != 0) {
            table[A[right]]++;
            tmp_cnt++;
        }
        else {
            kind_cnt++;
            table[A[right]] = 1;
            tmp_cnt++;
            while (kind_cnt > K) {
                tmp_cnt -= 1;
                table[A[left]] -= 1;
                if (table[A[left]] == 0) {
                    table.erase(A[left]);
                    kind_cnt -= 1;
                }
                left++;
            }
        }
        ans = max(ans, tmp_cnt);
        right++;
    }

    cout << ans << endl;
}