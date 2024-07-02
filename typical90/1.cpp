#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool is_acceptable(int mid, int K, vector<int> dis)
{
    int cnt = 0;
    int len_sum = 0;
    for (int i = 0; i < dis.size(); i++)
    {
        len_sum += dis[i];
        if (len_sum >= mid)
        {
            len_sum = 0;
            cnt++;
        }
    }

    return cnt > K;
}

int main()
{
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> v(N);
    vector<int> dis;

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    v.push_back(L);
    dis.push_back(v[0]);
    for (int i = 0; i < N; i++)
    {
        dis.push_back(v[i + 1] - v[i]);
    }

    int is_ok = 0;
    int is_ng = L + 1;
    while ((is_ng - is_ok) > 1)
    {
        int mid = (is_ok + is_ng) / 2;
        if (is_acceptable(mid, K, dis))
        {
            is_ok = mid;
        }
        else
        {
            is_ng = mid;
        }
    }

    cout << is_ok << endl;
}
