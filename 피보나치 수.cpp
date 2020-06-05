#include <string>
#include <vector>
#include <iostream>>

using namespace std;

bool check[100000];
int F[100000];

int fib(int n){
    if( n == 0 ){ F[0] = 0; return 0;} 
    if( n == 1 ){ F[1] = 1; return 1;}
    if( check[n] ){ return F[n];}
    else{
        check[n] = true;
        return F[n] =( fib(n-1) + fib(n-2) ) % 1234567;
    }
}

int solution(int n) {
    int answer = 0;
    check[0] = true; check[1] = true; 
    answer = fib(n);
    return answer;
}