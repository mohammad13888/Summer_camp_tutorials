//In The Name Of God
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
 
#define pb push_back
#define endl '\n'
#define test(x) cout<<x,exit(0)
#define fast (ios_base::sync_with_stdio(false), cin.tie(NULL));

const int maxn=5010;
ll dp[2][maxn*2];
ll pre[maxn];
int n,mod;

ll pw(ll a , ll b){
	ll res=1;
	while(b){
		if(b%2){
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b/=2;
	}
	return res;
}

int main(){
	fast;
	cin>>n>>mod;
	if(n==1){
		test(0);
	}
	pre[1]=1;
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]*(i-1);
		pre[i]%=mod;
	}
	dp[1][n+1]=1;
	ll ans=0;
	for(int i=n;i>=2;i--){
		for(int j=1;j<=2*n;j++){
			dp[0][j]+=dp[1][j]*(i-1);
			dp[0][j]%=mod;
			dp[0][j-1]+=dp[1][j];
			dp[0][j+1]+=dp[1][j];
			dp[0][j-1]%=mod;
			dp[0][j+1]%=mod;
		}
		for(int j=1;j<=2*n;j++){
			dp[1][j]=dp[0][j];
			dp[0][j]=0;
		}
		ans+=pre[i-1]*dp[1][n+1]-pre[n]+mod;
		ans%=mod;
	}
	ans*=pw(2,mod-2);
	ans%=mod;
	for(int i=1;i<=n-1;i++){
		ans*=pw(i,mod-2);
		ans%=mod;
	}
	cout<<ans<<endl;
}