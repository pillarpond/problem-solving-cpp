//geom

#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

using namespace std;

int main() {
    float r = 0;
    cin >> r;

    printf("%.6f\n", M_PI * pow(r, 2));
    printf("%.6f\n", 2 * pow(r, 2));
    return 0;
}