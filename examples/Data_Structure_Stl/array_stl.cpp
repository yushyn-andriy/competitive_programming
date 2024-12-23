#include<iostream>
#include<array>

using namespace std;


void updateArr(array<string, 2> &xarr, int index, string value) {
    xarr[index] = value;
}


void print(const array<string, 2> &xarr) {
    for(auto x: xarr) cout<<x<<endl;
}


int main() {
    array<string, 2> arr;

    arr[0] = "Hello";
    arr[1] = "World";

    print(arr);
    updateArr(arr, 0, "Bye");
    print(arr);

    arr.fill("AY");
    print(arr);


    return 0;
}