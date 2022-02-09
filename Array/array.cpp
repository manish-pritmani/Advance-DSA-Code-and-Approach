#include <iostream>
#include <vector>
#include <climits>
// #include<bits/stdc++.h>
using namespace std;

void reverseArray(int* arr, int n){
  int start=0,end=n-1;
  while(start<end){
    swap(arr[start],arr[end]);
    start=start+1;
    end=end-1;
  }
}




// Moore Voting Algorithm
int findMajor(int arr[], int n){}





// Best time to buy sell stock





// Kadane's Algorithm for Maximum Sum Contiguos Subarray - O(n)
int maxSubArray(vector<int>& arr) {
  int curr = 0;
  int max = INT_MIN;
  for(int i=0;i<arr.size();i++){
    curr = curr + arr[i];
    if(curr>max)
      max = curr;
    if(curr<0)
      curr = 0;
  }
  return max;
}

void printArray(int* arr,int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  } 
}

int main(){
  int arr[]={1,2,3,4,5,6};
  reverseArray(arr,6);
  printArray(arr,6);
  return 0;
}