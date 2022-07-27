#include <iostream>
#include <vector>
using namespace std;

// a function to generate +-+-+-+ sequence
void l1(int c){
    for(int i=0;i<c;i++){
        cout << "+-";
    }
    cout << "+" << endl;
}

// a function to generate |.|.|.|.|.| sequence
void l2(int c){
    for(int i=0;i<c;i++){
        cout << "|.";
    }
    cout << "|" << endl;
}

int main() {
    int t;
    cin >> t;
    vector<int> rr,cc;   // to store the rows and coloumns of the test set
    
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
        
        // generating the first tow lines manually cause it has a special beginning
        cout << ".." ;
        l1(c-1);
        cout << ".." ;
        l2(c-1);
        
        // generating the rest of the punched card 
        // noticing that we start with +-+-+-+ and also end with it
        // so i printed the first +-+-+-+ line the the rest are in the loop
        l1(c);
        
        for(int x=1 ; x < r ; x++){
            l2(c);
            l1(c);
        }
        
        
        
    }
    

    return 0;
}
