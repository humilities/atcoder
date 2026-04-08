#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,cnt=0;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cnt+=i;
	}

	cout<<cnt<<endl;

	return 0;
}