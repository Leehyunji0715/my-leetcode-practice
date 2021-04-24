
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
    
int main(){
    // queue
    queue<int> q;
    q.push(1); 
    q.push(2);
    cout << q.front() << ", " << q.back();
    q.pop();
    q.pop();
    cout << q.empty() << "\n\n";


    // dequeue (with iterator)
    deque<int> dq;
    deque<int>::iterator iter;
    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(3);
    dq.push_back(4);

    for(int i=0; i<4; i++)
        cout << dq[i] << ", "; // or dq.at(i)
    cout << endl;

    for(iter=dq.begin(); iter!=dq.end(); iter++)
        cout << *iter << ", ";
    cout << endl;
    dq.pop_front();
    dq.pop_back();

    for(int i=0; i<dq.size(); i++)
        cout << dq.at(i) << ", ";
    cout << endl;

    dq.clear();
}