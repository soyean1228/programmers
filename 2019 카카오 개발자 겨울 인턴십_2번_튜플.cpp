#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> strSet;
    s = s.substr(1,s.size()-2);
        
    string str = "";
    for(int i=0;i<s.size();i++){
        str += s[i];
        if(s[i] == '}'){
            i++;
            strSet.push_back(str);
            str = "";
        }
    }
    
    sort(strSet.begin(),strSet.end(),cmp);
    
    for(int i=0;i<strSet.size();i++){
        string tmp = strSet[i].substr(1,strSet[i].size()-2);
        //cout << tmp << endl;
        string t = "";
        for(int j=0;j<tmp.size();j++){
            if(isdigit(tmp[j])){
                t += tmp[j];
            }else{
                if(find(answer.begin(),answer.end(),atoi(t.c_str())) == answer.end()){
                    answer.push_back(atoi(t.c_str()));
                }
                t = "";
            }
        }
        if(find(answer.begin(),answer.end(),atoi(t.c_str())) == answer.end()){
            answer.push_back(atoi(t.c_str()));
        }
    }
    
    return answer;
}