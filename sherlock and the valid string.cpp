#include<bits/stdc++.h>

using namespace std;

int main(){
    string str;

    cin>>str;

    int arr[26] = {0};

    for(int i=0; i<str.length(); i++){
        arr[str[i]-'a'] += 1; // map the character value
    }

    map<int, int> m;
    map<int, int> ::iterator itr;

    for(int i=0; i<26; i++){
        m[arr[i]] += 1;  // copy the occurrances of the values in the map
    }

    // find maximum and minimum keys
    int maxk = 0;
    int mink = 1000000;

    int k = 0;
    for(itr = m.begin(); itr!= m.end(); itr++){
        if(maxk < itr->first){
            maxk = itr->first;
        }
        if(mink > itr->first && itr->first != 0){
            mink = itr->first;
        }

        if(m[itr->first] && itr->first != 0)
        {
            k++; // count the no of distinct keys
            //cout<<"K: "<<k<<endl<<"itr:"<<itr->first<<endl;
        }
    }


    if((maxk - mink)==0){
        // if max(k) - min(k) == 0 then there is only one key
        cout<<"YES"<<endl;
    }
    else if(k<3 && (((maxk-mink)==1 && m[maxk]==1) || (mink == 1 && m[mink]==1)) ){
        // number of distinct keys should be less than 3
        // max(k)-min(k) == 1, that means there is two consecutive keys and if m[max(k)]==1 occurs once then we can subtract it
        // min(k) == 1, and if it occurs only once m[min(k)]==1 then we can subtract the minimum key
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
