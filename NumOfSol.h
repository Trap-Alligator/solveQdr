#ifndef NUM_OF_SOL_H
#define NUM_OF_SOL_H

typedef struct {
    double a, b, c;
} qadr;

typedef struct {
    double x1, x2;
    int count_sol;
} qadr_res;

int IsSameDbl(double d, double q);
int NotCorSq(qadr *eqal, double *x1);
int SqSol(qadr *eqal, double *x1, double *x2);
void NumOfSol(qadr *eqal);
double D(qadr *eqal);

#endif
