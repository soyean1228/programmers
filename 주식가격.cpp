#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0;i<prices.size()-1;i++){
        int num = 0; // 숫자
        int n = prices[i];
        // cout << n <<"과 비교했을 때" << endl;
        for(int j = i+1; j < prices.size();j++){
            // cout << prices[j] <<" ";
            if( prices[j] >= n ){
                // cout << "yes"<<endl;
                num++;
            }else{
                num++;
                // cout << "no " << endl; 
                break; 
            }
        }
        // cout << n << " == "<< num << endl;
        answer.push_back(num);
    }
    answer.push_back(0);
    return answer;
}
