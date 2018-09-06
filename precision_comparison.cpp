#include <iostream>
#include <string>
#include <cmath>

typedef double (* vFunctionCall)(int args);

class Fun{
    double result;
public:
    void set_fun(vFunctionCall);
    void show(){
        std::cout << std::scientific;
        std::cout << result;
        std::cout << "\n";
    }
};

void Fun::set_fun(vFunctionCall res){
    for(int i=-1 ; i >= -14 ; i--){
        double x = pow(10,i);
        Fun result;
        result.result = res(x);
        result.show();
    }
}

double func_a(double x){
    return (1-(1/cos(x)))/pow(tan(x),2);
}

double func_a_conjugate(double x){
    return (1-(1/pow(cos(x),2)))/(pow(tan(x),2)*(1+(1/cos(x))));
}

double func_b(double x){
    return (1-pow((1-x),3))/x;
}

double func_b_conjugate(double x){
    return (1-pow((1-x),6))/(x*(1+pow((1-x),3)));
}

int main()
{
    Fun result;
    
    // Standard double precision (a)
    result.set_fun((vFunctionCall)func_a);
    std::cout << "\n";
    
    // Conjugate method (a)
    result.set_fun((vFunctionCall)func_a_conjugate);
    std::cout << "\n";
    
    
    // Standard double precision (b)
    result.set_fun((vFunctionCall)func_b);
    std::cout << "\n";
    
    // Conjugate method (b)
    result.set_fun((vFunctionCall)func_b_conjugate);
    std::cout << "\n";
    
    return 0;
}
