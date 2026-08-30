import java.util.*;

class main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int[][] qry = new int[q][3];
        for(int i=0;i<q;i++){
            qry[i][0] = sc.nextInt();
            qry[i][1] = sc.nextInt();
            qry[i][2] = sc.nextInt();
        }

        SGTTree sg = new SGTTree(n);
        sg.build(arr, 0, n-1, 0);
        // System.out.println(sg.query(0, 0, n-1, 3, 4));
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0;i<qry.length;i++){
            int type = qry[i][0];
            int a = qry[i][1];
            int b = qry[i][2];
            if(type == 1){
                sg.update(0,0,n-1,a-1,b);
            }else{
                int val = 0;
                for(int k=a-1;k<b;k++){
                    for(int j=k;j<b;j++){
                        int value = sg.query(0,0,n-1,k,j);
                        val += value;
                        // System.out.println(type + " " + k + " " + j);
                        // System.out.println(value);
                    }
                }
                list.add(val);
            }
        }
        for(int i=0;i<list.size();i++){
            System.out.println(list.get(i));
        }
        

    }
}

class SGTTree {
    static int[] st;
    public SGTTree(int n){
        st = new int[4 * n];
        Arrays.fill(st,-1);
    }
    public void update(int ind, int lo,int hi, int i, int val){
        if(lo == hi){
            st[ind] = val;
            return;
        }
        int mid = lo + (hi - lo)/2;
        if(i<=mid){
            update(2*ind+1,lo,mid,i,val);
        }else{
            update(2*ind+2,mid+1,hi,i,val);
        }
        st[ind] = st[2*ind + 1] + st[2*ind + 2];
        
    }
    public int query(int ind, int lo, int hi, int l, int r){
        //no overlap
        if(r < lo || hi < l)return 0;
        
        //Complete overlap
        if(l <= lo && hi <= r){
            return st[ind];
        }
        //partial overlop
        int mid = lo + (hi-lo)/2;
        int left = query(2*ind+1,lo,mid,l,r);
        int right = query(2*ind+2,mid+1,hi,l,r);
        return left + right;
        
    }
	public void build(int arr[], int lo, int hi, int ind) 
	{ 
		if (lo == hi){
			st[ind] = arr[lo];
			return;
		}
		int mid = lo + (hi - lo)/2;
		build(arr, lo, mid, ind * 2 + 1);
		build(arr, mid + 1, hi, ind * 2 + 2);
		
		st[ind] = st[2*ind + 1] + st[2*ind + 2];
	}
    public int get(int i){
        return st[i];
    }
}

