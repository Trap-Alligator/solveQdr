#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "UnitTest.h"
#include "NumOfSol.h"

//-----------------------------------------------------------------------------------------------
//! печать неправильно решенного примера
//-----------------------------------------------------------------------------------------------
void PrintWrong(qadr *testent, double x1, double x2, double x1norm, double x2norm, int count_sol_norm, int count_sol){
    char buffer[200];
    sprintf(buffer, "NO: a = %lg, b = %lg, c = %lg\nCurrent: x1 = %lg, x2 = %lg, count_sol = %i\n",\
    testent->a, testent->b, testent->c, x1, x2, count_sol);
    printf("%sAns: x1 = %lg, x2 = %lg, count_sol = %i\n", buffer, x1norm, x2norm, count_sol_norm);
}

//----------------------------------------------------------------------
//! обработка готовых входных данных
//----------------------------------------------------------------------
void TestHelp(qadr *testent, qadr_res *testext){
    double x1 = 0, x2 = 0;

    double x1norm = testext->x1;
    double x2norm = testext->x2;
    int count_sol_norm = testext->count_sol;

    int count_sol = SqSol(testent, &x1, &x2);

    bool flag = (count_sol_norm == count_sol);

    if(!(flag && IsSameDbl(x1, x1norm) == 1 && IsSameDbl(x2, x2norm) == 1)){
        PrintWrong(testent, x1, x2, x1norm, x2norm, count_sol_norm, count_sol);
    }
}

//------------------------------------------------------------
//! тестирование программы на готовых входных данных
//------------------------------------------------------------
void UnitTest(){
    qadr testent[5] = {{1, 3, 2}, {4, 0, -1}, {4, 3, 1}, {0, 2, 9}, {0, 0, 0}};
    qadr_res testext[5] = {{-1, -2, 2}, {0.5, -0.5, 2}, {0, 0, 0}, {-4.5, 0, 1}, {0, 0, INF_SOL}};
    for(int i = 0; i < 5; i++){
        TestHelp(&testent[i], &testext[i]);
    }
}

