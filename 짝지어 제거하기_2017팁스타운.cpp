#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0;
    if(s.empty()){return 1;}
    vector<char> str;
    str.push_back(s[0]);
    for(int i=1;i<s.size();i++){
        if( str.back() == s[i] ){
            str.pop_back();
        }else{
            str.push_back(s[i]);
        }
    }
    // for(int i=0;i<str.size();i++){
    //     cout << str[i] << endl;
    // }
    if(str.empty()){return 1;}
    return answer;
}