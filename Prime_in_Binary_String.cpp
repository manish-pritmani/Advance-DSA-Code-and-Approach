// https://www.codechef.com/JAN221B/problems/PINBS

// Approach - the fundamental no. that is prime is 2 ("10") and 3("11") if any no. contains this two cominations as 0 or 1 after 1, it will be prime containing binary string. So run a loop 1 char before the string length and seach if '1' is found if found print "YES" else "NO"



#include<iostream>
using namespace std;

int main(){
    int t=0;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        int count = 0;
        int flag = 0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                cout<<"YES"<<endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
