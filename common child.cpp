#include<bits/stdc++.h>

using namespace std;

int main(){

    string s1, s2;

    cin>>s1>>s2;

    int len1 = s1.size();
    int len2 = s2.size();

    int **s = new int*[len1+1];
        for(int i=0; i<len1 + 1; i++){
            s[i] = new int [len2+1];
        }

    //int s[len1+2][len2+2]= {0};

    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            if(i==0 || j==0){
                s[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                s[i][j] = s[i-1][j-1] + 1;
            }
            else{
                s[i][j] = max(s[i-1][j],s[i][j-1]);
            }
        }
    }

    cout<<s[len1][len2]<<endl;
    return 0;

}
