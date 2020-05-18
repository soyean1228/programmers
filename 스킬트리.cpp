#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> skill_order;
    vector<char>::iterator tmp;
    for(int i=0;i<skill.size();i++){
        skill_order.push_back(skill[i]);
    }
    for(int i=0;i<skill_order.size();i++){
        cout << skill_order[i] << " " ;
    }
    cout << endl;
    for(int i=0;i<skill_trees.size();i++){
        bool possible = false;
        string s = skill_trees[i];
        int get_n = 0;
        int j=0;
        for(j=0;j<s.size();j++){
            tmp = find(skill_order.begin(),skill_order.end(),s[j]);
            if(tmp!=skill_order.end()){ //있으면
                if(skill_order[get_n] == s[j]){
                    cout << *tmp << endl;
                    possible = true;
                    get_n++;
                }else{
                    possible = false;
                    break;
                }
            }
        }
        if( j==s.size() || possible) { answer ++ ;}
        cout << answer << "  " << skill_trees[i] << endl;
    }
    return answer;
}