#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll N;
vector<ll> A;
ll sum;
bool is_ok = false;


void input() {
    cin >> N;
    A.resize(N);
    rep(i,N){
        cin >> A[i];
        sum += A[i];
    }
    rep(i,N){
        A.push_back(A[i]);
    }
}

void solve() {
    int right = 0;ll tmp_sum = 0;
    for(int left = 0;left<2*N;left++){
        while(right < 2*N && (tmp_sum + A[right])*10 <= sum) {
            tmp_sum += A[right];
            right++;
        }
        if(tmp_sum * 10 == sum){
            is_ok = true;
            break;
        }

        if(left == right)right++;
        else tmp_sum -= A[left];
    }
}

void output() {
    cout << ((is_ok) ? "Yes" : "No") << endl;
}

int main()
{
    input();
    solve();
    output();
}