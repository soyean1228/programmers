#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string a, string b){
    if(a[0] < b[0]){ return false;}
    else if(a[0] == b[0]){
        return stoi(a+b) > stoi(b+a);
    }
    return true;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_numbers;
    bool allOne = true;
    for(int i=0;i<numbers.size();i++){
        str_numbers.push_back(to_string(numbers[i]));
        if(numbers[i] != 0) {allOne = false;}
    }
    if( allOne ) { cout << " 0 " << endl; return "0";};
    sort(str_numbers.begin(),str_numbers.end(),compare);
    for(int i=0;i<str_numbers.size();i++){
        // cout << str_numbers[i] << endl;
        answer += str_numbers[i];
    }
    return answer;
}