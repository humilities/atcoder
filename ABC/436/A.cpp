#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  string s;
  
  cin>>n>>s;
  
  int len=s.size();
  
  if(len==n){
    cout<<s<<endl;
  }
  else{
    string re;
    for(int i=0;i<n-len;i++){
      re+='o';
    }
    
    cout<<re+s<<endl;
  }
  
  return 0;
}