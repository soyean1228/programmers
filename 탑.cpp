#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	stack<int> st;
	bool check = true;

	for ( int i = heights.size() - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (heights.at(j) > heights.at(i)) {
				st.push(j + 1);
				check = false;
				break;
			}
		}
		if (check == true) {
			st.push(0);
		}
		check = true;
	}

	while (!st.empty()) {
		answer.push_back(st.top());
		st.pop();
	}
	return answer;
}