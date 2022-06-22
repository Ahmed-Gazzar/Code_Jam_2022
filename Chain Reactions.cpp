#include<iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector<long long> f;
vector<long long> p;
vector<long long> pointed_at;
vector<vector<long long>> pointers;
vector<long long> res;
long long trace(int x) {
    long long max = f[x];
    while (x < f.size()) {
        if (pointers[x].size() == 0) { break; }
        x = pointers[x][0];
        if (max < f[x]) { max = f[x]; }
    }
    return max;
}
long long mi(vector<long long> v) {
    long long min = v[0], ii = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (min > v[i]) { min = v[i]; ii = i; }
    }
    return ii;
}
long long sum(vector<long long> v) {
    long long res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        res += v[i];
    }
    return res;
}
int main() {


    int t = 0;
    cin >> t;
    res = vector<long long>(t + 1, 0);
    for (int ii = 1; ii <= t; ii++)
    {
        int n;
        cin >> n;
        f = vector<long long>(n + 1, 0);
        p = vector<long long>(n + 1, 0);
        pointed_at = vector<long long>(n + 1, 0);
        pointers = vector<vector<long long>>(n + 1);
        for (int i = 1; i <= n; i++)
        {
            long long z;
            cin >> z;
            f[i] = z;
        }
        for (int i = 1; i <= n; i++)
        {
            long long z;
            cin >> z;
            p[i] = z;
            pointed_at[p[i]]++;
            pointers[p[i]].push_back(i);
        }

        for (int i = n; i >= 0; i--)
        {
            if (pointed_at[i] > 1) {
                vector<long long> v(pointed_at[i]);
                long long min_i = pointers[i][0];
                long long min = trace(pointers[i][0]);
                for (int x = 0; x < pointed_at[i]; x++)
                {
                    v[x] = trace(pointers[i][x]);
                    if (min > v[x]) { min = v[x]; min_i = pointers[i][x]; }
                }
                res[ii] += sum(v);
                res[ii] -= min;
                pointed_at[i] = 1;
                pointers[i] = { min_i };
            }
        }
        long long next = pointers[0][0];
        long long max = f[pointers[0][0]];
        for (int i = next; i <= n; i = next)
        {
            if (pointers[i].size() == 0) { break; }
            if (max < f[pointers[i][0]]) { max = f[pointers[i][0]]; }
            next = pointers[i][0];
            if (max < f[pointers[i][0]]) { max = f[pointers[i][0]]; }
        }
        res[ii] += max;
    }

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << res[i] << endl;
    }

}
