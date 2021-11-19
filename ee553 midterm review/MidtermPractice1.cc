#include <iostream>
#include <cmath>

using namespace std;

//Option 1
void rect_to_polar(double x, double y, double& r, double& theta){
    r = sqrt(x*x+y*y);
    theta = atan2(x,y);
}

//Option 2 - This form is better, more obvious
void rect_to_polar(double x, double y, double* r, double* theta){
    *r = sqrt(x*x+y*y);
    *theta = atan2(x,y);
}


void minmax(int a, int b, int& min, int& max){
    if(a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }
}

int main(){
    double x = 3, y = 4;
    double r, theta;
    cout << x << " " << y << " " << r << " "<< theta << "\n";
    rect_to_polar(x, y, r, theta); //Option 1
    cout << x << " " << y << " " << r << " "<< theta << "\n";
    rect_to_polar(x, y, &r, &theta); //Option 2
    cout << x << " " << y << " " << r << " "<< theta << "\n";
}