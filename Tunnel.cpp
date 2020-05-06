#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
int h;
int v;
int c1,c2,m1,m2,r1,r2;
int final_cost;
int cost = 0;
int cur_cost;
int ans[16];
int s[16][301];
int k1;
int k2;
int n1,n2,n3,n4,n5;
int main()
{
    int t;
    cin>>t;

    int max;
    for(int testcase=1;testcase<=t;testcase++)
    {
        final_cost = 6000000;
        cur_cost = 6000000;
        for(int i=0;i<16;i++)
        {
            ans[i] = 0;
            for(int j=0;j<301;j++)
                s[i][j] = 0;
        }
        cin>>n>>h>>v;

        for(int i=1;i<=v;i++)
            for(int j=1;j<=h;j++)
                cin>>s[i][j];

        cin>>c1>>r1>>m1>>c2>>r2>>m2;

        for(int i=1;i<=v;i++)
        {
            max = 6000000;
            for(k1=0;k1<=h;k1++)
            {
                k2 = h - k1;
                for(int j=0;j<=k1;j++)
                    cost = cost + (c1*s[i][j]);
                for(int k=h;k>k1;k--)
                    cost = cost + (c2*s[i][k]);
                if(k1>k2)
                    cost = cost + ((k1-k2-1)*r1);
                else if(k2>k1)
                    cost = cost + ((k2-k1-1)*r2);
                if(max>=cost)
                    max = cost;
                cost = 0;
            }
            ans[i] = max;
        }

        if(n==1)
        {
			for(n1=1;n1<=v;n1++)
				if(final_cost>=ans[n1])
					final_cost=ans[n1];
        }

        else if(n==2)
        {
            for(n1=1;n1<=(v-((n-1)*2));n1++)
				for(n2=n1+2;n2<=v;n2++)
                {
					cur_cost= ans[n1]+ans[n2]+ (m1*m1 + m2*m2)*(n2-n1);
                    if(final_cost>=cur_cost)
                        final_cost= cur_cost;
                }
        }

        else if(n==3)
        {
            for(n1=1;n1<=(v-((n-1)*2));n1++)
				for(n2=n1+2;n2<=(v-((n-2)*2));n2++)
					for(n3=n2+2;n3<=v;n3++)
                    {
						cur_cost= ans[n1]+ans[n2]+ ans[n3] + (m1*m1 + m2*m2)*(n3-n1);
                        if(final_cost>=cur_cost)
                            final_cost= cur_cost;
                    }
        }

        else if(n==4)
        {
            for(n1=1;n1<=(v-((n-1)*2));n1++)
				for(n2=n1+2;n2<=(v-((n-2)*2));n2++)
					for(n3=n2+2;n3<=(v-((n-3)*2));n3++)
						for(n4=n3+2;n4<=v;n4++)
                        {
							cur_cost= ans[n1]+ans[n2]+ ans[n3] + ans[n4] + (m1*m1 + m2*m2)*(n4-n1);
                            if(final_cost>=cur_cost)
                                final_cost= cur_cost;
                        }
        }

        else if(n==5)
        {
            for(n1=1;n1<=(v-((n-1)*2));n1++)
				for(n2=n1+2;n2<=(v-((n-2)*2));n2++)
					for(n3=n2+2;n3<=(v-((n-3)*2));n3++)
						for(n4=n3+2;n4<=(v-((n-4)*2));n4++)
							for(n5=n4+2;n5<=v;n5++)
                            {
                                cur_cost= ans[n1]+ans[n2]+ ans[n3] + ans[n4] + ans[n5] + (m1*m1 + m2*m2)*(n5-n1);
                                if(final_cost>=cur_cost)
                                    final_cost= cur_cost;
                            }
        }

        cout<<"#"<<testcase<<"."<<final_cost<<"\n";
    }
    return 0;
}


//ALTERNATE

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int v;
int h;
int n;
int c1,c2,r1,r2,m1,m2;
int k1,k2;
int s[16][301];
int ans[16];
int cost;
int final_cost;
int cur_cost;
int n1,n2,n3,n4,n5;

void one()
{
    for(n1=1;n1<=v;n1++)
    {
        if(final_cost>=ans[n1])
            final_cost = ans[n1];
    }
}
void two()
{
    for(n1=1;n1<=(v-((n-1)*2));n1++)
        for(n2=n1+2;n2<=v;n2++)
        {
            cur_cost = ans[n1] + ans[n2] + (m1*m1 + m2*m2)*(n2-n1);
            if(final_cost>=cur_cost)
            	final_cost = cur_cost;
        }
}
void three()
{
    for(n1=1;n1<=(v-((n-1)*2));n1++)
        for(n2=n1+2;n2<=(v-((n-2)*2));n2++)
        {
            for(n3=n2+2;n3<=v;n3++)
            {
                cur_cost = ans[n1] + ans[n2] + ans[n3] + (m1*m1 + m2*m2)*(n3-n1);
                if(final_cost>=cur_cost)
            	final_cost = cur_cost;
            }
        }
}
void four()
{
    for(n1=1;n1<=(v-((n-1)*2));n1++)
        for(n2=n1+2;n2<=(v-((n-2)*2));n2++)
        {
            for(n3=n2+2;n3<=(v-((n-3)*2));n3++)
            {
                for(n4=n3+2;n4<=v;n4++)
                {
                    cur_cost = ans[n1] + ans[n2] + ans[n3] + ans[n4] + (m1*m1 + m2*m2)*(n4-n1);
                    if(final_cost>=cur_cost)
            			final_cost = cur_cost;
                }
            }
        }
}
void five()
{
    for(n1=1;n1<=(v-((n-1)*2));n1++)
        for(n2=n1+2;n2<=(v-((n-2)*2));n2++)
        {
            for(n3=n2+2;n3<=(v-((n-3)*2));n3++)
            {
                for(n4=n3+2;n4<=(v-((n-4)*2));n4++)
                {
                    for(n5=n4+2;n5<=v;n5++)
                    {
                        cur_cost = ans[n1] + ans[n2] + ans[n3] + ans[n4] + ans[n5] + (m1*m1 + m2*m2)*(n5-n1);
                        if(final_cost>=cur_cost)
            				final_cost = cur_cost;
                    }
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
        int max;
        final_cost= 60000000;
        cur_cost = 60000000;
        cin>>n>>h>>v;
        for(int i=1;i<=v;i++)
            for(int j=1;j<=h;j++)
                cin>>s[i][j];
        cin>>c1>>r1>>m1>>c2>>r2>>m2;
        for(int i=1;i<=v;i++)
        {
            max = 60000000;
            for(k1=0;k1<=h;k1++)
            {
                k2 = h - k1;
                for(int j=0;j<=k1;j++)
                    cost = cost + c1*s[i][j];
                for(int k=h;k>k1;k--)
                    cost = cost + c2*s[i][k];
                if(k1>k2)
                    cost = cost + r1*(k1-k2-1);
                else if(k2>k1)
                    cost = cost + r2*(k2-k1-1);
                if(max>cost)
                    max = cost;
                cost = 0;
            }
            ans[i] = max;
        }
        if(n==1)
            one();
        else if(n==2)
           	two();
        else if(n==3)
            three();
        else if(n==4)
            four();
        else if(n==5)
            five();

        cout<<final_cost<<"\n";
    }
	return 0;
}

