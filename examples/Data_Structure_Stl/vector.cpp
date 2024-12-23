#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


int main() {
    vector<int> matrix;

    matrix.push_back(1);
    matrix.push_back(2);
    matrix.push_back(3);

    cout<<"Front: "<<matrix.front()<<endl;
    cout<<"Back: "<<matrix.back()<<endl;
    cout<<"Size: "<<matrix.size()<<endl;
    cout<<"At(0): "<<matrix.at(0)<<endl;

    matrix.clear();
    cout<<"Size: "<<matrix.size()<<endl;
    cout<<"Empty: "<<matrix.empty()<<endl;

    vector<int> second(2, 33);
    for(auto x: second) cout<<x<<endl;

    return 0;
}

