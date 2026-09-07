#include<iostream>
#include<vector>
using namespace std;
int hcf(int a,int b){
    return b==0?a:hcf(b,a%b);
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    cout<<hcf(nums[0],nums[n-1])<<" "<<endl;
}