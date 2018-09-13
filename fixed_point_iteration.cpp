#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>

using namespace std;

typedef double (* vFunctionCall)(int args);

class Fun{
    int count;
    double x_i;
    bool converged;

public:
    vFunctionCall res;
    vFunctionCall res_prime;
    double guess;
    double max_iter;
    /*************************************
     * given f(x), g(x) = x - f(x)/f'(r)
     * where r is a guess for the root of
     * f(x).
     *************************************/
    
    double func_g(vFunctionCall res, vFunctionCall res_prime, double x, double guess){
        return (x - (res(x)/res_prime(guess)));
    }
    
    // fixed point iteration
    void fpi(){
        x_i = guess;
	double delta_x;
	double x_o;
        converged = false;
        for(int i=0 ; i <= max_iter ; i++){
	    x_o = x_i;
            x_i = func_g(res,res_prime,x_i,guess);
            delta_x = abs(x_o - x_i)/x_o;
            count = i + 1;
            if(delta_x < pow(10,-9)){
                converged = true;
                break;
            }
        }
    }
    void show(){
	if(converged){
        	std::cout << x_i;
        	std::cout << "\n";
	}
	else{
		std::cout << "Function does not converge\n";
	}
    }
};

double func_a(double x){
    return (pow(x,5) + x - 1);
}

double func_a_prime(double x) {
    return (5*pow(x,4) + 1);
}

double func_b(double x){
    return (sin(x) - 6*x - 5);
}

double func_b_prime(double x){
    return (cos(x) - 6);
}

double func_c(double x){
    return (log(x) + pow(x,2) - 3);
}

double func_c_prime(double x){
    return (1/x + 2*x);
}

int main()
{
    // fpi func (a)
    Fun resulta;
    resulta.res = (vFunctionCall)func_a;
    resulta.res_prime = (vFunctionCall)func_a_prime;
    resulta.guess = 2.582000001;
    resulta.max_iter = 100000;
    resulta.fpi();
    resulta.show();
    std::cout << "\n";
    
    // fpi func (b)
    Fun resultb;
    resultb.res = (vFunctionCall)func_b;
    resultb.res_prime = (vFunctionCall)func_b_prime;
    resultb.guess = 2.582000001;
    resultb.max_iter = 100000;
    resultb.fpi();
    resultb.show();
    std::cout << "\n";
    
    
    // fpi func (c)
    Fun resultc;
    resultc.res = (vFunctionCall)func_c;
    resultc.res_prime = (vFunctionCall)func_c_prime;
    resultc.guess = 2.58200001;
    resultc.max_iter = 100000;
    resultc.fpi();
    resultc.show();
    std::cout << "\n";
    
    return 0;
}
