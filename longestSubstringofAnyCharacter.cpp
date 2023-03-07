/*
    कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥
 
    Karmanye vadhikaraste Ma Phaleshu Kadachana,
    Ma Karmaphalaheturbhurma Te Sangostvakarmani,
 
    The meaning of the verse is :—
    You have the right to work only but never to its fruits.
    Let not the fruits of action be your motive, nor let your attachment be to
   inaction
*/
#include <math.h>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>

#define ll long long int
#define endl "\n"
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define MOD 998244353
// cout <<setprecision(15)
#define NEED_FOR_SPEED      \
      ios_base::sync_with_stdio(false); \
      cin.tie(NULL);                    \
      cout.tie(NULL)
using namespace std;

ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
ll mod_sub(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a - b) % mod) + mod) % mod;
}
int poww(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return ans;
}
class DisjointSet{
        vector<ll> rank,parent,size;
        public:
        DisjointSet(ll n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++)parent[i]=i;
        }
        
        ll findUpar(ll node)
        {
            if(node==parent[node]) return node;
            return parent[node]=findUpar(parent[node]);
        }
        
        void urank(ll u, ll v)
        {
            ll ulp_u=findUpar(u);
            ll ulp_v=findUpar(v);
            if(ulp_u==ulp_v)return;
            if(rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u])
            {
                parent[ulp_v]=ulp_u;
            }
            else
            {
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
        
        void usize(ll u, ll v)
        {
            ll ulp_u=findUpar(u);
            ll ulp_v=findUpar(v);
            if(ulp_u==ulp_v)return;
            if(size[ulp_u]<size[ulp_v])
            {
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else
            {
                 parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
                
        }
    };

void solve()
{
    string s="abccccc";
    int i=0,j=0;
    int ans=1;
    unordered_map<int, int>mp;
    while(j<s.size())
    {
        mp[s[j]]++;
        if(mp.size()==1)
        {
            ans=max(ans,j-i+1);
        }
        if(mp.size()>1)
        {
            while(mp.size()>1)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    cout << ans;
}
 
signed main()
{
      NEED_FOR_SPEED;
      // cout << setprecision(15);
      int t = 1;
      //cin >> t;
      while (t--)
      {
            solve();
            // cout << endl;
      }
}
