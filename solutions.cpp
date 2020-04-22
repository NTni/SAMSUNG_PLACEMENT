//1.ENDOSCOPE(done)
#include<iostream>
using namespace std;
#define l long long
struct list
{
    int x;
    int y;
};
list q[1000001];
l arr[1001][1001];
l visited[1001][1001];
bool up(l x,l y,l t,l len)
{
    if(t<0 || arr[x][y]==0 || arr[t][y]==0 || visited[x][y]==len || visited[t][y]!=0)
        return 0;
    if((arr[x][y]==1||arr[x][y]==2||arr[x][y]==4||arr[x][y]==7 )&&(arr[t][y]==1||arr[t][y]==2||arr[t][y]==5||arr[t][y]==6 ))
        return 1;
    return 0;
}
bool down(l x,l y,l t, l row,l len)
{
    if(t>=row || arr[x][y]==0 || arr[t][y]==0 || visited[x][y]==len || visited[t][y]!=0)
        return 0;
    if((arr[x][y]==1||arr[x][y]==2||arr[x][y]==5||arr[x][y]==6 )&&(arr[t][y]==1||arr[t][y]==2||arr[t][y]==4||arr[t][y]==7 ))
        return 1;
    return 0;
}
bool left(l x,l y,l t,l len)
{
    if(t<0 || arr[x][y]==0 || arr[x][t]==0 || visited[x][y]==len || visited[x][t]!=0)
        return 0;
    if((arr[x][y]==1||arr[x][y]==3||arr[x][y]==6||arr[x][y]==7 )&&(arr[x][t]==1||arr[x][t]==3||arr[x][t]==4||arr[x][t]==5 ))
        return 1;
    return 0;
}
bool right(l x,l y,l t,l col,l len)
{
    if(t>=col || arr[x][y]==0 || arr[x][t]==0 || visited[x][y]==len || visited[x][t]!=0)
        return 0;
    if((arr[x][y]==1||arr[x][y]==3||arr[x][y]==4||arr[x][y]==5 )&&(arr[x][t]==1||arr[x][t]==3||arr[x][t]==6||arr[x][t]==7 ))
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        l row;
        l col;
        l x;
        l y;
        l len;
        cin>>row>>col>>x>>y>>len;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>arr[i][j];
                visited[i][j] = 0;
            }
        }
        if(arr[x][y]==0)
            cout<<0<<endl;
        else if(len==1)
            cout<<1<<endl;
        else
        {
            list p;
            l start = 0;
            l end = 0;
            l count = 0;
            p.x = x;
            p.y = y;
            q[end++] = p;
            visited[x][y] = 1;
            while(start!=end)
            {
                p = q[start];
                l a1 = p.x;
                l a2 = p.y;
                start++;
                if(up(a1,a2,a1-1,len))
                {
                    p.x = a1-1;
                    p.y = a2;
                    q[end++] = p;
                    visited[a1-1][a2] = visited[a1][a2] + 1;
                }
                if(down(a1,a2,a1+1,row,len))
                {
                    p.x = a1+1;
                    p.y = a2;
                    q[end++] = p;
                    visited[a1+1][a2] = visited[a1][a2] + 1;
                }
                if(left(a1,a2,a2-1,len))
                {
                    p.x = a1;
                    p.y = a2-1;
                    q[end++] = p;
                    visited[a1][a2-1] = visited[a1][a2] + 1;
                }
                if(right(a1,a2,a2+1,col,len))
                {
                    p.x = a1;
                    p.y = a2+1;
                    q[end++] = p;
                    visited[a1][a2+1] = visited[a1][a2] + 1;
                }
            }
            for(l i=0;i<row;i++)
                for(l j=0;j<col;j++)
                    if(visited[i][j]!=0)
                        count++;
                        
        cout<<count<<endl;
        }
    }
    return 0;
}

//ALTERNATE SOLUTION FOR ENDOSCOPE

#include<iostream>
using namespace std;
#define l long long int

struct queue
{
    int ax,ay;
}q[1000001];

l v[1001][1001];
l visited[1001][1001];

bool up(l x,l y,l t,l len)
{
    if(t<0 || v[x][y]==0 || v[t][y]==0 || visited[x][y]==len || visited[t][y]!=0)
        return false;
    if((v[x][y]==1 || v[x][y]==2 || v[x][y]==4 || v[x][y]==7)&&(v[t][y]==1 || v[t][y]==2 || v[t][y]==5 || v[t][y]==6))
        return true;
    return false;
}

bool down(l x,l y,l t,l row,l len)
{
    if(t>=row || v[x][y]==0 || v[t][y]==0 || visited[x][y]==len || visited[t][y]!=0)
        return false;
    if((v[x][y]==1 || v[x][y]==2 || v[x][y]==5 || v[x][y]==6)&&(v[t][y]==1 || v[t][y]==2 || v[t][y]==4 || v[t][y]==7))
        return true;
    return false;
}

bool left(l x,l y,l t,l len)
{
    if(t<0 || v[x][y]==0 || v[x][t]==0 || visited[x][y]==len || visited[x][t]!=0)
        return false;
    if((v[x][y]==1 || v[x][y]==3 || v[x][y]==6 || v[x][y]==7)&&(v[x][t]==1 || v[x][t]==3 || v[x][t]==4 || v[x][t]==5))
        return true;
    return false;
}

