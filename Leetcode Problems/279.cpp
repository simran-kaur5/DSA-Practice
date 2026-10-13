#include <iostream>
#include <stack>
#include <utility>
using namespace std;

class MyCalendar {
public:
    stack<pair<int, int>> s;

    MyCalendar() {
    }

    bool book(int startTime, int endTime) {
        stack<pair<int, int>> temp = s;

        while (!temp.empty()) {
            auto [st, e] = temp.top();
            temp.pop();

            if (st < endTime && startTime < e) {
                return false;
            }
        }

        s.push({startTime, endTime});
        return true;
    }
};

int main() {
    MyCalendar* obj = new MyCalendar();

    cout << boolalpha;
    cout << obj->book(10, 20) << endl; // true
    cout << obj->book(15, 25) << endl; // false
    cout << obj->book(20, 30) << endl; // true
    cout << obj->book(5, 10) << endl;  // true

    delete obj;
    return 0;
}
