#include <iostream>
using namespace std;
int main() {
    string str;
    cin>>str;
    int L = str.length();
    for(int i=1;i<((1<<L)-1);i++){
        string k="";
        for(int j=0;j<L;j++){
            if(i & (1<<j))
            k+=str[j];
        }
        cout<<k<<endl;
    }
    return 0;
}