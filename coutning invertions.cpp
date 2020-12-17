#include<bits/stdc++.h>

using namespace std;

long mergeTwo(long arr[], long temp[], int l, int m, int r){
    int i,j,k;
    long c = 0;

    i = l; // i is the index for left subarray
    j = m; // j is the index for right subarray
    k = l; // k is the index of resultant subarray

    while((i<=m-1)&&(j<=r)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];

            // if arr[j] > arr[i] then there will be (m-i) convertions
            c += (m-i);
        }
    }

    // copy the remaining elements
    while(i<= m-1){
        temp[k++] = arr[i++];
    }

    while(j<=r){
        temp[k++] = arr[j++];
    }

    // copy the merged element to the original array
    for(i = l; i<= r; i++){
        arr[i] = temp[i];
    }

    return c;
}


long _mergeSort(long arr[], long temp[], int l, int r){
    int m;
    long c = 0; // c = inversion count

    if(r > l){
        //mid
        m = (l+r)/2;

        c += _mergeSort(arr, temp, l, m);
        c += _mergeSort(arr, temp, m+1, r);

        // merge the two parts
        c+= mergeTwo(arr, temp, l, m+1, r);
    }
    return c;
}


long mergeSort(long arr[], long temp[], int n){

    int l = 0;
    int r = n-1;

    return _mergeSort(arr, temp, l, r);
}

int main(){
    int d;
    cin>>d;

    while(d--){
        int n;
        cin>>n;

        long* arr = new long[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        long temp[n];

        long ans = mergeSort(arr, temp, n);
        cout<<ans<<endl;

    }

    return 0;
}
