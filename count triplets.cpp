#include<bits/stdc++.h>

using namespace std;

int main(){
    long n;
    long r;
    cin>>n>>r;

    long long *arr = new long long[n+2];

    map<long, long> after;
    map<long, long>before;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    long res = 0;

    //initialize the after map
    for(int i=0; i<n; i++){
        int v = arr[i];

        if(after[v])
            after[v] += 1;
        else
            after[v] = 1;
    }

    for(int i=0;i<n;i++){
        int v = arr[i];
        after[v]-=1; // current value

        if(after[v*r] && v%r==0 && before[v/r]){
            res += after[v*r] * before[v/r]; // calculate the result c+= bef[a/r] * aft[n*r]
        }

        if(!before[v])
            before[v]=1;
        else
            before[v]+=1;
    }

    cout<<res<<endl;
    return 0;
}
