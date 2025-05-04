#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num, input; cin >> num;
    vector<int>students;
    while(num--){
        cin >> input;
        students.push_back(input);
    }
    sort(students.begin(), students.end());
    for(int i=0; i<students.size(); i++){
        cout << students[i];
        if(i != students.size()-1) cout << " ";
        else cout << endl;
    }
    bool done = false;
    for(int i=0; i<students.size(); i++){
        if(students[i] >= 60){
            if(!done){
                if(i == 0) cout << "best case" << endl;
                else cout << students[i-1] << endl;
                cout << students[i];
                done = true;
                break;
            }
        }
    }
    if(!done) cout << students[students.size()-1] << "\nworst case";
}
