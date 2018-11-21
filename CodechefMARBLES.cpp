//
// Created by shkhatri on 11/19/2018.
//
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<int,int> > primeFactors[1000001];
map<ll,ll> numFactorMap;

int Array[1000001];

void primeFactorsCalculator(){

    for(int i = 0 ; i < 1000001; i++){
        Array[i] = i;
    }

    for( int i = 2; i < 1000001 ; i++){

        for( int j = i ; j  < 1000001 ; j += i ){
            int count = 0;

            while( Array[j] % i == 0 ){
                Array[j] /= i;
                count++;
            }
            if(count > 0){
                primeFactors[j].emplace_back(i , count);
            }
        }

    }
}

ll powx( ll a , ll b ){
    ll result = 1;
    while(b--){
        result *= a;
    }
    return result;
}

int main(){
    primeFactorsCalculator();

    int t;
    cin>>t;

    int n , k;
    while(t--){
        numFactorMap.clear();
        cin>>n>>k;
        ll ans = 1;
        n--,k--;
        int sTimes = min( k , (n-k));
        int lTimes = max( k , (n - k));

        for( int i = n ; i > lTimes ; i--){
            for (auto &j : primeFactors[i]) {
                numFactorMap[j.first] += j.second;
            }
        }

        for(int i = 2 ; i <= sTimes ; i++){
            for (auto &j : primeFactors[i]) {
                if(numFactorMap[j.first]){
                    numFactorMap[j.first] -= j.second;
                }
            }
        }

        map<ll,ll>::iterator it;

        for(it = numFactorMap.begin(); it != numFactorMap.end(); ++it){
            if( it->second <= 0 )
                continue;
            ans *= powx(it->first, it->second);
        }

        cout<<ans<<endl;
    }
}
