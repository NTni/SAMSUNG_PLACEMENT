#include <iostream>
using namespace std;
float maxprob;
int calprob(int from[],int to[],float prob[],int nodes,int edges,int moves){
    float dp[moves+1][nodes+1];
    for(int i=0;i<=moves;i++){
        for(int j=0;j<=nodes;j++){
            dp[i][j] = 0;
        }
    }
    dp[0][1] = 1;
    for(int i=1;i<=moves;i++){
       for(int k=1;k<=nodes;k++){
           float temp = 0;
            for(int j=0;j<edges;j++){
                if(to[j]==k){
                    temp+=(dp[i-1][from[j]]*prob[j]);
                }
            }
            dp[i][k] = temp;
       }
    }
    maxprob = dp[moves][0];
    int index=0;
    for(int i=1;i<=nodes;i++){
        if(maxprob<dp[moves][i]){
            maxprob = dp[moves][i];
            index = i;
        }
    }
    return index;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int nodes,edges,duration;
	    cin>>nodes>>edges>>duration;
	    int moves = duration/10;
	    int from[edges],to[edges];
	    float prob[edges];
	    for(int i=0;i<edges;i++){
	        cin>>from[i]>>to[i]>>prob[i];
	    }
	    int ans = calprob(from,to,prob,nodes,edges,moves);
	    cout<<ans<<" "<<maxprob<<endl;
	}
	return 0;
}
