#include<iostream>


using namespace std;



int get_min_sonar_count(int x, int y) {
    return (x/3) * (y/3);
}


int main() {
    int n;
    cin>>n;

    int x, y;
    while(n--) {
        cin>>x>>y;
        cout<<get_min_sonar_count(x, y)<<endl;
    }


    return 0;
}