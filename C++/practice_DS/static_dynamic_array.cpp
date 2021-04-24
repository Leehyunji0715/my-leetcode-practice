#include <iostream>
#include <vector>
using namespace std;

// static & dynamic array
// array [] VS pointer

int main(){

    // static array
    int arr[5] = {1, 2, 3, 4, 5};



    // dynamic memory (pointer)
    int * ptr;
    ptr = new int [10];
    if(ptr == nullptr)
    {
        cout << "Error of assigning memory\n";
        exit(0);
    }
    delete [] ptr;



    // dynamic memory (vector)
    cout << "\nvector\n";
    vector<int> v;
    vector<int>::iterator iter;
    vector<int>::reverse_iterator r_iter;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0; i< v.size(); i++){
        cout << v.at(i) << ", " ;
    }
    cout << endl;

    v.pop_back();
    
    for(iter=v.begin(); iter != v.end(); iter++){
        cout << *iter << ", " ;
    }

    cout << "\n";
    for(r_iter=v.rbegin(); r_iter!=v.rend(); r_iter++){
        cout << *r_iter << ", " ;
    }

}
