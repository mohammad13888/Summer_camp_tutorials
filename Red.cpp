//In the name of God
#include<bits/stdc++.h>
/*MHN*/
using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair<lli,lli> pii;
typedef pair<pii,pii> piiii;
typedef vector<lli> ve;
typedef vector<pii> vp;
const lli N=4e5+100;
const lli mod=1e9+7;//998244353;//1e9+9
const lli INF=1e18;
lli power(lli x,lli y){lli res = 1;x = x % mod;while(y>0){if( y & 1 ){res = (res * x) % mod;}y = y >> 1;x = (x * x)%mod;}return res;}
lli modinv(lli x){return power(x,mod-2);}
lli divide(lli x,lli y){return ((x%mod) * modinv(y))%mod;}
#define all(v) v.begin(),v.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define migmig ios_base::sync_with_stdio(false),cout.tie(0), cin.tie(0);
#define read freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define minheap priority_queue<pair<lli,pii>, std::vector<pair<lli,pii>>, std::greater<pair<lli,pii>>>
#define set_preci(x) cout << fixed << setprecision(x);
#define debug(x) cerr << (#x) << " " << (x) << endl
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define SUM(v) accumulate(v.begin(),v.end(), 0LL)
#define FOR(x,n) for(lli x = 0; x < n; x++)
#define FORS(x,n) for(lli x = 1; x <= n; x++)
#define TEST int TQPWIEJR; cin>>TQPWIEJR;while(TQPWIEJR--)
#define BN(l,a) while(l){a.PB(l%2);l/=2;}
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define sep " "
lli tmp;
lli n;
pii A[N];
lli dp[N];
int main(){
    migmig;
	cin>>n;
	FORS(i,n){
		lli l,r;
		cin>>l>>r;
		A[i] = MP(l,r);
	}	
	n ++;
	A[n] = {0,0};
	sort(A+1,A+n+1,[](pii a,pii b){
		if(a.se < b.se)return 1;
		if(b.se < a.se)return 0;
		if(a.fi < b.fi)return 1;
		return 0;		
	});
	dp[1] = 0;
	for(lli i = 2; i <= n; i ++){
		lli mxl = 0;
		lli cnt = 0;
		bool boo = 0;
		for(lli j = i-1; j > 1; j --){
			if(A[j].fi >= A[i].fi && A[j].se <= A[i].se){
				cnt ++;
				continue;
			}
			if(A[i].fi > A[j].se)
				mxl = max(mxl,A[j].fi);
			if(A[j].se >= mxl){
				dp[i] = (dp[i] + dp[j]*power(2,cnt))%mod;
			}
			else{
				dp[i] = (power(2,j-1)*power(2,cnt)+dp[i])%mod;
				boo = 1;
				break;	
			}
		}
		if(boo == 0 && i > 2 && A[2].se < A[i].fi)dp[i] = (power(2,cnt)+dp[i])%mod;
		/*debug(A[i].fi);
		debug(A[i].se);
		debug(dp[i]);
		cerr<<endl;*/
	}
	lli ans = 0;
	lli mxl = 0;
	lli cnt = 0;
	for(lli i = n ;i > 1 ;i --){
		mxl = max(A[i].fi,mxl);
		if(mxl > A[i].se){cnt = 1;ans = (ans + power(2,i-1))%mod;break;}
		else ans = (ans + dp[i])%mod;
	}
	ans += 1-cnt;
	ans %= mod;
	ans = (power(2,n-1)-ans + mod)%mod;
	cout<<ans<<endl;
}
