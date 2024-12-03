#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
string S;
ll ans = 0;

void input() {
    cin >> N;
    cin >> S;
}

void solve() {
    int right = 0;
    int o_cnt =0;int x_cnt =0;
    for(int left = 0;left < N; left++){
        while(right < N && (o_cnt == 0 || x_cnt == 0)) {
            if(S[right] == 'x'){
                x_cnt++;
            } else {
                o_cnt++;
            }
            right++;
        }
        if(x_cnt > 0 && o_cnt > 0){
            ans += N - right + 1;
        }
        if(left == right){
            right++;
        } else {
            if(S[left] == 'x') {
                x_cnt--;
            } else {
                o_cnt--;
            }
        }
    }
}

void output() {
    cout << ans << endl;
}

int main()
{
    input();
    solve();
    output();
}