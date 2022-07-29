#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    
    int t = 0;
    cin >> t;
    vector<int> res;

    for (int ii = 1; ii <= t; ii++)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int z;
            cin >> z;
            v.push_back(z);
        }
        sort(v.begin(), v.end());
        int r = 1;
        for (int i = 1; i < n; i++)
        {
            if (r < v[i]) { r++; }
        }
        res.push_back(r);

    }
    
    
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << res[i-1] << endl;
    }

    
    
    
    
}