bool right(l x,l y,l t,l col,l len)
{
    if(t>=col || v[x][y]==0 || v[x][t]==0 || visited[x][y]==len || visited[x][t]!=0)
        return false;
    if((v[x][y]==1 || v[x][y]==3 || v[x][y]==4 || v[x][y]==5)&&(v[x][t]==1 || v[x][t]==3 || v[x][t]==6 || v[x][t]==7))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        l row,col,x,y,len;
        cin>>row>>col>>x>>y>>len;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>v[i][j];
                visited[i][j] = 0;
            }
        }
        if(v[x][y]==0)
            cout<<0<<endl;
        else if(len==1)
            cout<<1<<endl;
        else
        {
            queue p;
            l start = 0;
            l end = 0;
            l count = 0;
            p.ax = x;
            p.ay = y;
            q[end++] = p;
            visited[x][y] = 1;
            while(start!=end)
            {
                p = q[start];
                l a1 = p.ax;
                l a2 = p.ay;
                start++;
                if(up(a1,a2,a1-1,len))
                {
                    p.ax = a1-1;
                    p.ay = a2;
                    q[end++] = p;
                    visited[a1-1][a2] = visited[a1][a2] + 1;
                }
                if(down(a1,a2,a1+1,row,len))
                {
                    p.ax = a1+1;
                    p.ay = a2;
                    q[end++] = p;
                    visited[a1+1][a2] = visited[a1][a2] + 1;
                }
                if(left(a1,a2,a2-1,len))
                {
                    p.ax = a1;
                    p.ay = a2-1;
                    q[end++] = p;
                    visited[a1][a2-1] = visited[a1][a2] + 1;
                }
                if(right(a1,a2,a2+1,col,len))
                {
                    p.ax = a1;
                    p.ay = a2+1;
                    q[end++] = p;
                    visited[a1][a2+1] = visited[a1][a2] + 1;
                }
            }
            for(l i=0;i<row;i++)
                for(l j=0;j<col;j++)
                {
                    if(visited[i][j]!=0)
                        count++;
                }
                cout<<count<<endl;
        }
    }
    return 0;
}

//2.AGGRESIVE COWS
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(int* arr,int n,int cow,int mid)
{
	int pos = arr[0];
	int c = 1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]-pos>=mid)
		{
			pos = arr[i];
			c++;
		}
		if(c==cow)
			return 1;
	}
	return 0;
}
int binary(int* arr,int n,int cow)
{
	sort(arr,arr+n);
	int start = arr[0];
	int end = arr[n-1];
	int ans = -1;
	while(start<end)
	{
		int mid = (start+end)/2;
		if(check(arr,n,cow,mid))
		{
			ans = max(ans,mid);
			start = mid+1;
		}
		else
			end = mid;
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int cow;
		cin>>n>>cow;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		cout<<binary(arr,n,cow)<<endl;
	}
	return 0;
}



//3.BALLOON BURST(done)
#include<iostream>
using namespace std;
int burst(int* arr,int len)
{
    int newarr[len+2];
    int n = 1;
    for(int i=0;i<len;i++,n++)
        newarr[n] = arr[i];
        
    newarr[0] = 1;
    newarr[n] = 1;
    n++;
    
    int dp[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j] = 0;
            
    for(int k=0;k<n;k++)
    {
        for(int l=0;l<n-k;l++)
        {
            int r = l+k;
            for(int i=l+1;i<r;i++)
            {
                int temp;
                if(l==0 && r==n-1)
                {
                    temp = newarr[l]*newarr[i]*newarr[r] + dp[l][i] + dp[i][r];
                }
                else
                {
                    temp = newarr[l]*newarr[r] + dp[l][i] + dp[i][r];
                }
                dp[l][r] = (dp[l][r]>temp) ? dp[l][r] : temp;
            }
        }
    }
    return dp[0][n-1];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        cout<<burst(arr,n)<<endl;
    }
    return 0;
}

