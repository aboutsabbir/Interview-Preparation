#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string str;

    cin>>n>>str;

    int len=str.size();

    int left[len]={0};
    int right[len]={0};

    //initialize first elements of the two arrays
    left[0]=1;
    right[n-1] = 1; // cause it starts from the right side

    for(int i=1; i<len; i++){
        if(str[i]==str[i-1]){
            left[i] = left[i-1] + 1;
        }
        else{
            left[i]++;
        }
    }

    for(int i = len-2; i>=0; i--){
        if(str[i]==str[i+1]){
            right[i] = right[i+1] + 1;
        }
        else{
            right[i]++;
        }
    }

    // main calculation
    int c = 0; //count

    for(int i=0; i<n; i++){
        c++;
        if(i>0 && i<(len - 1)){
            if(str[i-1]==str[i+1] && str[i]!=str[i-1]){
                c += min(left[i-1], right[i+1]);
            }
            else if(str[i]==str[i-1]){
                c += left[i] - 1;
            }
        }

        if(i==len-1 && str[i]==str[i-1]){
            c += left[i] - 1;
        }
    }

    cout<<c<<endl;

    return 0;

}
