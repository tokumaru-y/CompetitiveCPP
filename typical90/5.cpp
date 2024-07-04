#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int N, K;
    cin >> N >> K;
    string S;

    cin >> S;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    vector<char> alphav(alphabet.begin(), alphabet.end());
    vector<char> ans;

    int next_start_index = 0;
    int test_cnt = 0;
    while ((int)ans.size() < K) {
        int tmp_index;
        char min = 'z' + 1;
        for (int i = next_start_index;i < (N - K + (int)ans.size() + 1);i++) {
            if (S[i] < min) {
                min = S[i];
                tmp_index = i;
            }
            test_cnt++;
        }
        next_start_index = tmp_index + 1;
        ans.push_back(S[tmp_index]);
    }

    cout << test_cnt << endl;

    for (auto a : ans) {
        cout << a;
    }
    cout << endl;

}