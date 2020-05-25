#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n!=0){
        if(n % 3 == 0 ){
            answer += to_string(4);
            n = (n/3)-1;
        }else{
            answer += to_string(n%3);
            n = n/3;
        }
    }
    string ans = "";
    for(int i=answer.size()-1;i>=0;i--){
        ans += answer[i];
    }
    return ans;
}