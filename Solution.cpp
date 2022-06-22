#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;


int main() {


    int t;
    cin >> t;
    vector<string> res(1, "0");

    for (int tt = 1; tt <= t; tt++) {

        string s,result="";
        cin >> s;
        s += "A";
        for (size_t i = 0; i < s.size()-1; i++)
        {
            char a = s[i], b = s[i + 1];
            if (a == b) {
                char c = '0';
                for (size_t ii = i + 2; ii < s.size(); ii++)
                {
                    if (s[ii] != b) { c = s[ii]; break; }
                }
                if (c == '0') {
                    result += s.substr(i, s.size() - i - 1);
                    break;
                }
                else {
                    if (c > b) {
                        result += a;
                    }
                    result += a;
                }

            }
            else {
                if (a < b) {
                    result += a;
                }
                result += a;
            }
            
        }






        res.push_back(result);
    }



    for (int ii = 1; ii <= t; ii++) {
        cout << "Case #" << ii << ": " << fixed << setprecision(9) << res[ii] << endl;
    }

}