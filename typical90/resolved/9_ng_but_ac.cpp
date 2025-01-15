#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int N;
vector<double> X,Y;
double ans = 0;

void input() {
    cin >> N;
    rep(i,N){
        double x,y;cin >> x >> y;
        X.push_back(x);Y.push_back(y);
    }
}

void solve() {
    rep(i,N){
        double ax = X[i];double ay = Y[i];
        vector<double> R;
        rep(j,N){
            if(i==j)continue;
            double bx=X[j];double by=Y[j];
            double angle = atan2(by-ay,bx - ax);
            double degree = angle * 180.0 / 3.14159265358979;
            if(degree < 0){
                degree = 360.0 + degree;
            }
            R.push_back(degree);
        }
        sort(R.begin(),R.end());
        rep(j,N-1){
            double target = R[j] + 180.0;
            if(target >= 360.0){
                target -= 360.0;
            }
            auto iter = lower_bound(R.begin(), R.end(), target);
            int candidate_ind1 = (iter - R.begin()) % R.size();
            int candidate_ind2 = ((iter - R.begin()) + R.size() - 1) % R.size();

            double tmp1 = abs(R[j] - R[candidate_ind1]);
            if(tmp1>=180.0)tmp1 = 360.0-tmp1;
            double tmp2 = abs(R[j] - R[candidate_ind2]);
            if(tmp2>=180.0)tmp2=360.0-tmp2;
            double tmp = max(tmp1,tmp2);
            ans = max(ans, tmp);
        }
    }
}

void output() {
    printf("%.12lf\n", ans);
}

int main()
{
    input();
    solve();
    output();
}