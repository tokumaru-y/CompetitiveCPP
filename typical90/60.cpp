#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<int>A;
vector<int>LIS1;
vector<int>LIS2;
vector<int> ans1;
vector<int>ans2;
int MAX_NUM = 5000000;


void input() {
    cin >> N;
    rep(i, N) {
        int a;cin >> a;A.push_back(a);
    }
}

void solve() {
    LIS1.resize(N + 1, MAX_NUM);LIS2.resize(N + 1, MAX_NUM);
    ans1.resize(N + 1);ans2.resize(N + 1);
    rep(i, N) {
        int target = A[i];
        auto ind = lower_bound(LIS1.begin(), LIS1.end(), target) - LIS1.begin();
        LIS1[ind] = target;
        ans1[i] = ind + 1;
    }
    for (int i = N - 1;i >= 0;i--) {
        int target = A[i];
        auto ind = lower_bound(LIS2.begin(), LIS2.end(), target) - LIS2.begin();
        LIS2[ind] = target;
        ans2[i] = ind + 1;
    }
}

void output() {
    int t = 0;
    rep(i, N) {
        t = max(t, ans1[i] + ans2[i] - 1);
    }
    cout << t << endl;
}

int main()
{
    input();
    solve();
    output();
}