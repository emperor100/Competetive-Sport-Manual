/*
  An Emperor100 Production
  Everyone is permitted to copy and distribute verbatim copies
  of this code, but changing it is not allowed.
*/

#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)
#define pool(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define um unordered_map

typedef long long ll;

ll MOD = 1e9+7;

ll power(ll x, ll y){ll temp;if( y == 0)return 1;temp = power(x, y/2)%MOD;if (y%2 == 0)return (temp%MOD*temp%MOD)%MOD;else{if(y > 0)return (x%MOD*temp%MOD*temp%MOD)%MOD;else return (temp*temp)/x;}}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    
    int t;
    cin>>t;
    
    while(t--)
    {
        
        
        
        
    }
    
    
    return 0; 
}


