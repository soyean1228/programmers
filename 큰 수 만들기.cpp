#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start = 0;
    for(int i=0;i<number.size()-k ;i++){
        int maxIdx = start;
        int maxNum = number[start];
        for(int j=start;j<=k+i;j++){
            if(maxNum < number[j]){
                maxNum = number[j];
                maxIdx = j;
            }
        }
        answer += maxNum;
        start = maxIdx + 1;
    }
    return answer;
}