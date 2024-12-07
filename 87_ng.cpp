#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
ll N,P,K;
vector<vector<ll>> A(70, vector<ll>(70,0));
vector<vector<ll>> dist(70,vector<ll>(70,0));

void input() {
    cin >> N >> P >> K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)cin >> A[i][j];
    }
}

int count_number(long long lens) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] == -1) dist[i][j] = lens;
			if (A[i][j] != -1) dist[i][j] = A[i][j];
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (dist[i][j] <= P) cnt++;
		}
	}
	return cnt;
}
ll get_boader(ll cnts) {
    long long cl = 1, cr = 5000000000LL, cm, minx = 5000000000LL;
    for(int i=0;i<40;i++){
        cm = (cl + cr) / 2LL;
        ll res = count_number(cm);
        if(res <= cnts) { cr = cm; minx = min(minx, cm);}
        else { cl = cm; }
    }
    return minx ;
}

void solve() {
    ll L = get_boader(K);
    ll R = get_boader(K-1);
    if(R - L >= 2000000000LL) cout << "Infinity" << endl;
    else cout << R - L << endl;
}

void output() {}

int main()
{
    input();
    solve();
    output();
}