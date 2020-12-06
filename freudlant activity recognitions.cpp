#include<bits/stdc++.h>

using namespace std;

int arr[2000001];
int freq[201] = {0};

int twiceMedian(int d){
    int sum = 0;
    for(int i =0; i<201; i++){
        sum += freq[i];

        if(2*sum > d) // for odd condition
            return (2*i);

        else if(2*sum == d){ // for even condition
            for(int j=i+1;;j++){
                if(freq[j])
                    return (i+j); // 2 * median = 2 * (i+j)/2 = (i+j)
            }
        }
    }

    // if nothing else happens
    return -1;

}

int main(){
    int n,d;
    cin>>n>>d;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int c = 0;

    for(int i = 0; i<n; i++){
        if(i>=d){
            if(arr[i]>=twiceMedian(d)){
                c++;
            }

            // remove the  previous element
            freq[arr[i-d]]--;
        }
        freq[arr[i]]++;

    }

    cout<<c<<endl;
    return 0;
}
