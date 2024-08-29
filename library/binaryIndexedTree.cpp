
using ll = long long;
// ref: https://hos.ac/slides/20140319_bit.pdf
struct BIT {
private:
    int N;
    vector<ll>bit;
public:
    BIT(int n) {
        N = n;
        bit.resize(N + 1, 0);
    }

    void add(int a, int w) {
        for (int x = a;x <= N;x += (x & -x))bit[x] += w;
    }

    ll sum(int a) {
        ll res = 0;
        for (int x = a;x > 0;x -= (x & -x))res += bit[x];
        return res;
    }
};