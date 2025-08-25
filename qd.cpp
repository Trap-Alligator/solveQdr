#include <stdio.h>
#include <math.h>
#include "UnitTest.h"

//--------------------------------------------
//! подсчет дискриминанта
//--------------------------------------------
static double D(qadr *eqal){
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
    if(b == 0 && c == 0){
        return INF_SOL;
    }
    if(b == 0 && c != 0){
        return 0;
    }
    *x1 = -c / b * 3;
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

    }
}

void ScanInput(qadr *eqal){
    int dbl_count = scanf("%lg %lg %lg", &(eqal->a), &(eqal->b), &(eqal->c));
    if(dbl_count != 3){
        printf("Wrong input");
    }
    else{
        NumOfSol(eqal);
    }
}

int main(void) {
    UnitTest();

    qadr eqal = {};
    printf("Enter the coefficients of the qadr.:\n");
    ScanInput(&eqal);

    return 0;
}





