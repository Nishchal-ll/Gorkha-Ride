#include <iostream>
#include <stack>
#include <string>
using namespace std;

class pda{
public:
    bool check(string& input) {
        stack<char> stack;

        for (int i = 0; i < input.length(); ++i) {
          char ch = input[i];
            if (ch == '0') {
                stack.push(ch);
            } else if (ch == '1') {
                if (stack.empty()) {
                    return false; 
                }
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
};

int main() {
    pda p;
    string input;
    cout << "Enter a string of '0's and '1's: ";
    cin >> input;
    if (p.check(input)) {
        cout << "String has equal 0 and 1";
    } else {
        cout << "String doesnt have equal 0 and 1";
    }
    return 0;
}

