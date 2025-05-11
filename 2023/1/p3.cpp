#include <bits/stdc++.h>
#define ll long long
using namespace std;

string str;
int pos=0;

ll calc(bool weight);

int get_digits(){
    int result=0;
    while(pos<str.length() && isdigit(str[pos])){
        result = result*10 + str[pos]-'0';
        ++pos;
    }
    return result;
}

ll fcal(){
    pos += 2;
    ll mx = calc(1), mn = mx;
    while(str[pos] != ')'){
        ++pos;
        ll num = calc(1);
        mx = max(mx, num);
        mn = min(mn, num);
    }
    ++pos;
    return (mx-mn);
}

ll calc(bool weight){
    ll curNum;
    if(isdigit(str[pos])) curNum = get_digits();
    else if(str[pos] == 'f') curNum = fcal();
    if(!weight || str[pos]==',' || str[pos]==')') return curNum;
    while(pos<str.length()){
        if (str[pos] == '+'){
            ++pos;
            curNum += calc(0);
        }
        else if(str[pos] == '*'){
            ++pos;
            curNum *= calc(1);
        }
        if(str[pos]==',' || str[pos]==')') break;
    }
    return curNum;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> str;
    cout << calc(1);
}
