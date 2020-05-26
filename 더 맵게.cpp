#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while( pq.top() < K && pq.size()>1 ){
        int first, second;
        answer++;
        first = pq.top(); pq.pop();
        second = pq.top(); pq.pop();
        pq.push(first + second * 2);
    }
    if(pq.top() < K){
        return -1;
    }
    return answer;
}