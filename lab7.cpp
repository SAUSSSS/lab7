#include<iostream>
#include<cmath>
#include<fstream>
 



//Differential equation
// y" + y = x*exp(-x)  y(0) = 1, y'(0) = 0; x->[0,2]


double a_f(const double &t){
    return cos(t)/2 + (exp(-t) * cos(t) * (cos(t) + t * cos(t) + t * sin(t)))/2 + (exp(-t)*sin(t)*(sin(t)-t*cos(t)+t*sin(t)))/2;
}

double aa_f(const double &t){

    return -(exp(t) * sin(t) + t) / (2 * exp(t));
}


double y_1(){
    return 0;   // => y'(0)/1! = 0
}

double y_2(const double &x,const double &y0){
    return x*exp(-x) - y0;   // => y"(0)*x^2/2! =  - x^2/2!
}

double norma(double x0, double x1, double y0, double y1)
{
	return sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
}



int main(){
    int N = 10000;
    double y[N] = {0};
    double yy[N] = {0};
    double ay[N] = {0};
    double ayy[N] = {0};
    double xx[N] = {0};
    const double h = 0.01; //step
    double x = 0.0;
    int i = 0;
    y[i] = 1;
    yy[i] = 0;

    while(x <= 2){
        y[i+1] = 1 -  y_1()*x + (pow(x,2)*(y_2(x,y[i])))/2;
        yy[i+1] = -x +  y_1()*x + (pow(x,2)*(y_2(x,yy[i])))/2;
        ay[i] = a_f(x);
        ayy[i] = aa_f(x);
        x += h;
        xx[i] = x;
        i++;
    }
    std::cout << i << std::endl;
    std::ofstream y1,y2;
    y1.open("y1.dat");
    
    y2.open("y2.dat");
    


    for(int j = 0; j < i; j++){
        y1 << y[j] << " " << ay[j] << " " << xx[j] << std::endl;
        y2 << yy[j] << " " << ayy[j] << " " << xx[j] << std::endl;
       

    }
    y1.close();
   
    y2.close();
   
    


    return 0;
}
