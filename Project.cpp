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

const int maxn=1e5+10;
const int inf=1e5;
vector<int>divs[maxn];
ll res[maxn];
int cnt[maxn];
ll dp[maxn];
ll sum[maxn];
int arr[maxn];
ll ans=0;

int main(){
	fast;
	for(int i=1;i<maxn;i++){
		for(int j=i;j<maxn;j+=i){
			divs[j].pb(i);
		}
	}
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		cnt[arr[i]]++;
		for(int j=0;j<divs[arr[i]].size();j++){
			res[divs[arr[i]][j]]++;
		}
	}
	for(int i=inf;i>=1;i--){
		dp[i]=res[i]*(res[i]-1)/2;
		for(int j=2*i;j<maxn;j+=i){
			dp[i]-=dp[j];
		}
	}
	
	for(int i=1;i<=inf;i++){
		ans+=dp[i]*cnt[i];
	}
	
	for(int i=1;i<=inf;i++){
		ans-=(ll)(cnt[i])*(cnt[i]-1);
	}
	for(int i=1;i<=inf;i++){
		for(int j=i*2;j<maxn;j+=i){
			ans-=(ll)(cnt[i])*cnt[j];
		}
	}

	for(int i=1;i<=inf;i++){
		res[i]=0;
		dp[i]=0;
	}
	ll dif;
	for(int i=n;i>=1;i--){
		ans-=dp[arr[i]];
		for(int j=0;j<divs[arr[i]].size();j++){
			res[divs[arr[i]][j]]++;
		}
		for(int j=divs[arr[i]].size()-1;j>=0;j--){
			dif=dp[divs[arr[i]][j]];
			dp[divs[arr[i]][j]]=res[divs[arr[i]][j]]*(res[divs[arr[i]][j]]-1)/2-sum[divs[arr[i]][j]];
			dif=dp[divs[arr[i]][j]]-dif;
			for(int k=0;k<divs[divs[arr[i]][j]].size()-1;k++){
				sum[divs[divs[arr[i]][j]][k]]+=dif;
			}	
		}
	}

	for(int i=1;i<=n/2;i++){
		swap(arr[i],arr[n-i+1]);
	}
	for(int i=1;i<=inf;i++){
		res[i]=0;
		sum[i]=0;
		dp[i]=0;
	}
	for(int i=n;i>=1;i--){
		ans-=dp[arr[i]];
		for(int j=0;j<divs[arr[i]].size();j++){
			res[divs[arr[i]][j]]++;
		}
		for(int j=divs[arr[i]].size()-1;j>=0;j--){
			dif=dp[divs[arr[i]][j]];
			dp[divs[arr[i]][j]]=res[divs[arr[i]][j]]*(res[divs[arr[i]][j]]-1)/2-sum[divs[arr[i]][j]];
			dif=dp[divs[arr[i]][j]]-dif;
			for(int k=0;k<divs[divs[arr[i]][j]].size()-1;k++){
				sum[divs[divs[arr[i]][j]][k]]+=dif;
			}	
		}
	}
	test(ans);
}