//4.SPACESHIP GAME(done)
#include<iostream>
using namespace std;
int ans;
int max(int x,int y)
{
    return (x>y)?x:y;
}
void fun(int x,int y,int** arr,int coin,int bomb,int blow)
{
    if(coin<0) return;
    if(x==-1)
    {
        ans = max(ans,coin);
        return;
    }
    if(x<0 || y<0 ||y>=5) return;
    if(arr[x][y]==0)
    {
        fun(x-1,y-1,arr,coin,bomb,blow);
        fun(x-1,y,arr,coin,bomb,blow);
        fun(x-1,y+1,arr,coin,bomb,blow);
    }
    if(arr[x][y]==1)
    {
        fun(x-1,y-1,arr,coin+1,bomb,blow);
        fun(x-1,y,arr,coin+1,bomb,blow);
        fun(x-1,y+1,arr,coin+1,bomb,blow);
    }
    if(arr[x][y]==2)
    {
        if(bomb==0)
        {
            fun(x-1,y-1,arr,coin-1,bomb,blow);
            fun(x-1,y,arr,coin-1,bomb,blow);
            fun(x-1,y+1,arr,coin-1,bomb,blow);
            
            fun(x-1,y-1,arr,coin,1,x);
            fun(x-1,y,arr,coin,1,x);
            fun(x-1,y+1,arr,coin,1,x);
        }
        if(bomb==1)
        {
            if((blow-x)<=4)
            {
                fun(x-1,y-1,arr,coin,bomb,blow);
                fun(x-1,y,arr,coin,bomb,blow);
                fun(x-1,y+1,arr,coin,bomb,blow);
            }
            if((blow-x)>=5)
            {
                fun(x-1,y-1,arr,coin-1,bomb,blow);
                fun(x-1,y,arr,coin-1,bomb,blow);
                fun(x-1,y+1,arr,coin-1,bomb,blow);
            }
        }
        if(bomb==0)
        {
            if(arr[x][y]==0)
            {
                fun(x-1,y-1,arr,coin,1,x);
                fun(x-1,y,arr,coin,1,x);
                fun(x-1,y+1,arr,coin,1,x);
            }
            if(arr[x][y]==1)
            {
                fun(x-1,y-1,arr,coin+1,1,x);
                fun(x-1,y,arr,coin+1,1,x);
                fun(x-1,y+1,arr,coin+1,1,x);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ans = -1;
        int n;
        cin>>n;
        int** arr = new int*[n];
        for(int i=0;i<n;i++)
            arr[i] = new int[5];
        for(int i=0;i<n;i++)
            for(int j=0;j<5;j++)
                cin>>arr[i][j];
        
        int x = n;
        int y = 2;
        int coin = 0;
        int bomb = 0;
        int blow = 0;
        fun(x-1,y-1,arr,coin,bomb,blow);
        fun(x-1,y,arr,coin,bomb,blow);
        fun(x-1,y+1,arr,coin,bomb,blow);
        cout<<ans<<endl;
    }
    return 0;
}



//5.PILLARS(done)
#include<iostream>
using namespace std;

int grid[100],pillar=0;
int n;

void  dfs(int p1,int p2,int index)
{
  if(index==n+1)
  {
      if(p1==p2)
      {
          if(pillar<p1)
          pillar=p1;
      }
      return;
  }

    dfs(p1+grid[index],p2,index+1);
    dfs(p1,p2+grid[index],index+1);
    dfs(p1,p2,index+1);
}

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
           cin>>grid[i];

    int p1=0;
    int p2=0;
    dfs(p1,p1,0);
    cout<<pillar;
    return 0;
}

//ALTERNATE PILLARS SOLUTION
#include<iostream>
using namespace std;
int ans = 0;

void maxHeight(int a[],int s1 , int s2 ,int i ,int n)
{
	if(s1 ==  s2 && i != 0)
    {
    	if(ans < s1)
    	{
            ans = s1;
        }
    }

    if(i < n)
    {
        maxHeight(a,s1,s2,i+1,n);

        s1+=a[i];
        maxHeight(a,s1,s2,i+1,n);
        s1-=a[i];

        s2+=a[i];
        maxHeight(a,s1,s2,i+1,n);
        s2-=a[i];
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    ans = 0;
	int n;
	cin>>n;

	int a[1000];
	for(int i = 0;i<n;i++)
    {
    	cin>>a[i];
	}
	maxHeight(a,0,0,0,n);
	cout<<ans<<endl;
    }
	return 0;
}


//6.PRINT CYCLE IN DIRECTED GRAPH
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int e;
int visited[100];
int cycle = 0;
int flag = 0;
int k;
int arr[100];
void dfs(int** edge,int start)
{
    for(int i=1;i<=n;i++)
    {
        if(edge[start][i])
        {
            if(cycle==0)
            {
                if(visited[i]==0)
                {
                    visited[i] = 1;
                    dfs(edge,i);
                }
                else if(visited[i]==1)
                {
                    cycle = i;
                    k = 1;
                    break;
                }
            }
        }
    }
    arr[k] = start;
    k++;
    visited[start] = 2;
    return;
}
int main()
{
    cin>>n>>e;
    int** edge = new int*[n];
    for(int i=1;i<=n;i++)
    {
        edge[i] = new int[n];
        for(int j=1;j<=n;j++)
            edge[i][j] = 0;
    }
    for(int i=0;i<e;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        edge[n1][n2] = 1;
    }
    memset(visited,0,n);
    for(int i=1;i<=n;i++)
    {
        if(cycle==0)
            dfs(edge,i);
        else
        {
            flag = 1;
            break;
        }
    }
    if(flag==0)
        cout<<"NO CYCLE"<<endl;
    else
    {
        cout<<"CYCLE"<<endl;
        int hash[100];
        for(int i=0;i<=n;i++)
        {
            hash[i]=0;
        }

        for(int i=1;i<=k;i++)
        {
            if(cycle==arr[i])
            {
                k=i;
            }
            hash[arr[i]]++;
        }

        for(int i=1;i<=n;i++)
        {
            if(hash[i]>0)
                cout<<i<<" ";
        }
    }
    return 0;
}


//7.MARATHON SAMSUNG

#include<iostream>
using namespace std;
int ans = 99999;
int vmin[100];
int vsec[100];
int energy[601];
int startingenergy;
int dist;
int p = 1;

void fun(int index,int tenergy,int tdist,int ttime)
{
    if(tenergy>startingenergy)
        return;
    if(tdist==dist)
    {
        if(ans>ttime)
        {
            ans = ttime;
            return;
        }
    }
    
    for(int i=index;i<5;i++)
    {
        fun(i,tenergy+energy[i],tdist+1,ttime+vmin[i]);
    }
}
void init()
{
    ans = 99999;
    for(int i=0;i<5;i++)
    {
        vmin[i] = 0;
        vsec[i] = 0;
        energy[i] = 0;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>startingenergy>>dist;
        init();
        for(int i=0;i<5;i++)
        {
            cin>>vmin[i]>>vsec[i]>>energy[i];
            vmin[i] = (vmin[i]*60) + vsec[i];
        }
        fun(0,0,0,0);
        int q = ans;
        int rem = ans%60;
        ans = q/60;
        cout<<"#"<<p++<<" "<<ans<<":"<<rem<<endl;
    }
    return 0;
}


//8.RESTROOM(done)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int place(char* restroom,int n)
{
    int cur_max = 0;
    int cur_index = 0;
    int long_max = 0;
    int long_index = 0;
    bool flag = false;
    
    for(int i=0;i<n;i++)
    {
        if(!flag && restroom[i]=='_')
        {
            flag = true;
            cur_max = 1;
            cur_index = i;
        }
        else if(flag && restroom[i]=='_')
        {
            cur_max++;
        }
        else if(flag && restroom[i]=='X')
        {
            flag = false;
            if(cur_max>=long_max)
            {
                long_max = cur_max;
                long_index = cur_index;
            }
        }
        if(flag && cur_max>=long_max)
        {
            long_max = cur_max;
            long_index = cur_index;
        }
    }
    int index = (long_max+long_index+long_index-1)/2;
    return index;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char restroom[n];
        for(int i=0;i<n;i++)
            restroom[i] = '_';
        for(int i=0;i<n;i++)
        {
            int index = place(restroom,n);
            restroom[index] = 'X';
            for(int j=0;j<n;j++)
                cout<<restroom[j]<<" ";
            cout<<endl;
        }
    }
}

