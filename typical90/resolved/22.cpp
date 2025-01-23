#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
unsigned long long A,B,C;
unsigned long long ans;

void input() {
    cin >> A >> B >> C;
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
    if(a < b){
        unsigned long long tmp = b;
        b = a;
        a = tmp;
    }
    if(a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}
void solve() {
    unsigned long long a = gcd(A,B);
    unsigned long long b = gcd(a,C);
    if(b == 1 ){
        ans = A + B + C - 3;
    } else {
        ans += A / b - 1;
        ans += B / b - 1;
        ans += C / b - 1;
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