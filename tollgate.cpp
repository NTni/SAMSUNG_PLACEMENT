Toggle navigation



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int toll[25];
int men[25];
int min_cost;
void dfs(int pos,int a,int b,int c,int cost)
{
    int temp = a+b+c;
    if(cost>min_cost) return;
    if(pos==n-1)
    {
        if(temp<men[pos])
            cost = cost + toll[pos];
        if(cost<min_cost)
            min_cost = cost;
        return;
    }
    dfs(pos+1,a,b,c,cost+toll[pos]);
    dfs(pos+1,a+men[pos],b,c,cost+2*toll[pos]);
    if(temp>=men[pos])
    {
        if(men[pos]>b+c)
            a = temp-men[pos];
        if(men[pos]>c)
            b = men[pos]-c>=b?0:b-men[pos]+c;
        dfs(pos+1,0,a,b,cost);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>men[i]>>toll[i];
        min_cost = 2e9;
        dfs(0,0,0,0,0);
        cout<<min_cost<<"\n";
    }
    return 0;
}/*5
7
10 100
70 5
80 15
20 60
50 90
30 80
10 10
 
9
600 800
300 400
Custom Inputs
Code ID	Status	Time (sec)	Exit Signal
242666	C++ : Success	0.8	0
Standard Output
150
3000
2370
4721
8231
5
7
10 100
70 5
80 15
20 60
50 90
30 80
10 10
 
9
600 800
300 400
300 400
1000 400
300 600
100 300
600 300
600 500
1000 300
 
11
1000 10
700 900
400 500
300 10
900 900
300 10
50 900
50 900
700 900
500 900
50 10
 
20
896 546
543 216
454 310
408 367
40 602
252 582
954 627
850 234
763 479
232 278
301 538
528 508
936 154
629 443
758 336
432 700
882 256
278 738
517 882
317 136
 
20
410 610
831 909
675 629
421 774
386 869
544 219
492 414
996 557
499 482
231 285
804 978
304 881
489 911
75 315
927 648
252 914
330 396
937 133
495 882
813 717
 



© 2018 SapphireEngine.com   All Rights Reserved.

150
3000
2370
4721
8231
