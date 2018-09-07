/****************************************************************
Solve ax^2 + bx + c = 0 for real roots

return 0 in no error, 1 otherwise
****************************************************************/
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

int quadraticFormula(double a, double b, double c, double& r1, double& r2, complex<double>& ir1, complex<double>& ir2, bool& im) {
  double discriminant = b*b - 4*a*c;

  if(a == 0) return 1;

    if(b < 0){
      // multiply through by -1, so now b>=0
      a = -a; b = -b; c = -c;
    }

  if(discriminant < 0){
    im = true;

    std::complex<double> imr1(-b/(2*a),-sqrt(-discriminant)/(2*a));
    ir1 = imr1;
    std::complex<double> imr2(-b/(2*a),sqrt(-discriminant)/(2*a));
    ir2 = imr2;
  }

  else{
    r1 = -(b + sqrt(discriminant)) / (2*a);
    r2 = -2*c / (b + sqrt(discriminant));
  }
  return 0;
}

int main() {
  double a,b,c,r1,r2;
  complex<double> ir1, ir2;
  bool im = false;
  cout << "Solve ax^2 + bx + c = 0 for its roots.\n" << "Enter a,b,c: ";
  cin >> a >> b >> c;
  
  int error = quadraticFormula(a,b,c,r1,r2,ir1,ir2,im);

  if(error){
    cout << "ERROR: a=0" << endl;
    return 1;
  }
  if(im){
    if(imag(ir1) < 0){
      cout << "Roots are " << real(ir1) << " - " << -imag(ir1) << "i";
    }
    else{
      cout << "Roots are " << real(ir1) << " + " << imag(ir1) << "i";
    }
    if(imag(ir2) < 0){
      cout << " and " << real(ir2) << " - " << -imag(ir2) << "i" << endl;
    }
    else{
      cout << " and " << real(ir2) << " + " << imag(ir2) << "i" << endl;
    }
  }  
  else{
    cout << "Roots are " << r1 << " and " << r2 << endl;
  }
  return 0;
}