//9.WORMHOLE(done)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define max 100001
struct wormhole
{
    int sx,sy,dx,dy,cost;
};
int abs(int x)
{
    return (x>0)?x:-1*x;
}
int min(int x,int y)
{
    return (x>y)?y:x;
}
int path(wormhole* a,bool* visited,int n,int srcx,int srcy,int desx,int desy,int cost_so_far)
{
    int ans = cost_so_far + abs(srcx-desx) + abs(srcy-desy);
    for(int i=0;i<n;i++)
    {
        if(visited[i])continue;
        visited[i] = true;
        int cur_cost = cost_so_far + abs(srcx-a[i].sx) + abs(srcy-a[i].sy) + a[i].cost;
        ans = min(ans,path(a,visited,n,a[i].dx,a[i].dy,desx,desy,cur_cost));
        cur_cost = cost_so_far + abs(srcx-a[i].dx) + abs(srcy-a[i].dy) + a[i].cost;
        ans = min(ans,path(a,visited,n,a[i].sx,a[i].sy,desx,desy,cur_cost));
        visited[i]= false;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int srcx,srcy,desx,desy;
        cin>>srcx>>srcy>>desx>>desy;
        int n;
        cin>>n;
        wormhole a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i].sx>>a[i].sy>>a[i].dx>>a[i].dy>>a[i].cost;
        }
        bool* visited = new bool[max];
        memset(visited,false,n+1);
        int ans = path(a,visited,n,srcx,srcy,desx,desy,0);
        cout<<"min cost:"<<ans<<endl;
    }
    return 0;
}
9
3
0 0
100 100
1 2 120 120 2
4 5 120 100 3
6 8 150 180 4
3
0 0
100 100
1 2 120 120 2
4 5 120 100 3
6 8 102 102 4
0
0 0 60 60
1
0 0 2 0
1 0 1 2 0
1
0 0 60 60
40 40 20 20 20
2
100 50 10 5
80 40 10 6 10
80 10 70 40 5
3
500 500 1000 1000
501 501 999 999 1000
1 1 499 499 100
1000 999 0 0 200
3
0 0
100 100
1 2 120 120 2
4 5 120 100 3
6 8 150 180 4
3
0 0
100 100
1 2 120 120 2
4 5 120 100 3
6 8 102 102 4


->32
->22
->120
->2
->100
->41
->305
->32
->22

//10.PIPE MAXIMUM LENGTH(done)

#include<iostream>
using namespace std;
int ans;
int dp[1005][1005];
int dp1[1005][1005];

void pipe(int* arr,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            for(int k=0;k<=1000;k++)
            {
                if(j>=arr[i])
                    if(dp[j-arr[i]][k])
                        dp1[j][k] = 1;
                if(k>=arr[i])
                    if(dp[j][k-arr[i]])
                        dp1[j][k] = 1;
                if(dp[j][k])
                    dp1[j][k] = 1;
            }
        }
        for(int j=0;j<=1000;j++)
            for(int k=0;k<=1000;k++)
            {
                dp[j][k] = dp1[j][k];
                dp1[j][k] = 0;
            }
    }
    
    for(int i=1;i<=1000;i++)
        if(dp[i][i])
            ans = i;
            
    cout<<ans<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int* arr = new int[n+1];
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        for(int i=0;i<=1000;i++)
            for(int j=0;j<=1000;j++)
                dp[i][j] = 0;
    
        dp[0][0] = 1;
        pipe(arr,n+1);
    }
    return 0;
}

#include<iostream>
using namespace std;
int dp[1005][1005];
int dp1[1005][1005];
int ans;
void pipe(int arr[],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            for(int k=0;k<=1000;k++)
            {
                if(j>=arr[i])
                {
                   if(dp[j-arr[i]][k])
                       	dp1[j][k] = 1;
                }
                if(k>=arr[i])
                {
                    if(dp[j][k-arr[i]])
                       	dp1[j][k] = 1;
                }
                if(dp[j][k])
                    dp1[j][k] = 1;
            }
        }
        for(int j=0;j<=1000;j++)
        {
        	for(int k=0;k<=1000;k++)
            {
                dp[j][k]=dp1[j][k];
                dp1[j][k] = 0;
            }
        }
    }
    ans = 0;
    for(int i=1;i<=1000;i++)
    {
        if(dp[i][i])
            ans = i;
    }
    
    cout<<ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=1000;j++)
        	dp[i][j] = 0;
    }
    
    dp[0][0] = 1;
    pipe(arr,n+1);
    return 0;
}



