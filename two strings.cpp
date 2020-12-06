#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    string str1, str2;

    while(t--){
        map <char, int> m;
        cin>>str1>>str2;

        for(int i=0; i<str1.size(); i++){
            m[str1[i]] += 1;
        }

        int flag = 0;

        for (int i=0; i<str2.size(); i++){
            if(m[str2[i]]) flag++;
        }

        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
