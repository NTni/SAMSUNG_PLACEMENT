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
