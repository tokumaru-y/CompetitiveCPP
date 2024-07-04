//ref: https://drken1215.hatenablog.com/entry/2021/10/10/195200
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> calc_next(const string& S) {
    int N = (int)S.size();

    vector<vector<int>> res(N + 1, vector<int>(26, N));

    for (int i = N - 1;i >= 0;i--) {
        res[i] = res[i + 1];

        res[i][S[i] - 'a'] = i;
    }

    return res;
}


int main()
{
    int N, K;string S;
    cin >> N >> K >> S;

    string res = "";
    auto nex = calc_next(S);

    int j = -1;
    for (int i = 0;i < K;i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            int k = nex[j + 1][c - 'a'];

            if (N - k >= K - i) {
                res += c;
                j = k;
                break;
            }
        }
    }

    cout << res << endl;
}