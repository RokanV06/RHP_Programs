#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int A,B,Q;
    cin>>A>>B>>Q;
    vector<long long>S(A),T(B);
    for(int i=0;i<A;i++){
        cin>>S[i];
    }
    for(int i=0;i<B;i++){
        cin>>T[i];
    }
    const long long INF=1e18;
    while(Q--){
        long long x;
        cin>>x;
        int i=lower_bound(S.begin(),S.end(),x)-S.begin();
        int j=lower_bound(T.begin(),T.end(),x)-T.begin();
        vector<long long>s={
            i>0 ? S[i-1]:-INF,
            i<A ? S[i]:INF
        };
        vector<long long>t={
            j>0 ? T[j-1]:-INF,
            j<B ? T[j]:INF
        };
        long long ans=INF;
        for(long long a:s){
            for(long long b:t){
                ans=min(ans,abs(x-a)+abs(a-b));
                ans=min(ans,abs(x-b)+abs(b-a));
            }
        }
        cout<<ans<<endl;
    }
}
