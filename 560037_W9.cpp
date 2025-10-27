/**
 * Program C++ untuk Soal Latihan Chapter 6, Nomor 8
 * * Program ini menghitung radius, diameter, keliling, dan luas lingkaran
 * berdasarkan input titik pusat dan satu titik pada lingkaran.
 */
#include <iostream> 
#include <cmath>   

using namespace std;
const double PI = 3.1416;

double distance(double x1, double y1, double x2, double y2);
double radius(double centerX, double centerY, double pointX, double pointY);
double circumference(double r);
double area(double r);

int main() {
    
    double centerX, centerY; 
    double pointX, pointY;   
    double rad, diam, circ, ar; 
    
    cout << "Enter the center of the circle (x y): ";
    cin >> centerX >> centerY;

    cout << "Enter a point on the circle (x y): ";
    cin >> pointX >> pointY;

    rad = radius(centerX, centerY, pointX, pointY); 
    diam = 2.0 * rad;
    circ = circumference(rad); 
    ar = area(rad); 
    cout << "\n--- Circle Properties ---" << endl;
    cout << "Radius:        " << rad << endl;
    cout << "Diameter:      " << diam << endl;
    cout << "Circumference: " << circ << endl;
    cout << "Area:          " << ar << endl;

    return 0; 
}
double distance(double x1, double y1, double x2, double y2) {
    double term1 = pow(x2 - x1, 2.0);
    double term2 = pow(y2 - y1, 2.0);
    return sqrt(term1 + term2);
}

double radius(double centerX, double centerY, double pointX, double pointY) {
    return distance(centerX, centerY, pointX, pointY);
}

double circumference(double r) {
    return 2.0 * PI * r;
}
double area(double r) {
    return PI * pow(r, 2.0);
}
