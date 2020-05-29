#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    vector<int> num;
    for(int i=0;i<priorities.size();i++){
        pq.push(priorities[i]);
        q.push(make_pair(i,priorities[i]));
    }
    while(!pq.empty()){
        if(pq.top() == q.front().second){
            num.push_back(q.front().first);
            pq.pop();
            q.pop();
        }else{
            pair<int,int> tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    for(int i=0;i<num.size();i++){
        if(location == num[i]){
            answer = i+1;
        }
    }
    return answer;
}