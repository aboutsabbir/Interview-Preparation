#include<bits/stdc++.h>

using namespace std;

// set prime numbers as key as no multiple of two primes are same
void get_prime_no(int *prime){

    int c = 0;
    int i,j;

    for(i=2; i<100000; i++){
        for(j=2; j<=i; j++){
            if(i%j==0) break;
        }
        // if the number is divisible by only itself then its a prime
        if(i==j) prime[c++]=i;

        if(c==26) break;

    }
}

int main(){

    int *prime = new int[26]; // dinamically allocated prime array
    get_prime_no(prime);

    string str;

    int t;
    cin>>t;

    while(t--){
        cin>>str;
        int ch;
        int range; // for substring length
        long key = 1; // to be multiplied

        int res = 0;
        int len = str.length();

        unordered_map<long, int> m;
        unordered_map<long, int> ::iterator it;

        for(int i=1; i<= len; i++){
            for(int j=0; j<=len-i; j++){ // important to subtract i

                range = i+j-1; // range of the substring
                key = 1;

                for(int k =j; k<= range; k++){
                    ch = str[k] - 97; //get integer value of character
                    key = ((prime[ch]*key)%10000000007);
                }

                m[key]+=1; // map the key
            }
        }

        for(it = m.begin(); it!=m.end(); it++){
            int val = it->second;
            if(val>=2){
                res += ((val) * (val-1))/2;
                // no of distinct substring = n(n-1)/2
                // no of substring = n(n+1)/2
            }
        }
        cout<<res<<endl;
    }


    return 0;
}
