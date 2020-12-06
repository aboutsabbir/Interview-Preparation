#include<bits/stdc++.h>

using namespace std;

int main(){
    long q;
    cin>>q;

    unordered_map<long long, long long> ele;
    unordered_map<long long, long long> freq;

    while(q--){
        int a;
        long b;
        cin>>a>>b;

        if(a==1){
            // insert in the map
            if(!ele[b]){
                // if there is no element in the first map
                ele[b] += 1;
                freq[ele[b]] += 1;
            }
            else{
                // if there exist a element in the first map
                freq[ele[b]] -= 1; // reduce from the second
                ele[b] += 1;        // increase in the first map
                freq[ele[b]] += 1; // increase in the second
            }

        }
        else if(a==2){
            // subtract frequency from map
            if(ele[b]){
                freq[ele[b]] -= 1; // reduce from the second map first
                ele[b] -= 1; // reduce from the element map then
                freq[ele[b]] += 1; // update the new value
            }

        }
        else if(a==3){
            // show the number of frequency
            if(freq[b]) cout<<1<<endl;
            else cout<<0<<endl;

        }
    }

    return 0;
}
