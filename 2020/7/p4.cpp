#include <bits/stdc++.h>
#define MAXN 2e9
#define MOD 1e9+7
#define pb push_back
#define ll long long
using namespace std;

int n,m;
vector<vector<int> > v;
vector<vector<int> > rna;
vector<vector<int> > dp;

void findMin(const int &node){
    for(auto &s:vs[node]){

    }
}

int main(){
    cin >> n >>m; 
    v.resize(n+1); rna.resize(n+1,vector<int>(5,0));
    int a,b,root; string s;
    for(int i=0; i<n; ++i){
        cin >> a >> b >> s;
        if(a == b) root = a;
        else rna[b].pb(a);
        for(auto &it:s){
            switch(it){
                case 'A': rna[a][0] +=1; break;
                case 'U': rna[a][1] +=1; break;
                case 'C': rna[a][2] +=1; break;
                case 'G': rna[a][3] +=1; break;
                case '@': rna[a][4] +=1; break;
            }
        }
    }
    dp.resize(n+1,4);
    ll ans=0;
    findMin(root);
}