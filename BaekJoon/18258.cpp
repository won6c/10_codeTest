#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

/*
 * [방식 2] unordered_map + 람다로 명령 분기 처리 (main과 동일한 동작)
 *
 * - 명령 문자열을 키로, 해당 동작을 수행하는 함수(람다)를 값으로 넣어둠.
 * - 입력된 command로 map에서 바로 함수를 찾아 호출하므로
 *   if-else 체인이 사라지고, 명령 추가/삭제 시 map만 수정하면 됨.
 * - 람다는 [&q]로 큐를 참조 캡처해서 같은 큐를 공유함.
 * - 사용 예: runQueueCommands(testcase);
 */
void runQueueCommands(int testcase) {
    queue<int> q;
    string command;

    auto do_push = [&q]() {
        int num;
        cin >> num;
        q.push(num);
    };
    auto do_pop = [&q]() {
        if (q.empty()) cout << -1 << "\n";
        else { cout << q.front() << "\n"; q.pop(); }
    };
    auto do_front = [&q]() {
        if (q.empty()) cout << -1 << "\n";
        else cout << q.front() << "\n";
    };
    auto do_back = [&q]() {
        if (q.empty()) cout << -1 << "\n";
        else cout << q.back() << "\n";
    };
    auto do_size = [&q]() {
        cout << q.size() << "\n";
    };
    auto do_empty = [&q]() {
        cout << (q.empty() ? 1 : 0) << "\n";
    };

    unordered_map<string, function<void()>> cmd = {
        {"push",  do_push},
        {"pop",   do_pop},
        {"front", do_front},
        {"back",  do_back},
        {"size",  do_size},
        {"empty", do_empty},
    };

    for (int i = 0; i < testcase; i++) {
        cin >> command;
        cmd[command]();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase;
    string command;
    cin >> testcase;
    queue<int> q;
    for(int i = 0 ; i < testcase ; i++){
        cin >> command;
        if(0 == command.compare("push")){
            int num;
            cin >> num;
            q.push(num);
        }else if(0 == command.compare("pop")){
            if(q.empty()){
                cout << -1 << "\n";
            }else{
                cout << q.front() << "\n";
                q.pop();
            }
        }else if(0 == command.compare("front")){
            if(q.empty()){
                cout << -1 << "\n";
            }else{
                cout << q.front() << "\n";
            }
        }else if(0 == command.compare("back")){
            if(q.empty()){
                cout << -1 << "\n";
            }else{
                cout << q.back() << "\n";
            }
        }else if(0 == command.compare("size")){
            cout << q.size() << "\n";
        }else if(0 == command.compare("empty")){
            if(q.empty()){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}