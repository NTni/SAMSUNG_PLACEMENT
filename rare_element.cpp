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
