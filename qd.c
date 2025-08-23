#include <stdio.h>
#include <math.h>

typedef struct {
    double a, b, c;
} qadr;

void UnitTest(qadr *eqal);

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
int same(double d, double q){
    if(fabs(d - q) > 0.000000001){
        return 0;
    }
    return 1;
}
int samedi(double d, int q){
    if(fabs(d - q) > 0.000000001){
        return 0;
    }
    return 1;
}

//---------------------------------------------------------
//! обработка уравнения, если коэф. при x^2 равен 0
//---------------------------------------------------------
int notcorsq(qadr *eqal, double *x1){
    double b = eqal->b;
    double c = eqal->c;
    if(b == 0 && c == 0){
        return -1;
    }
    if(b == 0 && c != 0){
        return 0;
    }
    if(b != 0){
        *x1 = -c / b;
        return 1;
    }
}

//--------------------------------------------------
//! обработка уравнения
//--------------------------------------------------
int sqsol(qadr *eqal, double *x1, double *x2){
    double a = eqal->a;
    double b = eqal->b;
    double c = eqal->c;
    if(a == 0){
        notcorsq(eqal, x1);
    }
    else{
        double d = D(eqal);
        if(same(d, 0) == 1){
            *x1 = *x2 = -b / (2*a);
            return 1;
        }
        if(d < 0){
            return 0;
        }
        if(d > 0){
            *x1 = (-b + sqrt(d)) / (2*a);
            *x2 = (-b - sqrt(d)) / (2*a);
            return 2;
        }
    }
}

//----------------------------------------------------------
//! вывод ответа
//----------------------------------------------------------
void numofsol(qadr *eqal){
    double a = eqal->a;
    double x1 = 0, x2 = 0;
    int count = 0;
    count = sqsol(eqal, &x1, &x2);
    switch(count){
        case -1:
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

int main(void) {

    qadr eqal;
//    printf("Enter the coefficients of the qadr.:\n");
//    scanf("%lg %lg %lg", &(eqal.a), &(eqal.b), &(eqal.c));

    UnitTest(&eqal);


    return 0;
}

//------------------------------------------------------------
//! тестирование программы на готовых входных данных
//------------------------------------------------------------
void UnitTest(qadr *eqal){
    qadr testent[5] = {{1, 3, 2}, {4, 0, -1}, {4, 3, 1}, {0, 2, 9}, {0, 0, 0}};
    qadr testext[5] = {{-1, -2, 2}, {0.5, -0.5, 2}, {0, 0, 0}, {-4.5, 0, 1}, {0, 0, -1}};
    for(int i = 0; i < 5; i++){
        double x1 = 0, x2 = 0;
        double a = testent[i].a;
        double b = testent[i].b;
        double c = testent[i].c;

        eqal->a = a;
        eqal->b = b;
        eqal->c = c;

        double x1norm = testext[i].a;
        double x2norm = testext[i].b;
        double countnorm = testext[i].c;

        int count = sqsol(eqal, &x1, &x2);

        if(same(countnorm, 2) == 1){
            if(!(same(countnorm, count) == 1 && same (x1, x1norm)== 1 && same(x2, x2norm) == 1)){
                printf("NO: a = %lg, b = %lg, c = %lg -> x1 = %lg, x2 = %lg, count = %i(should be x1 = %lg, x2 = %lg, count = %lg)",a, b, c, x1, x2, count, x1norm, x2norm, countnorm);
            }
        }
        if(same(countnorm, 1) == 1){
            if(!(same(countnorm, count) == 1 && same(x1, x1norm)== 1)){
                printf("NO: a = %lg, b = %lg, c = %lg -> x1 = %lg, x2 = %lg, count = %i (should be x1 = %lg, count = %lg)",a, b, c, x1, x2, count, x1norm, countnorm);
            }
        }
        if(same(countnorm, 0) == 1){
            if(!(same(countnorm, count) == 1)){
                printf("NO: a = %lg, b = %lg, c = %lg -> x1 = %lg, x2 = %lg, count = %i (should be count = %lg)",a, b, c, x1, x2, count, countnorm);
            }
        }
        if(same(countnorm, -1) == 1){
            if(!(same(countnorm, count) == 1)){
                printf("NO: a = %lg, b = %lg, c = %lg -> x1 = %lg, x2 = %lg, count = %i (should be count = %lg)",a, b, c, x1, x2, count, countnorm);
            }
        }

    }
    // double x1 = 0, x2 = 0;
    // int count;
    // eqal->a = 1;
    // eqal->b = 3;
    // eqal->c = 2;
    // count = sqsol(eqal, &x1, &x2);
    // if(!(count == 2 && same(x1, -1) == 1 && same(x2, -2) == 1)){
    //     printf("NO: a = 1, b = 3, c = 2 -> x1 = %lg, x2 = %lg, count = %i (should be x1 = -1, x2 = -2, count = 2)", x1, x2, count);
    // }
    // eqal->a = 4;
    // eqal->b = 0;
    // eqal->c = -1;
    // count = sqsol(eqal, &x1, &x2);
    // if(!(count == 2 && same (x1, 0.5)== 1 && same(x2, -0.5) == 1)){
    //     printf("NO: a = 4, b = 0, c = -1 -> x1 = %lg, x2 = %lg, count = %i (should be x1 = 0.5, x2 = -0.5, count = 2)", x1, x2, count);
    // }
    // eqal->a = 4;
    // eqal->b = 3;
    // eqal->c = 1;
    // count = sqsol(eqal, &x1, &x2);
    // if(!(count == 0)){
    //     printf("NO: a = 4, b = 3, c = 1 -> x1 = %lg, x2 = %lg, count = %i (should be count = 0)", x1, x2, count);
    // }
    // eqal->a = 0;
    // eqal->b = 2;
    // eqal->c = 9;
    // count = sqsol(eqal, &x1, &x2);
    // if(!(count == 1 && same(x1, -4.5) == 1)){
    //     printf("NO: a = 0, b = 2, c = 9 -> x1 = %lg, x2 = %lg, count = %i (should be x1 = -4.5, count = 1)", x1, x2, count);
    // }
    // eqal->a = 0;
    // eqal->b = 0;
    // eqal->c = 0;
    // count = sqsol(eqal, &x1, &x2);
    // if(!(count == -1)){
    //     printf("NO: a = 0, b = 0, c = 0 -> x1 = %lg, x2 = %lg, count = %i (should count = -1)", x1, x2, count);
    // }
}
