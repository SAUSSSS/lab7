#include<iostream>
#include<cmath>
#include<fstream>
 



//Differential equation
// y" + y = x*exp(-x)  y(0) = 1, y'(0) = 0; x->[0,2]



double yp_x(const double &x,const double &y){
    return -pow(x,2)/2;
}

double ypp_x (const double &x,const double &y){
    return -(1+x)*exp(-x) - y*x ;
}

double ypp_y(const double &x,const double &y1){
    return -1;
}
 
double norma(double x0, double y0, double x1, double y1)
{
	return sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
}



int main(){
    int N = 10000;
    double res[N] = {0};
    const double h = 0.01;
    double x = 0.0;
    res[0] = 0;
    int i = 0;
    while(x <= 2){
        res[i + 1] =  res[i] + h*(ypp_x(x,res[i]) + (h/2) *(-1)*(yp_x(x,res[i]) + yp_x(x,res[i])));
        x += 0.01;
        i++;
    }

    std::ofstream out;
    out.open("data.dat");

    for(int j = 0; j < i; j++){
        out << res[j] << std::endl;
    }
    out.close();
    


    return 0;
}
