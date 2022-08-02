                    /*Jai Baba Bholenath*/

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
// #define int long long
const int MOD=1e9+7;
#define ll long long
#define all(v) v.begin(),v.end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
typedef unsigned long long ull;
typedef long double lld;
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*--------------------------------------------------------------------------------------------------------------------------*/
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
bool isPrime(ll n){   if (n <= 1)return false;    for (int i = 2; i <= sqrt(n); i++)  if (n % i == 0)  return false;    return true;}
/*--------------------------------------------------------------------------------------------------------------------------*/

bool canplace(vector<int> &arr,int n,int c,int mid){
    debug(arr);
    int cordinate=arr[0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if((arr[i]-cordinate)>=mid){
            cordinate=arr[i];
            cnt++;
        }
        if(cnt==c)return true;
    }
    return false;
}

void solve(){
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        vector<int>arr(n);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto &e : arr){
            cin>>e;
            maxi=max(maxi,e);
            mini=min(mini,e);
        }
        
        sort(all(arr));
        
        int begin=1;
        int over=maxi-mini;

        int ans=-1;

        while(begin<=over){
            int mid=begin+(over-begin)/2;
            // cout<<"mid "<<mid<<endl;
            if(canplace(arr,n,c,mid)){
                begin=mid+1;
                ans=mid;
            }
            else{
                over=mid-1;
            }
        }

        cout<<ans<<nline;
    }
}   
 
int32_t main()
{
    // #ifdef Yashdeep
	// freopen("Error.txt", "w", stderr);
    // #endif
	// fastio();
	// solve();
    // #ifdef Yashdeep
	// cerr << "Time: " << duration . count() / 1000 << endl;
    // #endif

    fastio();
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif
    solve();
    #ifndef ONLINE_JUDGE
    #endif
    return 0;
}
