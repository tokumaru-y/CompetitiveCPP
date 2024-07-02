#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool is_acceptable(vector<char> tmp) {
    int left = 0;
    for (int i = 0; i < tmp.size();i++) {
        if (tmp[i] == '(') {
            left++;
        }
        else {
            if (left == 0) {
                return false;
            }
            left -= 1;
        }
    }

    return left == 0;
}

int main()
{
    int N;
    cin >> N;
    if (N % 2 == 1) {
        return 0;
    }
    vector<string> candidate;
    for (int b = 0; b < (1 << N); b++)
    {
        vector<char> tmp;

        for (int i = 0; i < N; i++) {
            if ((b & (1 << i)) > 0)
            {
                tmp.push_back(')');
            }
            else
            {
                tmp.push_back('(');
            }
        }

        if (is_acceptable(tmp))
        {
            string str(tmp.begin(), tmp.end());
            candidate.push_back(str);
        }
    }

    sort(candidate.begin(), candidate.end());

    for (int i = 0;i < candidate.size(); i++) {
        cout << candidate[i] << endl;
    }
}