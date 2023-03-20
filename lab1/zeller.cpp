//zeller.cpp
#include "mlisp.h"
double day__of__week();
double zeller(double d, double m, double y, double c);
double neg__to__pos(double d);
double birthday(double dw);
extern double dd;
extern double mm;
extern double yyyy;

double day__of__week(){
    return zeller(dd,
                  10. + (mm <= 2. ? mm : mm - 12.),
                  remainder(1. + (mm < 3. ? yyyy - 2. : true ? yyyy - 1. : _infinity), 100.),
                  quotient((2. >= mm ? yyyy - 1. : yyyy), 100.)
    );
}

double zeller(double d, double m, double y, double c){
    return neg__to__pos(remainder(d + y
                                  + quotient(26. * m - 2., 10.)
                                  + quotient(y, 4.)
                                  + quotient(c, 4.)
                                  + 2. * (-c),
                                  7.)
    );
}

double neg__to__pos(double d){
    return (d < 0. ? d + 7.
                   : true ? d
                          : _infinity
    );
}
double birthday(double dw){
    display("Matvey Leukhin was born on ");
    display(dw == 1. ? "Monday " :
            dw == 2. ? "Tuesday " :
            dw == 3. ? "Wednesday " :
            dw == 4. ? "Thursday " :
            dw == 5. ? "Friday " :
            dw == 6. ? "Satuday " : "Sunday ");
    display(dd);
    display(".");
    display(mm);
    display(".");
    return  yyyy;
}

double dd = 25.;
double mm = 9.;
double yyyy = 2002.;

int main(){
    display(birthday(day__of__week()));
    newline();
    return 0;
}