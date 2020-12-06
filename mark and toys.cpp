#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long k;

    cin>>n>>k;

    long* arr = new long[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);

    long sum = 0;
    int c = 0;

    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum>k) break;
        c++;
    }
    cout<<c<<endl;
    return 0;
}
