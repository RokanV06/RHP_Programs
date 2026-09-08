#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;

    vector<long long> ques(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>ques[i];
        ques[i]+=ques[i-1];
    }

    while(q--){
        int a,b; cin>>a>>b;
        cout<<(ques[b]-ques[a-1])<<endl;
    }
}

//Program Link : https://cses.fi/problemset/task/1646/
