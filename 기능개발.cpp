#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<pair<int,int>> day_p;
    for(int i=0;i<progresses.size();i++){
        int day =(100 - progresses[i])/speeds[i];
        if( (100 - progresses[i])%speeds[i] != 0 ) { day++; }
        day_p.push_back(make_pair(day,i));
    }
    
    cout << "출력" << endl;
    for(int i=0;i<day_p.size();i++){
        cout << day_p[i].first << endl;
    }
    cout << endl;
    
    int max = day_p[0].first;
    int num = 1;
    for(int i=1;i<day_p.size();i++){
        if(max>=day_p[i].first){num++;}
        else{
            answer.push_back(num);
            max = day_p[i].first;
            num = 1;
        }
    }
    if(num !=0) answer.push_back(num);
    return answer;
}