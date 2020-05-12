#include<iostream>
#include<cmath>
#include<fstream>
 double y_2(const double &x,const double &y);



//Differential equation
// y" + y = x*exp(-x)  y(0) = 1, y'(0) = 0; x->[0,2]


double a_f(const double &t){
    return cos(t)/2 + (exp(-t) * cos(t) * (cos(t) + t * cos(t) + t * sin(t)))/2 + (exp(-t)*sin(t)*(sin(t)-t*cos(t)+t*sin(t)))/2;
}

double aa_f(const double &t){
    return -(exp(t) * sin(t) + t) / (2 * exp(t));
}


double y_1(const double &x,const double &y){
    //std::cout << y << std::endl;
    return -(x)*exp(-x);   // => y'(0)/1! = 0
}

double y_2(const double &x,const double &y){
    return x*exp(-x) - y;   // => y"(0)*x^2/2! =  - x^2/2!
}




int main(){
    int N = 1000;
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
    double p = y[i];

    while(x <= 2){
        y[i+1] = 1 + x*(x*y_1(x,p)) + (pow(x,2)*(y_2(x,p)))/2.;
        p = y[i+1];
        yy[i+1] = -x  + (pow(x,2)*(y_2(x,yy[i])))/2.;
        ay[i] = a_f(x);
        ayy[i] = aa_f(x);
        x += h;
        xx[i] = x;
        i++;
        std::cout << y[i-1] << " " << ay[i-1]<< std::endl;
    }
    std::cout << y << std::endl;
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
