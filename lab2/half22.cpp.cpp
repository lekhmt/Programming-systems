//half22.cpp
#include "mlisp.h"
double root(double a, double b);
double half__interval(double a, double b, double fa, double fb);
double __MVL__try(double neg__point, double pos__point);
bool close__enough_Q(double x, double y);
double average(double x, double y);
double f(double z);
extern double total__iterations;
extern double tolerance;

double root(double a, double b){
    double temp (0.);
    temp = half__interval(a, b, f(a), f(b));
    display("Total number of iterations=");
    display(total__iterations);
    newline();
    display("[");
    display(a);
    display(" , ");
    display(b);
    display("]");
    return temp;
}

double half__interval(double a, double b, double fa, double fb){
    double root (0.);
    total__iterations = 0.;
    root = (((fa < 0.) && (fb > 0.)) ? __MVL__try(a, b) :
            ((fa > 0.) && (fb < 0.)) ? __MVL__try(b, a) :
            b + 1.);
    newline();
    return root;
}

double __MVL__try(double neg__point, double pos__point){
    double midpoint (0.);
    double test__value (0.);
    midpoint = average(neg__point, pos__point);
    display("+");
    total__iterations = total__iterations + 1.;
    return ((close__enough_Q(neg__point, pos__point)) ? midpoint :
            (test__value = f(midpoint), ((test__value > 0.) ? __MVL__try(neg__point, midpoint) :
                                         (test__value < 0.) ? __MVL__try(midpoint, pos__point) :
                                         midpoint)
            )
    );
}

bool close__enough_Q(double x, double y){
    return (abs(x - y) < tolerance);
}

double average(double x, double y){
    return (x + y) * (1. / (1. * 2.0));
}


double tolerance = 0.001;
double total__iterations = 0.;

double f(double z){
    return 2 * sin(z) * cos(z) + 0.5;
}

int main(){
    display("Variant 206-12\n");
    display(root(1., 2.35));
    newline();
    display("(c) Matvey Leukhin 2022\n");
    return 0;
}













