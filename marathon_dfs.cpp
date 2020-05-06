///marathon

#include<iostream>
using namespace std;
int ans=99999;
int energy,dist,p=1,test;
int vmin[100],sec[100],energy1[601];

void dfs(int index,int tdist,int tenergy,int ttime)
{
    if(tenergy>energy)
        return;
    
    if(tdist==dist)
    {
        if(ttime<ans)
            ans=ttime;
        return;
    }
    
    for(int i=index;i<5;i++)
        dfs(i,tdist+1,tenergy+energy1[i],ttime+vmin[i]);
}
void init()
{
    ans=99999;
    for(int i=0;i<5;i++)
    {
        vmin[i]=0;
        sec[i]=0;
        energy1[i]=0;
    }
}
int main()
{
   	cin>>test;
    while(test--)
    {
        cin>>energy>>dist;
        init();

        for(int i=0;i<5;i++)
        {
            cin>>vmin[i]>>sec[i]>>energy1[i];
            vmin[i]=(vmin[i]*60)+sec[i];
        }

        dfs(0,0,0,0);
        int q=ans;
        int rem=ans%60;
        ans=q/60;
        cout<<"#"<<p++<<" "<<ans<<" "<<rem<<endl;
	}
    return 0;
}
