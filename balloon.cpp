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
