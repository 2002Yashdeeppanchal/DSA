https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1



#include<bits/stdc++.h>
int f(int day,int taskdone,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(dp[day][taskdone]!=-1){
        return dp[day][taskdone];
    }
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=taskdone){
                maxi=max(maxi,points[day][i]);
            }
        }
        return dp[day][taskdone]=maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=taskdone){
            int d=points[day][i]+f(day-1,i,points,dp);
            maxi=max(d,maxi);
        }
    }
    return dp[day][taskdone]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    //memoisation
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);
    
    //tabulation
    vector<vector<int>>dp(n,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][1],points[0][0]);
    dp[0][3]=max(points[0][1],max(points[0][1],points[0][2]));
    
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int d=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],d);
                }
            }
        }
    }
    return dp[n-1][3];
    
    
    
    
    //space optimisation
    vector<int>prev(4);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][1],points[0][0]);
    prev[3]=max(points[0][1],max(points[0][1],points[0][2]));
    
     for(int day=1;day<n;day++){
        vector<int>temp(4);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int d=points[day][task]+prev[task];
                    temp[last]=max(temp[last],d);
                }
            }
        }
         prev=temp;
    }
    
    return prev[3];
    
    
}
