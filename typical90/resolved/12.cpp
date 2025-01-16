#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };
int H,W,Q;
bool grid[20002010];
struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        for (int i = 0;i < N;i++)par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
UnionFind uf(20002010);

ll make_index(int x, int y){
    return (10000 * x) + (y); 
}


void input() {
    cin >> H >> W >> Q;
    rep(i,Q){
        int t;cin >> t;
        int ax,ay; cin >> ax >> ay;
        ll ind = make_index(ax,ay);
        if(t==1){
            rep(k,4){
                grid[ind] = true;
                ll candidate = make_index(dx[k] + ax,dy[k] + ay);
                if(candidate >= 20002010 || candidate <= 0)continue;
                if(grid[candidate])uf.unite(candidate,ind);
            }
        } else {
            int bx,by;cin >> bx >> by;
            ll n_ind = make_index(bx,by);
            if(grid[ind] && grid[n_ind] && uf.same(ind,n_ind)){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}

void solve() {}

void output() {}

int main()
{
    input();
    solve();
    output();
}