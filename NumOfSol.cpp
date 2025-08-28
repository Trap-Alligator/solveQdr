#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "NumOfSol.h"

//--------------------------------------------
//! подсчет дискриминанта
//--------------------------------------------
double D(qadr *eqal){
    double a = eqal->a;
    double b = eqal->b;
    double c = eqal->c;

    return b * b - 4 * a * c;
}

//---------------------------------------------
//! сравнение чисел типа double
//---------------------------------------------
int IsSameDbl(double d, double q){
    if(fabs(d - q) > 0.000001){
        return 0;
    }
    return 1;
}

//---------------------------------------------------------
//! обработка уравнения, если коэф. при x^2 равен 0
//---------------------------------------------------------
int NotCorSq(qadr *eqal, double *x1){
    double b = eqal->b;
    double c = eqal->c;
    if(IsSameDbl(b, 0) == 1 && IsSameDbl(c, 0) == 1){
        return INF_SOL;
    }
    if(IsSameDbl(b, 0) == 1 && IsSameDbl(c, 0) == 0){
        return 0;
    }
    *x1 = -c / b;
    return 1;

}

//--------------------------------------------------
//! обработка уравнения
//--------------------------------------------------
int SqSol(qadr *eqal, double *x1, double *x2){
    double a = eqal->a;
    double b = eqal->b;
    if(IsSameDbl(a, 0) == 1){
        return NotCorSq(eqal, x1);
    }
    else{
        double d = D(eqal);
        if(IsSameDbl(d, 0) == 1){
            *x1 = *x2 = -b / (2*a);
            return 1;
        }
        if(d < 0){
            return 0;
        }
        *x1 = (-b + sqrt(d)) / (2*a);
        *x2 = (-b - sqrt(d)) / (2*a);
        return 2;
    }
}

//----------------------------------------------------------
//! вывод ответа
//----------------------------------------------------------
void NumOfSol(qadr *eqal){
    double x1 = 0, x2 = 0;
    int count_sol = 0;
    count_sol = SqSol(eqal, &x1, &x2);
    switch(count_sol){
        case INF_SOL:
            printf("Inf num of sol");
            break;

        case 0:
            printf("No sol.");
            break;

        case 1:
            printf("One sol.:\nx = %lg", x1);
            break;

        case 2:
            printf("Two sol.:\nx1 = %lg\nx2 = %lg", x1, x2);
            break;
        default:
            assert(0);
    }
}
