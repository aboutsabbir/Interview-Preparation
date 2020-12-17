#include<bits/stdc++.h>

using namespace std;

int main(){
    map<char, int> a;
    map<char, int> ::iterator itr;

    string s1, s2;

    cin>>s1>>s2;

    for(int i=0; i<s1.length(); i++){
        a[s1[i]] += 1;
    }

    int c = 0;

    for(int i=0; i<s2.length(); i++){
        if(a[s2[i]]){
            a[s2[i]] -= 1;
        }
        else c++; // if does not exist delete the char
    }

    for(itr = a.begin(); itr != a.end(); itr++){
        c+= itr->second; // delete characters from s1
    }

    cout<<c<<endl;

    return 0;
}
