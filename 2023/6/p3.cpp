#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

string str;
int pos=0, cur=10, ans=0;

int get_digits(){
    int num=0;
    while(pos<str.length() && isdigit(str[pos])){
        num = num*10 + str[pos]-'0';
        ++pos;
    }
    return num;
}

int calc(){
    int newnum;
    while(pos < str.length()){
        if(str[pos] == 'T'){
            ++pos;
            newnum = get_digits();
            ans += abs(newnum - cur);
            cur = newnum;
        }
        else if(str[pos] == 'L'){
            ++pos;
            int times = get_digits(), start = pos;
            while(times--){
                pos = start;
                newnum = calc();
            }
        }
        else if(str[pos] == 'E') {
            ++pos;
            break;
        }
    }
    return newnum;
}

int main(){
    cin >> str;
    calc();
    cout << ans;
}
