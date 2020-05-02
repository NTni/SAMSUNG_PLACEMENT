
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
