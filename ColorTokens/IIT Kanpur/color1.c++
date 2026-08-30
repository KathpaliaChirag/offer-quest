#include<bits/stdc++.h>

using namespace std;

vector<int> tree(4*1e6,0);
vector<int> lazy(4*1e6,0);

void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>ue || se<us)
        return ;
    if (ss>=us && se<=ue)
    {
        tree[si] += (se-ss+1)*diff;
        if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
    tree[si] = tree[si*2+1] + tree[si*2+2];
}

void updateRange(int n, int us, int ue, int diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}


int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];
        if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return tree[si];
 
    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}


int getSum(int n, int qs, int qe)
{

    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
  
    return getSumUtil(0, n-1, qs, qe, 0);
}


vector<int> solve(vector<int>& nums,vector<vector<int> >& q){
	int n=nums.size();
	vector<int> ans;
	for(int i=0;i<q.size();i++){
		if(q[i][0]==0){
			updateRange(n,q[i][1]-1,q[i][2]-1,q[i][3]);
		}
		else{
			int low=0,high=n-1;
			int res=n-1;

			while(low <= high){
				int mid=low + ((high-low)/2);

				int temp=getSum(n,0,mid);
				//cout << temp << endl;
				if(temp >= q[i][1]){
					res=mid;
					high=mid-1;
				}
				else{
					low=mid+1;
				}
			}
			ans.push_back(res+1);

		}
	}
	return ans;
}


int main(){
	int n=5;
	vector<int> nums(n,0);
	vector<vector<int> > q;
	vector<int> temp;
	temp.push_back(0);
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(2);
	q.push_back(temp);
	vector<int> temp1;
	temp1.push_back(1);
	temp1.push_back(3);
	q.push_back(temp1);
	vector<int> temp2;
	temp2.push_back(0);
	temp2.push_back(1);
	temp2.push_back(1);
	temp2.push_back(1);
	q.push_back(temp2);
	vector<int> temp3;
	temp3.push_back(1);
	temp3.push_back(3);	
	q.push_back(temp3);
	vector<int> temp4;
	temp4.push_back(1);
	temp4.push_back(6);
	q.push_back(temp4);
	//q.push_back({1,3});
	//q.push_back({0,1,1,1});
	//q.push_back({1,3});
	//q.push_back({1,6});

	vector<int> ans=solve(nums,q);
	for(int i:ans){
		cout << i;
	}

}