#include<bits/stdc++.h>
using namespace std;


int lazy[1000111];
int segTree[1000111];


int query(int s, int e, int l, int r, int root)
{
    
    if(lazy[root]==1)
    {
        segTree[root] = (e-s+1) - segTree[root];
        
        if(s!=e)
        {
            lazy[2*root+1] = 1 - lazy[2*root+1];
            lazy[2*root+2] = 1 - lazy[2*root+2];
        }
        
        lazy[root]=1;
        
        
    }
    
    if(s>r || e < l)
        return 0;
        
    if(s>=l && e<=r)
    
    {
        return segTree[root];
    }
    
    int mid = (s+e)/2;
    
    return query(s, mid, l, r, root*2+1) + query(mid+1, e, l, r, root*2+2);
    
    
}


void update(int s, int e, int l, int r, int root)
{
    
     if(lazy[root]==1)
    {
        segTree[root] = (e-s+1) - segTree[root];
        
        if(s!=e)
        {
            lazy[2*root+1] = 1 - lazy[2*root+1];
            lazy[2*root+2] = 1 - lazy[2*root+2];
        }
        
        lazy[root]=1;
        
        
    }
    
      if(s>r || e < l)
        return ;
    
        
     if(s>=l && e<=r)
    
    {
        segTree[root] = (e-s+1) - segTree[root];
        if(s!=e)
        {
            lazy[2*root+1] = 1 - lazy[2*root+1];
            lazy[2*root+2] = 1 - lazy[2*root+2];
        }
        return;
    }
    
    int mid=(s+e)/2;
    
    update(s, mid, l, r, root*2+1);
    update(mid+1, e, l, r, root*2+2);
    
    segTree[root] = segTree[2*root+1] + segTree[2*root+2];
    
    
}



int main()
{
    
    int n;
    cin>>n;
    
    
    int q;
    cin>>q;
    
    
    while(q--)
    {
        int type;
        cin>>type;
        
        if(type == 1)
        {
            
            int l, r;
            cin>>l>>r;
            
            cout<<query(0, n-1, l, r, 0)<<endl;
            
        }
        
        else 
        {
            int l, r, add;
            
            cin>>l>>r;
            
            update(0, n-1, l, r, 0);
            
            
        }
        
    }
    
    
    return 0;
}
