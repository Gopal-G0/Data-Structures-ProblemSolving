#include<bits/stdc++.h>
using namespace std;

int main() {
    
    //creating a queue for integers
    queue<int> que;

    que.push(5);

    cout << "Back of queue : " << que.back() << endl;

    que.push(10);

    cout << "Back of queue : " << que.back() << endl;
    
    que.push(4);

    cout << "Back of queue : " << que.back() << endl;

    que.push(2);

    cout << "Back of queue : " << que.back() << endl;

    cout << "Size of queue : " << que.size() << endl;

    que.pop();

    cout << "Size of queue : " << que.size() << endl;

    if(que.empty()) {
        cout << "Queue is Empty." << endl;
    }

    else {
        cout << "Queue is not Empty." << endl;
    }


    return 0;
}