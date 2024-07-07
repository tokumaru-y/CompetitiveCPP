#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll a, b, c;cin >> a >> b >> c;
    ll right = a;
    ll left = 1;for (int i = 0;i < b;i++) left *= c;

    if (right < left) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}