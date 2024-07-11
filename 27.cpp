#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;cin >> N;
    unordered_set<string> table;
    rep(i, N) {
        string S;cin >> S;
        auto res = table.find(S);
        if (res == table.end()) {
            cout << i + 1 << endl;
        }
        table.insert(S);
    }

}