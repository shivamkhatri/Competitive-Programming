//
// Created by shkhatri on 11/17/2018.
//
#include<bits/stdc++.h>
using namespace std;

int tweetIdxArray[1001];

int main() {

    int n , k;
    cin>>n>>k;
    string cmdName;
    int tweetNo;
    int lastCloseIdx = 0;

    int count = 0;

    for(int i = 1 ; i <= k ; i++){
        cin>>cmdName;

        if(cmdName == "CLOSEALL"){
            lastCloseIdx = i;
            count = 0;
        }
        else{

            cin>>tweetNo;

            if(tweetIdxArray[tweetNo] <= lastCloseIdx){
                tweetIdxArray[tweetNo] = i;
                count++;
            }
            else{
                tweetIdxArray[tweetNo] = 0;
                count--;
            }
        }

        cout<<count<<endl;
    }

    return 0;
}

