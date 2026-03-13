#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
 * 괄호 검사(VPS)를 스택 대신 숫자(열린 괄호 개수)로 판단.
 * '('면 count++, ')'면 count--. 중간에 count < 0 이면 불균형, 끝에 count != 0 이면 불균형.
 * 빈 문자열은 count가 0으로 끝나므로 true 반환. (문제에서 빈 입력을 NO로 보면 호출 전에 따로 검사)
 */
bool isVPSWithCounter(const string& s) {
    int count = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            count++;
        else {
            count--;
            if (count < 0)
                return false;
        }
    }
    return count == 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++){
        string vps;
        stack<char> s;
        cin >> vps;
        int len = vps.length();
        for(int j = 0 ; j < len ; j++){
            if(vps[j] == '('){
                s.push(vps[j]);
            }else{
                if(s.empty()){
                    cout << "NO" << "\n";
                    break;
                }else{
                    s.pop();
                }
            }
            if(j == len - 1 && s.empty()){
                cout << "YES" << "\n";
            }else if(j == len - 1){
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}