//11.MR.LEE(done)
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool visited[13];
int a[13][13];
int cost;
void dfs(int n,int index,int sum,int num)
{
    if(num==n-1)
    {
        cost = min(cost,sum+a[index][0]);
        return;
    }
    visited[index] = true;
    for(int i=0;i<n;i++)
        if(!visited[i] && a[index][i]!=0)
            dfs(n,i,sum+a[index][i],num+1);
    
    visited[index] = false;
}
int main()
{
   int t;
    cin>>t;
    while(t--)
    {
        cost = 99999;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        memset(visited,false,n);
        dfs(n,0,0,0);
        cout<<cost<<endl;
    }
    return 0;
}

//12.RARE ELEMENTS(done)

#include<iostream>
using namespace std;
int n,c;
int ans = 9999;
int region[22][22];
int visited[22][22];
int location[5][2];
int rear = -1;
int front = -1;
struct queue
{
    int row;
    int col;
};
queue q[10000];
void init()
{
    int i,j;
    rear = -1;
    front = -1;
    for(i=0;i<22;i++)
        for(j=0;j<22;j++)
            visited[i][j] = 0;

    for(i=0;i<10000;i++)
    {
        q[i].row = 0;
        q[j].col = 0;
    }
}
void discover(int row,int col,int val)
{
    int cnt = 0;
    for(int k=0;k<c;k++)
    {
        if(visited[location[k][0]][location[k][1]]>0)
            cnt++;
    }
    if(cnt>=c)
        return;
    if((row-1)>=1 && visited[row-1][col]==0 && (region[row-1][col]==1 || region[row-1][col]==3))
    {
    	visited[row-1][col] = val+1;
        ++rear;
        q[rear].row = row-1;
        q[rear].col = col;
    }
    if((row+1)<=n && visited[row+1][col]==0 && (region[row+1][col]==1 || region[row+1][col]==3))
    {
        visited[row+1][col] = val+1;
        ++rear;
        q[rear].row = row+1;
        q[rear].col = col;
    }
    if((col-1)>=1 && visited[row][col-1]==0 && (region[row][col-1]==1 || region[row][col-1]==3))
    {
        visited[row][col-1]= val+1;
        ++rear;
        q[rear].row = row;
        q[rear].col = col-1;
    }
    if((col+1)<=n && visited[row][col+1]==0 && (region[row][col+1]==1 || region[row][col+1]==3))
    {
        visited[row][col+1] = val+1;
        ++rear;
        q[rear].row = row;
        q[rear].col = col+1;
    }
    while(front<rear)
    {
        ++front;
        discover(q[front].row,q[front].col,visited[q[front].row][q[front].col]);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        int temp = 0;
        cin>>n>>c;
        for(int i=0;i<c;i++)
        {
            cin>>x>>y;
            location[i][0] = x;
            location[i][1] = y;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>region[i][j];
            }
        }
        for(int k=0;k<c;k++)
            region[location[k][0]][location[k][1]] = 3;

        init();
        ans = 9999;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                init();
                temp = 0;
                if(region[i][j]==1)
                {
                    visited[i][j] = 1;
                    discover(i,j,1);
                    for(int k=0;k<c;k++)
                    {
                		if(temp<visited[location[k][0]][location[k][1]])
                            temp = visited[location[k][0]][location[k][1]];
                    }
                    if(ans>temp)
                        ans = temp;
                }
            }
        }
        cout<<"path:"<<ans-1<<endl;
    }
    return 0;
}

//13.MR.KIM(done)

#include<bits/stdc++.h>
using namespace std;
int n,x[20],y[20],ans;
int abs(int i)
{
    if(i>0) return i;
    else
        return (-1*i);
}
int dis(int a,int b)
{
    int x1 = x[a], x2 = x[b];
    int y1 = y[a], y2 = y[b];

    return (abs(x1-x2) + abs(y1-y2));
}
void dfs(bool* visited,int x,int nodes,int value)
{
    if(n==nodes)
	{
        ans = min(ans,value+dis(x,n+1));
	return;
	}

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(visited,i,nodes+1,value+dis(x,i));
            visited[i] = false;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ans = INT_MAX;
        cin>>n;
        cin>>x[n+1]>>y[n+1]>>x[0]>>y[0];
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        bool* visited = new bool[n+2];
        for(int i=0;i<=n+2;i++) visited[i] = 0;
        dfs(visited,0,0,0);
        cout<<ans;
    }
    return 0;
}

//14.TOLL GATE

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,cc[25],t[25],min_cost = INT_MAX;
void dfs(int p,int a,int b,int c,int cost)
{
    int asum = a+b+c;
    if(cost>min_cost) return;
    if(p==n-1)
    {
        if(asum<t[p])
            cost = cost + cc[p];
        if(cost<min_cost) min_cost = cost;
        return;
    }
    dfs(p+1,a,b,c,cost+cc[p]);
    dfs(p+1,a+t[p],b,c,cost+2*cc[p]);
    if(asum>=t[p])
    {
        if(t[p]>b+c) a = asum-t[p];
        if(t[p]>c) b = t[p]-c >= b ? 0 :b-t[p]+c;
        dfs(p+1,0,a,b,cost);
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>t[i]>>cc[i];
        dfs(0,0,0,0,0);
        cout<<min_cost;
        min_cost = INT_MAX;
    }
    return 0;
}

