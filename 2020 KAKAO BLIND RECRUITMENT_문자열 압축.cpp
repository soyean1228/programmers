#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int len = s.size();
    int count = 0;
    int num = 0;
    for(int i=1;i<=s.size();i++){ //1개 단위로 자름 -> 길이만큼 자르는 경우 
        //i는 몇개 단위로 자르는지를 알려주는 단위 
        len = s.size();
        num = 0;
        for(int j=0;j<s.size();j=j+i){ //1개 단위로 잘랐을 때, 앞에서부터 확인 
            if(j+i > s.length()){
                num = num + s.substr(j).size();
                break;
            } 
            //cout << s.substr(j,i) <<"와" << s.substr(j+i,i) <<endl;
            if(s.substr(j,i) == s.substr(j+i,i)){
                //j부터 i까지를 비교 == j+i부터 i개를 또 비교 
                //같으면 count를 증가
                count++;
            }else if(s.substr(j,i) != s.substr(j+i,i) && count != 0){
                //다르다면, 
                num = num + i + 1;
                //cout << "count = " <<count << endl;
                if(count >= 9 ) num++;
                if(count >= 99 ) num++;
                if(count >= 999 ) num++;
                count = 0;
                //cout << " !" <<endl; ;
            }else if( s.substr(j,i) != s.substr(j+i,i) && count == 0){
                num = num + i;
                //cout << " @" <<endl;
            }
        }
        if(num < len && num != 0) len = num;
        //cout << i << "일때 " << len << endl;
        if(len <= answer) {
            answer = len;
        }
    }
    return answer;
}