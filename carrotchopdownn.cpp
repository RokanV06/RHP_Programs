#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    vector <int> size(n);
    for(int i=0;i<n;i++){
        cin>>size[i];
    }
    vector<int> alter;
    for(int i=0;i<n;i++){
        int x=size[i];
        while(x>k){
            alter.push_back(k);
            x-=k;
        }
        if(x>0){
            alter.push_back(x);
        }
    }
cout<< alter.size();
}