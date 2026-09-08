#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ultimate leader of the node will be returned
int find(vector<int>& ldr, int node){
    if(ldr[node]!=node) ldr[node]=find(ldr, ldr[node]);
    return ldr[node];
}

//ultimate leader to the leftside val will be assigned as the leader to the rightside val
void join(vector<int>& ldr, int lt, int rt){
    int ldrlt=find(ldr,lt);
    int ldrrt=find(ldr,rt);
    ldr[ldrrt]=ldrlt;
}

int main(){
    int n,m; cin>>n>>m;
    vector<int> ldr(n+1);
    vector<int> leaders(n+1);

    //initially leader of that node is node itself
    for(int i=1;i<=n;i++){
        ldr[i]=i;
    }

    //assigning leaders to the right values (as their left ones)
    for(int e=1;e<=m;e++){
        int lt,rt; cin>>lt>>rt;
        leaders[e]=lt;
        join(ldr, lt,rt);
    }

    vector<long long int> gcnt(n+1,0), ecnt(n+1,0);

    for(int i=1;i<=n;i++){
        int x=find(ldr, i); //final leader 
        gcnt[x]++;          //that final leader val will be incremented
    }
    
    //we r calculating how many edges r there in the group.
    for(int i=1;i<=n;i++){
        int x=leaders[i];   //left-side values from the input
        ecnt[x]++;          //this is done by incrementing that val belonging to index=leader position               
    }

    long long int sum=0;
    for(int i=1;i<=n;i++){
        int ncnt=gcnt[i];   //size of the group or no of nodes
        int totalEdges=(ncnt*(ncnt-1))/2;
        int existingEdges=(ecnt[i]);

        sum+=totalEdges-existingEdges;  //remaining edges or frnship bonds that can be formed
    }

    cout<<sum<<endl;
    return 0;
}
