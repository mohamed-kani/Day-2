#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotateBrute(vector<vector<int>> &arr,int n,int m){
  vector<vector<int>> ans(n,vector<int> (m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      ans[j][n-i-1]=arr[i][j];
    }
  }
  for(auto it:ans){
    for(auto i:it)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
}
void rotateOptimal(vector<vector<int>> &arr,int n,int m){
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      swap(arr[i][j],arr[j][i]);
    }
  }
  for(int i=0;i<n;i++){
    reverse(arr[i].begin(),arr[i].end());
  }
  for(auto it:arr){
    for(auto i:it)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
}
int main()
{
  int n;
  int m;
  cout<<"Enter row and column of 2-D matrix : ";
  cin>>n>>m;
  vector<vector<int>> arr;
  for(int i=0;i<n;i++)
  {
    vector<int> a;
    cout<<i+1<<" row elements : \n";
    for(int j=0;j<m;j++){
      int num;
      cin>>num;
      a.push_back(num);
    }
    arr.push_back(a);
  }
  cout<<"Brute Forch Approach \n";
  rotateBrute(arr,n,m);
  cout<<"Optimal Approach \n";
  rotateOptimal(arr,n,m);
  return 0;
}