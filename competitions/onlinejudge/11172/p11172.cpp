#include<iostream>


using namespace std;


int main() {
    int n, a, b;
    cin>>n;
    while(cin>>a>>b) {
        if(a<b) cout<<"<"<<endl;
        else cout<<(a == b ? "=" : ">")<<endl;
    }

    return 0;
}