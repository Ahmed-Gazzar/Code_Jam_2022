#include <iostream>
#include <vector>
using namespace std;

void l1(int c){
    for(int i=0;i<c;i++){
        cout << "+-";
    }
    cout << "+" << endl;
}
void l2(int c){
    for(int i=0;i<c;i++){
        cout << "|.";
    }
    cout << "|" << endl;
}

int main() {
    int t;
    cin >> t;
    vector<int> rr,cc;
    for(int i=0;i<t;i++){
        int x;
        cin >> x;
        rr.push_back(x);
        cin >> x;
        cc.push_back(x);
    }
    
    for(int i=0;i<t;i++){
        int r = rr[i];
        int c = cc[i];
        cout << "Case #" << i+1 << ":" << endl;
        
        cout << ".." ;
        l1(c-1);
        cout << ".." ;
        l2(c-1);
        l1(c);
        
        for(int x=1 ; x < r ; x++){
            l2(c);
            l1(c);
        }
        
        
        
    }
    

    return 0;
}