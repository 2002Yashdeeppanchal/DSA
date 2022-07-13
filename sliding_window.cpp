maximum sum of all subarrays of size k

{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int k, vector<int> &arr , int n){
        int i = 0, j = 0, sum = 0, mx = INT_MIN;
       
        while(j < n)
        {
            sum = sum + arr[j];
            //dekh bhai apn ko jb tk window hit ni kr jati jb tk to j++ krte rhna hai and sum of ++ krte rhna hai then windown size hit kr jaegi jb agla element plus krna hai j++ krke or v[i] ko -- krna hai 
            if(j - i + 1 < k)
               j++;
               
            else if(j - i + 1 == k)
            {
               mx = max(mx, sum);
               sum = sum - arr[i];
               i++;
               j++;
            }
       }
       return mx;
    }
};

{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends




first negative number in every subarray of size k

maane ki jse 8 -2 -7 7 8 5
isme first subarray 8 -2 -7 to output -2 ese hi move krte rho



dekh approach ye thi ki jese jese aage move krre the na to negative element ko check krte ja rhe the and unko ek list me daalte jaare the then jb windown hit kr gyi tb list ke phla element ko ans vector me daal diya ki ye first neg element hai iss window ka then aage move krne se phle dekha ki apna v[i]==l.front() to ni hai kyuki aage move krne pr ye peeche rh jaega to usko remove kr denge list se then ese hi har window ke liye kregnge baki code pdh sb smjh javega
void solve(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long int>v(n);
        for(auto & e : v){
            cin>>e;
        }
        long long int k;
        cin>>k;
        list<long long int>l;
        vector<long long int>ans;
        long long int i=0;
        long long int j=0;
        while(j<n){
            if(v[j]<0){
                l.push_back(v[j]);
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(l.size()==0){
                    ans.push_back(0);
                    j++;
                    i++;
                }
                else{
                    ans.push_back(l.front());
                    if(v[i]==l.front()){
                        l.pop_front();
                    }
                    i++;
                    j++;
                }
            }
        }
        for(auto i : ans){
            cout<<i<<" ";
        }
        cout<<nline;
    }
}




find the all occurance of all anagram of a string in the main string

kafi shi problem thi yr mja sa aagya ek baar me code accepted ho gya "Jai Baba Bholenath" approach sunn dekh ab apn p string ke char ko map me store krre hai then ek cnt bna liya taaki map traverse na krna pde har iteration me to cnt jb zero hoga iska means hai ki map me sbhi char ki value zero ho chuki hai to window me sbhi char utni hi baar occur krre hai to ans mi include kr liya or window aage move krne se phle dekha ki apna window ka first char means s[i] apna map me lie to ni krra agr krra hai to uski value ek bdha to or cnt ko bhi ++ krdo aage ki window ke liye baki code se jyda clarify hoga so jaa code pdh neeche rha

void solve(){
    int t;
    cin>>t;
    while(t--){
        string s;
        string p;
        cin>>s>>p;
        int k=p.size();
        map<char,int>m;
        vector<bool>v(27,false);
        for(int i=0;i<p.size();i++){
            m[p[i]]++;
            v[p[i]-96]=true;
        }
        int cnt=m.size();
        debug(m);
        debug(v);
        debug(cnt);
        int i=0;
        int j=0;
        int ans=0;
        while(j<s.size()){
            if(v[s[j]-96]==true){
                if(m[s[j]]==1){
                    m[s[j]]--;
                    cnt--;
                }
                else{
                    m[s[j]]--;
                }
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(cnt==0){
                    ans++;
                }
                if(v[s[i]-96]==true){
                    m[s[i]]++;
                    if(m[s[i]]==1){
                        cnt++;
                    }
                }
                i++;
                j++;
            }
        }
        cout<<ans<<nline;
    }
}





longest substring with k unique characters

approach ye thi ki shuru me hi dekh lo ki unique char kitne hai agr k se km hue to obviously -1 return maar do ....... agr ni to ek map me count krte chlo agr map ka size k ke equal hua to apn ko ans milega then jb m.size > k ho jaega tb m[s[i]]-- chlo or dekho ki map ka size decreament hua ki ni ese hi krte chlo baaki code pdh bht acha likha hai mene :)

void solve(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        int k;
        cin>>k;
        map<char,int>st;
        bool cananslie=false;
        for(int i=0;i<n;i++){
            st[s[i]]++;
            if(st.size()>=k){
                cananslie=true;
                break;
            }
        }
        if(!cananslie){
            cout<<-1<<nline;
            continue;
        }
        st.clear();
        int mx=INT_MIN;
        int i=0;
        int j=0;
        while(j<n){
            st[s[j]]++;
            if(st.size()<k){
                j++;
            }
            else if(st.size()==k){
                mx=max(mx,(j-i+1));
                j++;
            }
            else{
                while(st.size()>k){
                    st[s[i]]--;
                    if(st[s[i]]==0){
                        st.erase(s[i]);
                    }
                    i++;
                }
            }
        }
        cout<<mx<<nline;
    }
}





longest substring with all unique characters

approach ye thi ki apn isme compare krte hai ki map ka size j-i+1(maane window size ke) iska mtlb hai ki uss window me sbhi characters unique hai isme mx krte krte ans nikal jaega.....ab easy lgne lgi hai problems or code bhi ho jata hai Bholenath Ji ki daya se "Jai Baba Bholenath" :)

void solve(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        if(n==0){
            cout<<0<<nline;
            continue;
        }
        map<char,int>st;
        int mx=INT_MIN;
        int i=0;
        int j=0;
        while(j<n){
            st[s[j]]++;
            // if(st.size()<(j-i+1)){
            //     j++;
            // }
            if(st.size()==(j-i+1)){
                mx=max(mx,(j-i+1));
                j++;
            }
            else if(st.size()<(j-i+1)){
                while(st.size()<(j-i+1)){
                    st[s[i]]--;
                    if(st[s[i]]==0){
                        st.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        cout<<mx<<nline;
    }
}
