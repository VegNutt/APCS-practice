#include <bits/stdc++.h>
using namespace std;

vector<int> rof;
int n,p,maxSum=0;

int recursion(int node, int sum){  
    if(node == n){
        if(sum <= p) maxSum = max(maxSum, sum);
        return -1;
    }
    recursion(node+1, sum+rof[node]);
    recursion(node+1, sum);
    return maxSum;
}

int main(){
    cin >> n >> p;
    int input;         
    for(int i=0; i<n; ++i){
        cin >> input;
        rof.push_back(input);
    }
    cout << recursion(0,0);
}
//so hard