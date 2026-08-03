#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double Re, Im;
}
Complex_t;

Complex_t scanComplex(){
    Complex_t x;
    scanf("%lf %lf", &x.Re, &x.Im);
    return x;
}

Complex_t setComplex(double r, double i){
    Complex_t x;
    x.Re = r;
    x.Im = i;
    return x;
}
void printComplex(Complex_t x) {
    printf("%+.2lf ", x.Re);
    if(x.Im < 0) {
        printf("- ");
        x.Im = -x.Im;
    }else{
        printf("+ ");
    }
    printf("i%.2lf\n", x.Im);
}
Complex_t conjungate(Complex_t x) {
    x.Im *= -1;
    return x;
}
double absComplex(Complex_t  x){
    return
     sqrt(pow(x.Re, 2) + pow(x.Im, 2));
}
Complex_t add(Complex_t a, Complex_t b) {
    Complex_t c;
    c.Re = a.Re + b.Re;
    c.Im = a.Im + b.Im;
    return c;
}
Complex_t mult(Complex_t a, Complex_t b) {
    Complex_t c;
    c.Re = a.Re * b.Re - a.Im * b.Im;
    c.Im = a.Re * b.Im + b.Re * a.Im;
    return c;
}
Complex_t division(Complex_t a, Complex_t b) {
    Complex_t c,d;
    d = b;
    d = conjungate(d);
    c = mult(a, d);
    d = mult(b, d);
    double con = d.Re;
    c.Re = c.Re / con;
    c.Im = c.Im / con;
    return c;
}


int main(){
    Complex_t a, b, c;
    a = setComplex(1.5, -3.2);
    b = setComplex(-2.4, 5.6);
    printComplex(a);
    printComplex(b);
    printComplex(conjungate(a));
    printComplex(conjungate(b));
    printf("%.2lf ", absComplex(a));
    printf("%.2lf\n", absComplex(b));
    printComplex(add(a,b));
    printComplex(mult(a,b));
    printComplex(division(a,b));
    return 0;
}
