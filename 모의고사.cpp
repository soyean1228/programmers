#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a {1,2,3,4,5};
    vector<int> b {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<pair<int,int>> score;
    int a_s = 0; int b_s = 0; int c_s = 0; int n;
    for(int i=0;i<answers.size(); i++){
        if(i >= a.size()){
            n = i % a.size();
            if(a[n] == answers[i]){
                a_s++;
            }
        }else{
            if(a[i] == answers[i]){
                a_s++;
            }
        }
        if(i >= b.size()){
            n = i % b.size();
            if(b[n] == answers[i]){
                b_s++;
            }
        }else{
            if(b[i] == answers[i]){
                b_s++;
            }
        }
        if(i >= c.size()){
            n = i % c.size();
            if(c[n] == answers[i]){
                c_s++;
            }
        }else{
            if(c[i] == answers[i]){
                c_s++;
            }
        }
        
    }
    score.push_back(pair<int,int>(a_s,1));
    score.push_back(pair<int,int>(b_s,2));
    score.push_back(pair<int,int>(c_s,3));
    sort(score.begin(),score.end());
    for(int i=0;i<score.size();i++){
        cout<<score[i].first << " " <<score[i].second << endl;
    }
    for(int i=2;i>=0;i--){
        answer.push_back(score[i].second);
        if((score[i].first != score[i-1].first) || (i==0)){
            break;
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}