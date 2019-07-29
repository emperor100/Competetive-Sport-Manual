/*

We are using priority_queue<> For printing multiplication of 3 maximum numbers in a running stream of nubers

*/


 

#include<bits/stdc++.h>

using namespace std;

class Element
{
  long elem;
  
  public:
  
  int getElement()
  {
      
      return this->elem;
  }
  
  void setElement(long ele)
  {
      this->elem = ele;
  }
    
    
};


class Comparator
{
    
  public:
  
  bool operator() (Element  e1, Element e2)
  {
      return e1.getElement() < e2.getElement();
      
  }
    
};




void solve()
{
    
    priority_queue<Element, vector<Element>, Comparator> prQ;
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        Element E;
        
        long number;
        
        cin>>number;
        
        E.setElement(number);
        
        prQ.push(E);
        
        if(i<2) /// Since top three elements are required. Therefore we are printing -1 for first 2 elements.
        cout<<"-1"<<endl;
        
        else 
        
        
        
        {
            Element first = prQ.top();
            prQ.pop();
            Element second = prQ.top();
            prQ.pop();
            Element third = prQ.top();
            
            prQ.push(first);
            prQ.push(second);
            
            
            
            Element answer;
            answer.setElement(first.getElement() * second.getElement()* third.getElement());
            
            cout<<answer.getElement()<<endl;
            
            
        }
        
        
    }
    
    
}

int main()
{
    
    solve();
    
    return 0;
}


