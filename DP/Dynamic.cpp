#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Fib Recursion Time - 2N
int fibRecursion(int n){
  if(n==0 or n==1){
    return n;
  }
  return fibRecursion(n-1) + fibRecursion(n-2);
}

// Fib Bottom Up DP - O(n)
int fibDP(int n){
  vector<int> v(n+1);
  v[0] = 0; 
  v[1] = 1;
  for(int i=2;i<=n;i++){
    v[i] = v[i-1]+v[i-2];
  }
  return v[n];
}

// Fib Top Down Approach O(n)
int fibDPtop(int n,int* dp){
  if(n==0 or n==1){
    return dp[n]=n;
  }
  if(dp[n]!=0){
    return dp[n];
  }
  int ans = fibDPtop(n-1,dp)+fibDPtop(n-2,dp);
  return dp[n] = ans;
}
// Space Optimisation for Fibonnaci
int fibSpace(int n){
  int a =0,b=1,ans;
  for(int i=2;i<=n;i++){
    ans = a+b;
    a=b;
    b=ans;
  }
  return ans;
}

// Minimum Steps to 1
int minSteps(int n){
  if(n==1){
    return 0;
  }
  int x = INT_MAX;
  int y = INT_MAX;
  if(n%3==0){
    x = minSteps(n/3);
  }
  if(n%2==0){
    y = minSteps(n/2);
  }
  int z = minSteps(n-1);
  return min(x,min(y,z))+1;
}

// Min Steps to 1 - Bottom up DP
int minStepsBottom(int n){
  vector<int> ans(n+1);
  ans[0]=0;
  ans[1]=0;
  for(int i=2;i<=n;i++){
    int three = INT_MAX, two = INT_MAX, one = INT_MAX;
    if(i%3 == 0){
      three = ans[i/3];
    }
    if(i%2){
      two = ans[i/2];
    }
    one = ans[i-1];
    ans[i] = min(three,min(two,one))+1;
  }
  return ans[n];
}

// Jump from 1 to N in at most K steps at time.
int waysToReach(int n, int k){
  if(n==1){
    return n;
  }




  
}

// Cut rod to maximise profit
int maxProfit(int lenRod,int lenArray[],int priceLen[],int size){
  if(n==1){
    return p[1];
  }
  int maxPro = INT_MIN;
  for(int i=0;i<size;i++){
    maxPro = max(maxProfit(lenRod)+priceLen[],maxPro)
  }
}









//Min Steps to 1 - Top Down DP
int minStepsTop(int n, vector<int> dp){
  
  // Base Case
  if(n==0 or n==1){
    dp[n]=0;
    return dp[n];
  }
  if(dp[n]!=0){
    return dp[n];
  }
  int x =INT_MAX,y=INT_MAX,z=INT_MAX;
  if(n%3==0){
    x = minStepsTop(n/3,dp);
  }
  if(n%2==0){
    y= minStepsTop(n/2,dp);
  }
  z = minStepsTop(n-1,dp);
  
  return dp[n]=min(x,min(y,z))+1;
}

int minCoins(int n, int change[],int size){
  // Base Case
  if(n==0 or n==1){
    return n;
  }
  // 1 , 7 , 10
  int min_val = INT_MAX;
  for(int i=0;i<size;i++){
    if(n-change[i]>=0){
      min_val=min(min_val,minCoins(n-change[i],change,size));
    }
  }
  return min_val+1;
}

int profitWine(int prices[],int start,int end){
  static int profit = 0;
  static int count = 1;
  while(start<end){
    profit+=min(prices[start],prices[end]);
    if(prices[start]<=prices[end]){
      start=start+1;
      count+=1;
      prices[start]*=count;
      prices[end]*=count;
    } else{
      end=end-1;
      count+=1;
      prices[start]*=count;
      prices[end]*=count;
    }
  }
  profit+=prices[start]*count;
  return profit;
}


int minCoinsTop(int n, int change[], int size){
  static vector<int> dp(n+1,0);
  if(n==0 or n==1){
    return n;
  }  
  if(dp[n]!=0){
    return dp[n];
  }
  int min_val = INT_MAX;
  for(int i=0;i<size;i++){
    if(n-change[i]>=0){
      min_val = min(min_val,minCoinsTop(n-change[i],change,size)+1);
    }
  }
  dp[n]=min_val;
  return dp[n];
}

int main(){
  int dp[1000]= {0};
  cout<<fibDP(6)<<endl;
  cout<<fibDPtop(6,dp)<<endl;
  cout<<"Min Steps "<<minSteps(10)<<endl;
  cout<<"Min Steps Bottom : "<<minStepsBottom(10)<<endl;
  vector<int> dpA(101,0);
  cout<<"Min Steps Top : "<<minStepsTop(10,dpA)<<endl;
  int change[3] = {1,7,10};
  cout<<"Min Coins : "<<minCoins(15,change,3);
  cout<<"Min Coins Top :"<<minCoinsTop(15,change,3)<<endl;
  int prices[]={2,3,5,1,4};
  cout<<"Wines Problem"<<profitWine(prices,0,4);
}