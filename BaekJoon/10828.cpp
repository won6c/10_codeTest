#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string cmd;
    cin >> t;
    stack<int> s;
    for(int i = 0 ; i < t ; i++){
        cin >> cmd;
        if(cmd=="push"){
            int x;
            cin >> x;
            s.push(x);
        }else if(cmd=="pop"){
            if(s.empty()){
                cout << -1 << "\n";
            }else{
                cout << s.top() << "\n";
                s.pop();
            }
        }else if(cmd=="top"){
            if(s.empty()){
                cout << -1 << "\n";
            }else{
                cout << s.top() << "\n";
            }

        }else if(cmd=="size"){
            cout << s.size() << "\n";

        }else if(cmd=="empty"){
            if(s.empty()){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }

        }
    }
    
    return 0;
}