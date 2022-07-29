#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    
    int t = 0;
    cin >> t;
    vector<int> res;

    for (int ii = 1; ii <= t; ii++)  // looping over each test case
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int z;
            cin >> z;
            v.push_back(z);         // recording the dices of the current test case
        }
        
        /*
        -   to form a straight, it is a safe move to take the 1 from the smallest dice 
            and the 2 from the second smallest dice ... etc.
        -   if the dice does not contain the desired value of the straight 
            just skip it and move on to the next bigger dice
        */
                
        sort(v.begin(), v.end());   // sorting the dices by their no. of sides
        
        int r = 1;                  // first value in the straight
        for (int i = 1; i < n; i++)
        {
            if (r < v[i]) { r++; }  // if the dice contain it, take it. if not, skip it.
        }
        res.push_back(r);           // r now is the largest value of the straight 

    }
    
    
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << res[i-1] << endl;
    }

    
    
    
    
}
