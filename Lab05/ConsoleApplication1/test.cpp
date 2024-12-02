#include <iostream>
#include <stack> // Thư viện stack trong C++
using namespace std;

int main() {
    stack<int> myStack;

    // Thêm phần tử vào ngăn xếp (push)
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top element before pop: " << myStack.top() << endl; // Output: 3

    // Loại bỏ phần tử trên cùng (pop)
    myStack.pop();

    cout << "Top element after pop: " << myStack.top() << endl; // Output: 2

    return 0;
}