//15.BIPARTITE DFS

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,e;
bool bipartitedfs(int** edge,bool* visited,int* color,int start)
{
    for(int i=0;i<n;i++)
    {
        if(edge[start][i]==1)
        {
            if(!visited[i])
            {
                visited[i] = 1;
                color[i] = !color[start];
                if(!bipartitedfs(edge,visited,color,i))
                    return false;
            }
            else if(color[i]==color[start])
                return false;
        }
    }
    return true;
}
int main()
{
    cin>>n>>e;
    int** edge = new int*[n];
    for(int i=0;i<n;i++)
    {
        edge[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            edge[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        edge[n1][n2] = 1;
        edge[n2][n1] = 1;
    }
    bool* visited = new bool[n];
    int* color = new int[n];
    memset(visited,0,n);
    visited[0] = 1;
    color[0] = 0;
    cout<<(bipartitedfs(edge,visited,color,0));
    return 0;
}

//16.BIPARTITE BFS

#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n,e;
bool bipartitebfs(int** edge,int* color,int start)
{
    color[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int ele = q.front();
        q.pop();
        if(edge[ele][ele]==1)  //self loop
            return false;
        for(int i=0;i<n;++i)
        {
            if(edge[ele][i])
            {
                if(color[i]==-1)
                {
                    color[i] = 1 - color[ele];
                    q.push(i);
                }
                else if(color[i]==color[ele])
                    return false;
            }
        }
        //return true;
    }
    return true;
}
bool bipartite(int** edge,int* color)
{
    for(int i=0;i<n;i++) color[i] = -1;
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartitebfs(edge,color,i))
                return false;
        }
    }
    return true;
}
int main()
{
    cin>>n>>e;
    int** edge = new int*[n];
    for(int i=0;i<n;i++)
    {
        edge[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            edge[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        edge[n1][n2] = 1;
        edge[n2][n1] = 1;
    }
    int* color = new int[n];
    cout<<(bipartite(edge,color));
    cout<<endl;
    for(int i=0;i<n;i++) cout<<color[i]<<"  ";
    return 0;
}

//17.RESTROOM
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int place(char* restroom,int n)
{
    int cur_max = 0;
    int cur_index = 0;
    int long_max = 0;
    int long_index = 0;
    bool flag = false;
    
    for(int i=0;i<n;i++)
    {
        if(!flag && restroom[i]=='_')
        {
            flag = true;
            cur_max = 1;
            cur_index = i;
        }
        else if(flag && restroom[i]=='_')
        {
            cur_max++;
        }
        else if(flag && restroom[i]=='X')
        {
            flag = false;
            if(cur_max>=long_max)
            {
                long_max = cur_max;
                long_index = cur_index;
            }
        }
        if(flag && cur_max>=long_max)
        {
            long_max = cur_max;
            long_index = cur_index;
        }
    }
    int index = (long_max+long_index+long_index-1)/2;
    return index;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char restroom[n];
        for(int i=0;i<n;i++)
            restroom[i] = '_';
        for(int i=0;i<n;i++)
        {
            int index = place(restroom,n);
            restroom[index] = 'X';
            for(int j=0;j<n;j++)
                cout<<restroom[j]<<" ";
            cout<<endl;
        }
    }
}

//18.//rare elements official
#include<iostream>
using namespace std;
int n,c;
int ans = 9999;
int region[22][22];
int visited[22][22];
int location[5][2];
int rear = -1;
int front = -1;
struct queue
{
    int row;
    int col;
};
queue q[10000];
void init()
{
    int i,j;
    rear = -1;
    front = -1;
    for(i=0;i<22;i++)
        for(j=0;j<22;j++)
            visited[i][j] = 0;

    for(i=0;i<10000;i++)
    {
        q[i].row = 0;
        q[j].col = 0;
    }
}
void discover(int row,int col,int val)
{
    int cnt = 0;
    for(int k=0;k<c;k++)
    {
        if(visited[location[k][0]][location[k][1]]>0)
            cnt++;
    }
    if(cnt>=c)
        return;
    if((row-1)>=1 && visited[row-1][col]==0 && (region[row-1][col]==1 || region[row-1][col]==3))
    {
    	visited[row-1][col] = val+1;
        ++rear;
        q[rear].row = row-1;
        q[rear].col = col;
    }
    if((row+1)<=n && visited[row+1][col]==0 && (region[row+1][col]==1 || region[row+1][col]==3))
    {
        visited[row+1][col] = val+1;
        ++rear;
        q[rear].row = row+1;
        q[rear].col = col;
    }
    if((col-1)>=1 && visited[row][col-1]==0 && (region[row][col-1]==1 || region[row][col-1]==3))
    {
        visited[row][col-1]= val+1;
        ++rear;
        q[rear].row = row;
        q[rear].col = col-1;
    }
    if((col+1)<=n && visited[row][col+1]==0 && (region[row][col+1]==1 || region[row][col+1]==3))
    {
        visited[row][col+1] = val+1;
        ++rear;
        q[rear].row = row;
        q[rear].col = col+1;
    }
    while(front<rear)
    {
        ++front;
        discover(q[front].row,q[front].col,visited[q[front].row][q[front].col]);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        int temp = 0;
        cin>>n>>c;
        for(int i=0;i<c;i++)
        {
            cin>>x>>y;
            location[i][0] = x;
            location[i][1] = y;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>region[i][j];
            }
        }
        for(int k=0;k<c;k++)
            region[location[k][0]][location[k][1]] = 3;

        init();
        ans = 9999;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                init();
                temp = 0;
                if(region[i][j]==1)
                {
                    visited[i][j] = 1;
                    discover(i,j,1);
                    for(int k=0;k<c;k++)
                    {
                		if(temp<visited[location[k][0]][location[k][1]])
                            temp = visited[location[k][0]][location[k][1]];
                    }
                    if(ans>temp)
                        ans = temp;
                }
            }
        }
        cout<<"path:"<<ans-1<<endl;
    }
    return 0;
}
//19.laughing bomb
//laughing bomb official 
#include <iostream>
using namespace std;
#define MAX_SIZE 101
int citymap[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int Answer;
int row_size = 0;
int col_size = 0;
int bomb_row, bomb_col;

void traverse(int row, int col, int cur_value)
{
    if ((row < 1) || (row > row_size) || (col < 1) || (col > col_size))
        return;

    if (citymap[row][col] == 0)
        return;
    
    if (visited[row][col])
    {
        if(citymap[row][col] > cur_value)
            citymap[row][col] = cur_value;
        else
            return;
    }
    else
    {
        visited[row][col] = 1;
        citymap[row][col] = cur_value;
    }

    traverse(row, col+1, cur_value + 1);
    traverse(row+1, col, cur_value + 1);
    traverse(row, col-1, cur_value + 1);
    traverse(row-1, col, cur_value + 1);

    return;
}
void init()
{
    row_size = 0;
    col_size = 0;

    bomb_row = 0;
    bomb_col = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
         	citymap[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    Answer = 0;
}
int main()
{
    int T;
    int i;
    int j;
    cin>>T;
    while(T--)
    {
        init();
        cin>>col_size>>row_size;

        for (i = 1; i <= row_size; i++)
            for (j = 1; j <= col_size; j++)
                cin>>citymap[i][j];

        cin>>bomb_col>>bomb_row;
        citymap[bomb_row][bomb_col] = 1;
        traverse(bomb_row, bomb_col,1);
       
        for (i = 1; i <= row_size; i++)
            for (j = 1; j <= col_size; j++)
                if (Answer < citymap[i][j])
                    Answer = citymap[i][j];

        cout<<Answer<<endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
//20.cow
#include<iostream>
using namespace std;
void merge(int a[],int start,int mid,int end)
{
	int n1=mid-start+1;
	int n2=end-mid;
	int l1[n1],l2[n2];
	for(int i=0;i<n1;i++)
	{
		 l1[i]=a[start+i];
	}
	for(int j=0;j<n2;j++)
	{
		l2[j]=a[mid+1+j];
	}
	int k=start,i=0,j=0;
	while(i<n1 && j<n2)
	{
		if(l1[i]<l2[j])
		{
			a[k++]=l1[i++];
		}
		else 
		{
			a[k++]=l2[j++];
		}
	}
	while(i<n1)
	{
		a[k++]=l1[i++];
	}
	while(j<n2)
	{
		a[k++]=l2[j++];
	}
}
void mergesort(int a[],int start,int end)
{
	if(start<end)
	{
	  int mid=(start+end)/2;
	  mergesort(a,start,mid);
	  mergesort(a,mid+1,end);
	  merge(a,start,mid,end);
    }
}
bool check(int a[],int n,int c,int dis)
{
	int last=0;
	int w=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]-a[last]>=dis)
		{
			w++;
			last=i;
		}
		if(w==c)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int n,c;
	cin>>n>>c;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	 int start=0;
	 int end=a[n-1]-a[0];
	 int ans=-1;
	 while(start<=end)
	 {
	 	int mid=(start+end)/2;
	 	if(check(a,n,c,mid))
	 	{
	 		ans=mid;
	 		start=mid+1;
		 }
		 else
		 {
		 	end=mid-1;
		 }
	 }
	 cout<<ans;
}
//21.frog
#include<iostream>
using namespace std;
bool safe(int i,int j,int n,int m)
{
	if(i<0 || j<0 || i>=n || j>=m)
	return false;
	return true;
}
void dfs(int**a,int** dp,int n,int m,int i,int j, int cost)
{
	if(dp[i][j]>cost)
	{
		dp[i][j]=cost;
		if(safe(i+1,j,n,m) && a[i+1][j]==1)
		{
			dfs(a,dp,n,m,i+1,j,cost+1);
		}
		if(safe(i-1,j,n,m) && a[i-1][j]==1)
		{
			dfs(a,dp,n,m,i-1,j,cost+1);
		}
		if(safe(i,j+1,n,m) && a[i][j+1]==1)
		{
			dfs(a,dp,n,m,i,j+1,cost);
		}
		if(safe(i,j-1,n,m) && a[i][j-1]==1)
		{
			dfs(a,dp,n,m,i,j-1,cost);
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	int** a=new int*[n];
	int** dp=new int*[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new int[m];
		dp[i]=new int[m];
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			dp[i][j]=9999;
		}
	}
	int homex,homey,officex,officey;
	cin>>homex>>homey>>officex>>officey;
	dfs(a,dp,n,m,homex,homey,0);
	cout<<dp[officex][officey];
}
//21.sum at level k
#include<iostream>
using namespace std;
int strlen(char str[])
{
    int k=0;
    while(str[k])
        k++;
    return k;
}
int main()
{
    char str[1001];
    cin>>str;
    int n = strlen(str);
    int k,sum=0,open=0,close=0;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
            open++;
        else if(str[i]==')')
            close++;
        else
        {
            int diff = open-close;
            if(diff==k+1)
                sum+=str[i]-48;
        }
    }
    cout<<sum<<endl;
}
//22. cycle directed nd print
//directed cycle and print SAMSUNG
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int e;
int visited[100];
int cycle = 0;
int flag = 0;
int k;
int arr[100];
void dfs(int** edge,int start)
{
    for(int i=1;i<=n;i++)
    {
        if(edge[start][i])
        {
            if(cycle==0)
            {
                if(visited[i]==0)
                {
                    visited[i] = 1;
                    dfs(edge,i);
                }
                else if(visited[i]==1)
                {
                    cycle = i;
                    k = 1;
                    break;
                }
            }
        }
    }
    arr[k] = start;
    k++;
    visited[start] = 2;
    return;
}
int main()
{
    cin>>n>>e;
    int** edge = new int*[n];
    for(int i=1;i<=n;i++)
    {
        edge[i] = new int[n];
        for(int j=1;j<=n;j++)
            edge[i][j] = 0;
    }
    for(int i=0;i<e;i++)
    {
        int n1,n2;
        cin>>n1>>n2;
        edge[n1][n2] = 1;
    }
    memset(visited,0,n);
    for(int i=1;i<=n;i++)
    {
        if(cycle==0)
            dfs(edge,i);
        else
        {
            flag = 1;
            break;
        }
    }
    if(flag==0)
        cout<<"NO CYCLE"<<endl;
    else
    {
        cout<<"CYCLE"<<endl;
        int hash[100];
        for(int i=0;i<=n;i++)
        {
            hash[i]=0;
        }

        for(int i=1;i<=k;i++)
        {
            if(cycle==arr[i])
            {
                k=i;
            }
            hash[arr[i]]++;
        }

        for(int i=1;i<=n;i++)
        {
            if(hash[i]>0)
                cout<<i<<" ";
        }
    }
    return 0;
}
//23.pots and crow
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    int ans = 0;
    for(int i=0;i<k;i++)
        ans += a[i];
    ans += (a[k-1]*(n-k));
    cout<<ans<<endl;
}
//24.oil mine
#include<iostream>
using namespace std;
int max1(int x,int y)
{
    return(x>y ? x:y);
}
int min1(int x,int y)
{
    return(x<y ? x:y);
}
void dfs(int i,int mx,int mn,int sum,int comp,int n,int m,bool vis[],int a[],int &ans)
{
    if(comp>n)
        return;
    int nmx=max1(sum,mx);
    int nmn=min1(sum,mn);
    if(vis[i]==true)
    {
        if(comp==n-1)
        {
            ans=min1(ans,nmx-nmn);
        }
      return;
    }
   vis[i]=true;
  int j=(i+1)%m;
  dfs(j,mx,mn,sum+a[i],comp,n,m,vis,a,ans);
  dfs(j,nmx,nmn,a[i],comp+1,n,m,vis,a,ans);
  vis[i]=false;
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>n>>m;
        int a[m];
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }
        bool vis[m];
        for(int i=0;i<m;i++)
        {
            vis[i]=false;
        }
        if(n>m)
            cout<<"-1"<<endl;
        else
        {
            int ans=9999;
            //int nmx=-1000;
            //int nmn=1000;
            for(int i=0;i<m;i++)
            {
                dfs(i,-1000,1000,0,0,n,m,vis,a,ans);
            }
            cout<<ans<<endl;
        }
    }
}
//25.jewel rat maze
#define MAXN 11
#include<stdio.h>
int N;
int map[MAXN][MAXN];
int visited[MAXN][MAXN];

