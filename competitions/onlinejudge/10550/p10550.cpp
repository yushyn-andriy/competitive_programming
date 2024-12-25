#include <iostream>

using namespace std;


#define DEGREES_PER_ANGLE 9


int solve(int a, int b, int c, int d) {
    int t_angle = 1080;
    if(a >= b) t_angle += (a - b) * DEGREES_PER_ANGLE;    
    else if(a < b) t_angle += (a + (40 - b))* DEGREES_PER_ANGLE;

    if(c >= b) t_angle += (c - b) * DEGREES_PER_ANGLE;    
    else if(c < b) t_angle += (c + (40 - b))* DEGREES_PER_ANGLE;

    if(c >= d) t_angle += (c - d) * DEGREES_PER_ANGLE;    
    else if(c < d) t_angle += (c + (40 - d))* DEGREES_PER_ANGLE;

    return t_angle;
}



int main() {
    int a, b, c, d;
    while(cin>>a>>b>>c>>d) {
        if(a == 0 && b == 0 && c == 0 && d == 0) break;
        cout<<solve(a, b, c, d)<<endl;
    }
    return 0;
}