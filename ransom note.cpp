#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    map <string, int> m1;
    map <string, int> m2;

    string key;
    for(int i=0; i<n; i++){
        cin>>key;
        m1[key] += 1;
    }

    int c = 0;
    for(int i=0; i<m; i++){
        cin>>key;
        if(!m1[key])
            c = 0;
        else{
            c++;
            m1[key] -= 1;
        }
    }

    if(c==m){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

    return 0;

}
