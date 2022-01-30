#include <iostream>
#include <vector>
using namespace std;

// Kadane's Algorithm for Maximum Sum Contiguos Subarray - O(n)
int maxSubArray(vector<int>& arr) {
  int curr = 0;
  int max = INT_MIN;
  for(int i=0;i<nums.size();i++){
    curr = curr + arr[i];
    if(curr>max)
      max = curr;
    if(curr<0)
      curr = 0;
  }
  return max;
}

int main(){
  return 0;
}