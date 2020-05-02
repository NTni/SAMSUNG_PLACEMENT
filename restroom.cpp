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
