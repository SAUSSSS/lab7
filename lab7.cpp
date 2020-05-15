#include<iostream>
#include<cmath>
#include<fstream>

#include <iostream>
#include <cmath>
 
using namespace std;
 
double f(double x, double y,double z)
{
    return z;
}
 
double g(double x, double y,double z)
{
   return x*exp(-x) - y;
}

double gx(double x, double y1,double z)
{
   return (1-x)*exp(-x) - y1;
}

 int main(){

    int N = 1000;
    double y[N] = {0};
    double z[N] = {0};
    double ay[N] = {0};
    double ayy[N] = {0};
    double xx[N] = {0};
    const double h = 0.01; //step
    double x = 0.0;
    int i = 0;
    y[0] = 1;
    z[0] = 0;

    std::ofstream y1,y2;
    y2.open("y2.dat");

    while(x <= 2){
        x = x + h;
        y[i+1] = y[i] + h*(f(x,y[i],z[i]) + (h/2.)*(f(x,y[i],z[i])));
        z[i+1] = z[i] + h*(g(x,y[i],z[i]) + (h/2.)*(gx(x,z[i],y[i])));
        xx[i] = x;
        i++;
        
        std::cout << y[i-1] << " " << z[i-1]<< std::endl;
        y2 << y[i-1] << " " << z[i-1] << std::endl;
    }
    y2.close();

     return 0;
 }
