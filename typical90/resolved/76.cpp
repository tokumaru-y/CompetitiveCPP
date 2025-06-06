#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll MOD = 1000000007;
ll N;
vector<ll> A;
vector<ll> B;
ll total = 0;
string answer = "No";

void input() {
    cin >> N;
    A.resize(N);
    B.resize(N);
    rep(i, N) {cin >> A[i];B[i] = A[i];total += A[i];}
    rep(i,N)B.push_back(A[i]);
}

void solve() {
    int left = 0;int right = 1;
    int length = 1;
    ll sum = B[0];
    bool continueFlag = true;
    while(continueFlag){
        while(length < N && (right < B.size())&& sum * 10 < total){
            sum += B[right];
            right++;
            length++;
        }
        if(sum * 10 == total){
            answer = "Yes";
            continueFlag = false;
        }
        if(left >= B.size()){
            continueFlag = false;
            break; 
        }

        if(left == right) {
            right++;
            sum += B[right];
            length++;
        } else {
            sum -= B[left];
            left++;
            length--;
        }
    }
}

void output() {
    cout << answer << endl;
}

int main()
{
    input();
    solve();
    output();
}