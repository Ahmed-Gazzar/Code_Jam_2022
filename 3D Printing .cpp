#include<iostream>
#include <vector>

using namespace std;

// function to calculate the min of a vector
int min(vector<int> s) {
    int res = s[0];
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < res) { res = s[i]; }
    }
    return res;
}


int main() {


    int t = 0;
    cin >> t;
    vector<int> res;
    int C, M, Y, K;
    for (int i = 1; i <= t; i++)
    {
        vector<int> c, m, y, kk;        // to store the c,m,y,k values of the three printers for each test case

        int k = 0;
        cin >> k;
        c.push_back(k);
        cin >> k;
        m.push_back(k);
        cin >> k;
        y.push_back(k);
        cin >> k;
        kk.push_back(k);

        cin >> k;
        c.push_back(k);
        cin >> k;
        m.push_back(k);
        cin >> k;
        y.push_back(k);
        cin >> k;
        kk.push_back(k);

        cin >> k;
        c.push_back(k);
        cin >> k;
        m.push_back(k);
        cin >> k;
        y.push_back(k);
        cin >> k;
        kk.push_back(k);


        // calc the min of each value 
        C = min(c);
        M = min(m);
        Y = min(y);
        K = min(kk);

        if ((C + M + Y + K) >= 1000000) {
            int tot = 1000000;
            res.push_back(C);
            tot -= C;
            if (tot == 0) {
                res.push_back(0);
                res.push_back(0);
                res.push_back(0);
            }
            else {
                M = min(M, tot);
                res.push_back(M);
                tot -= M;
                if (tot == 0) {
                    res.push_back(0);
                    res.push_back(0);
                }
                else {
                    Y = min(Y, tot);
                    res.push_back(Y);
                    tot -= Y;
                    res.push_back(tot);
                }
            }
            
        }
        else {
            res.push_back(-1);
            res.push_back(-1);
            res.push_back(-1);
            res.push_back(-1);
        }



    }
    for (int i = 1; i <= t; i++) {
        if (res[(i - 1)*4] == -1) {
            cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
        }
        else {
            cout << "Case #" << i << ": " << res[(i - 1) * 4] << " " << res[(i - 1) * 4 + 1] << " " << res[(i - 1) * 4 + 2] << " " << res[(i - 1) * 4 + 3] << endl;
        }
    }

}
