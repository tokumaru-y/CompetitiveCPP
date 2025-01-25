#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N,K;
bool isPrime[10000001]{};
int primeCount[10000001]{};
ll ans = 0;

void eratosthenes(){
    rep(i,10000001){isPrime[i]=true;primeCount[i]=0;}
    isPrime[0]=false;isPrime[1]=false;
    for(int i=2;i<=N;i++){
        if(!isPrime[i])continue;
        for(int j=i+i;j<=N;j+=i){
            isPrime[j]=false;
        }
    }
}

void input() {
    cin >> N >> K;
    eratosthenes();
}

void solve() {
    for(int i=0;i<=N;i++){
        if(!isPrime[i])continue;
        for(int j=i;j<=N;j+=i)primeCount[j]+=1;
    }

    for(int i=0;i<=N;i++){
        if(primeCount[i] >=K)ans++;
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