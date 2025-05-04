#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int row, col, M; cin >> row >> col >> M;
    vector<vector<int>> matrix(row, vector<int>(col));
    for(auto &row:matrix){
        for(auto &it:row) cin >> it;
    }
    vector<int> movement(M);
    for(int i=0; i<M; i++) cin >> movement[i];
    for(int i=M-1; i>=0; i--){
        row = matrix.size();
        col = matrix[0].size();
        //左90度
        if(movement[i] == 0){
            vector<vector<int>> next(col, vector<int>(row));
            for(int p=0; p<next.size(); p++){
                for(int q=0; q<next[0].size(); q++){
                    next[p][q] = matrix[q][matrix[0].size()-1-p];
                }
            }
            matrix = move(next);
;       }
        //上下翻轉
        else{
            reverse(matrix.begin(), matrix.end());
        }
    }
    cout << matrix.size() << " " << matrix[0].size();
    for(auto& row:matrix){
        cout << endl;
        for(int j=0; j<row.size(); j++){
            cout << row[j];
            if(j != row.size()-1) cout << " ";
        }
    }
}
