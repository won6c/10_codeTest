#include <iostream>
#include <queue>
using namespace std;

/*
 * 1번부터 N번까지 N명의 사람이 원을 이루어 앉음
 * 양의 정수 K(<=N)
 * 순서대로 K번째 사람 제거(모두 제거될 때까지 계속)
 * 원에서 제거되는 순서를 (N, K) - 요세푸스 순열
 *
 * ex) (7, 3) => <3, 6, 2, 7, 5, 1, 4>
 *
 */

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	queue<int> q;

	for(int i = 1 ; i <= N ; i++){
		q.push(i);
	}
	cout << '<';
	while(!q.empty()){
		for(int i = 0 ; i < K-1 ; i++){
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if(!q.empty()){
			cout << ", ";
		}
	}

	cout << '>';

	return 0;
}
