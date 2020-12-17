#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;

    while(q--){
        string str;
        cin>>str;
        int c=0;
        char temp = 'c';
        for(int i=0; i<str.length(); i++){
            if(str[i]==temp){
                c++;
            }
            temp = str[i];
        }
        cout<<c<<endl;
    }
    return 0;
}