int num_jewels;

int path[MAXN][MAXN];

void traverse(int x, int y, int jewel_cnt)
{
    int i, j;
    if (x<1 || x>N || y<1 || y>N || map[x][y] == 1 || visited[x][y])
        return;

    if (y == N && x == N)
    {
        if (num_jewels <= jewel_cnt)
        {
            num_jewels = jewel_cnt;

            //Take a snapshot of the path
            for (i = 1; i <= N; i++)
            {
                for (j = 1; j <= N; j++)
                {
                    if (visited[i][j] == 3)
                        path[i][j] = 3;
                    else
                        path[i][j] = map[i][j];
                }
            }
            path[x][y] = 3;
        }
        return;
    }

    visited[x][y] = 3;
    if (map[x - 1][y] == 2)
        traverse(x - 1, y, jewel_cnt + 1);
    else
        traverse(x - 1, y, jewel_cnt);
    if (map[x + 1][y] == 2)
        traverse(x + 1, y, jewel_cnt + 1);
    else
        traverse(x + 1, y, jewel_cnt);
    if (map[x][y - 1] == 2)
        traverse(x, y - 1, jewel_cnt + 1);
    else
        traverse(x, y - 1, jewel_cnt);
    if (map[x][y + 1] == 2)
        traverse(x, y + 1, jewel_cnt + 1);
    else
        traverse(x, y + 1, jewel_cnt);
    visited[x][y] = 0;
}

int main(void)
{
    int tc, T;

    //freopen("pick_jewel.txt","r",stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (tc = 0; tc<T; tc++)
    {
        int i, j;
        scanf("%d", &N);
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                scanf("%d", &map[i][j]);
                path[i][j] = map[i][j];
                visited[i][j] = 0;
            }
        }
        num_jewels = 0;
        traverse(1, 1, 0);

        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
        printf("%d\n\n", num_jewels);
    }
    return 0;
}
//26.

