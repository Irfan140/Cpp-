#include<iostream>
#include<vector>


#define mod 1000000007
#define ll long long int
using namespace std;



vector<ll> dp(1000005, -1);

ll f(int n){
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];

    ll sum = 0;
    for (int i = 1; i <= 6; i++)
    {   
        if((n - i) < 0) break;
        sum = (sum % mod +  f(n-i) % mod)%mod;
    }
    
    return dp[n] = sum%mod;
}

// bottom up solution

/*
ll fbu(int n) {
    dp[0] = 1;

    for(int k =0; k <= n; k++) {
     ll sum = 0;
    for (int i = 1; i <= 6; i++)
    {   
        if((k - i) < 0) break;
        sum = (sum % mod +  dp[k-i] % mod)%mod;
    }   
     dp[n] = sum%mod;   
    }
    return dp[n];
}
*/

int main(){
    int n;
    cin >> n;
   cout << f(n) << endl;

   return 0;
}