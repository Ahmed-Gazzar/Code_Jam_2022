#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

vector<int> generate(int n) {

    vector<int> v(2 * n);
    int x = 1;
    v[0] = 0;
    cout << v[0] << " ";

    if (n <= 30) {
        for (size_t i = 1; i < n - 1; i++)
        {
            v[i] = x;
            cout << v[i] << " ";
            x = x * 2;
        }
        v[n - 1] = x;
        cout << v[n - 1] << endl;
    }
    else {
        for (size_t i = 1; i < 30; i++)
        {
            v[i] = x;
            cout << v[i] << " ";
            x = x * 2;
        }
        x = 3;
        for (size_t i = 30; i < n - 1; i++)
        {
            v[i] = x;
            cout << v[i] << " ";
            x = x + 2;
        }
        v[n - 1] = x;
        cout << v[n - 1] << endl;
    }



    return v;
}

vector<int> recieve(vector<int>v, int n) {
    for (size_t i = n; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
    }
    return v;
}

long long sum(vector<int> v) {
    long long sum = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}

void output(vector<int> v) {
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " ";
    }
    cout << v[v.size() - 1] << endl;
}

int main() {


    int t;
    cin >> t;


    for (int tt = 1; tt <= t; tt++) {

        int n;
        cin >> n;
        vector<int> v;
        v = generate(n);
        v = recieve(v, n);
        long long half = sum(v) / 2;



        int ii = 2 * n - 1;
        vector<int> res;
        long long sum = 0;

        while (1) {

            if (sum + v[ii] <= half) {
                res.push_back(v[ii]);
                sum += v[ii];
            }

            if (sum == half) {
                break;
            }

            ii--;

        }

        output(res);


    }



}