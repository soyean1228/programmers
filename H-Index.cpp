#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0; //h
    sort(citations.begin(),citations.end());
    int max_h = citations[citations.size()-1];
    for(int h=0;h<=max_h;h++){
        int count = 0;
        int no = 0;
        for(int i=0;i<citations.size();i++){
            if( citations[i] >= h ){count++;}
            else{no++;}
        }
        // cout <<h<< " count = " << count << " 나머지" << no << endl;
        if(count >= h && no<= h){
            // cout << h << endl;
            answer = h;
        }
        
    }
    
    return answer;
}