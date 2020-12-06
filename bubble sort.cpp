#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    long* arr = new long[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    long c = 0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                c++;
            }
        }
    }

    cout<<"Array is sorted in "<<c<<" swaps."<<endl;
    cout<<"First Element: "<<arr[0]<<endl;
    cout<<"Last Element: "<<arr[n-1]<<endl;
    return 0;
}
