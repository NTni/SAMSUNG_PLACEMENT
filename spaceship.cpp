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
