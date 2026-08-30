#include<bits/stdc++.h>
using namespace std;
int match=0;

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int m,n;

void solve(vector<vector<int>> &rectangle,vector<vector<int>> &visited,int r,int c,int pr, int pc ){

	for(int i=0;i<4;i++){
		int nr=r+dr[i];
		int nc=c+dc[i];
		//cout<<nr<<" "<<nc<<endl;
		if(nr<0 or nr>=m or nc<0 or nc>=n or rectangle[nr][nc]==1){
			continue;}
		if(nr!=pr and nc!=pc){
			solve(rectangle,visited,nr,nc,r,c);
		}
	}

	
	if(pr!=-1 and pc!=-1 and !visited[r][c] and !visited[pr][pc] and rectangle[r][c]==0 and rectangle[pr][pc]==0){
		//cout<<"Hello"<<endl;
		visited[r][c]=1;
		visited[pr][pc]=1;
		cout<<r<<" "<<c<<" "<<pr<<" "<<pc<<endl;
		match++;
	}




}
int main()
{
	//int m,n;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>m>>n;
	vector<vector<int>> rectangle(m,vector<int> (n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){

			cin>>rectangle[i][j];

		}
	}
	vector<vector<int>> visited(m,vector<int> (n,0));
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j)
		{
			/* code */
			if(rectangle[i][j]==0 and visited[i][j]==0){
							solve(rectangle,visited,i,j,-1,-1);

			}
		}
	}
	{
		/* code */
	}
	
	// for(int i=0;i<m;i++){
	// 	for(int j=0;j<n;j++){

	// 		cout<<visited[i][j]<<" ";

	// 	}
	// 	cout<<endl;
	// }
	cout<<match<<endl;



	return 0;
}