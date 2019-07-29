
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



int tree[1055555][26]={};
int node=0;
int res[1055555]={};

void insert(string s)
{
    int root=0;
    for(int i=0;i<s.size();i++){
            
            if(tree[root][s[i]-'a']==0)
            tree[root][s[i]-'a'] = ++node;
            
            root = tree[root][s[i]-'a'];
            res[root]++;
    }
    
}



int query(string s)
{
    int root = 0;
    
    
    
    for(int i=0;i<s.size();i++)
    {
        
            
        if(tree[root][s[i]-'a']!=0)
            root = tree[root][s[i]-'a'];
            
        else return 0;
        
    }
    
    return res[root];
    
}



int main()
{
    
    int n, q;
    cin>>n>>q;
    
    while(n--)
    {
        
        string s;
        cin>>s;
        
        insert(s);
        
    }
    
    while(q--)
    {
        string s;
        cin>>s;
        cout<<query(s)<<endl;
    }
    
    return 0;
}


/*
 Sample input
 
 12 6
bulldog
dog
dogged
doggedly
doggerel
dogma
dogmatic
dogmatism
dogs
catastroph
catastroph
doctor
cat
dog
dogg
do
doctrinography
dogge

 Sample output
 
2
8
3
9
0
3

*/


