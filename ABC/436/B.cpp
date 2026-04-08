// #include<bits/stdc++.h>

// using namespace std;

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	int n;
// 	cin>>n;

// 	vector<vector<int>> ma(n,vector<int>(n));
// 	ma[0][(n-1)/2]=1;
	
// 	int x=-1%n;
// 	int y=((n-1)/2+1)%n;
// 	int k=1;

// 	while(!ma[x][y]){
// 		ma[x][y]=++k;

// 		x=(x-1)%n;
// 		y=(y+1)%n;

// 		if(ma[x][y]){
// 			int x=(x+1)%n;

// 			ma[x][y]=++k;
// 		}
// 	}

// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			cout<<ma[i][j]<<" ";
// 		}

// 		cout<<endl;
// 	}

// 	return 0;
// }



#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> ma(n, vector<int>(n, 0));
    int x = 0, y = (n - 1) / 2; 
    ma[x][y] = 1;

    for (int k = 2; k <= n * n; k++) {
       
        int nx = (x - 1 + n) % n;
        int ny = (y + 1) % n;

        if (ma[nx][ny] == 0) {
            x = nx;
            y = ny;
        } else {
            x = (x + 1) % n;
        }

        ma[x][y] = k;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ma[i][j]<<endl;
        }
        cout << endl;
    }

    return 0;
}