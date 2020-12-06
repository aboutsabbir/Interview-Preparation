#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;

    cin>>n>>m;

    // dynamically allocate the memory as n may extend 10^7
    long long *arr = new long long[n+2]; // add n+2 as we will access (b+1) index

    int a, b, k;
    while(m--){
        cin>>a>>b>>k;
        arr[a] += k;    // add to the position 'a;
        arr[b+1] -= k; // subtract from the position 'b+1'
    }

    long long top = 0; // as the size of k is 10^9
    int temp;
    for(int i=1; i<=n; i++){
        arr[i] += arr[i-1];
        top = max(arr[i], top);
    }

    cout<<top<<endl;
    return 0;
}
