#include <stdio.h>
#include <math.h>
#include "UnitTest.h"

//------------------------------------------------------------
//! обработка готовых входных данных
//------------------------------------------------------------
void TestHelp(qadr *testent, qadr_res *testext){
    double x1 = 0, x2 = 0;

    double x1norm = testext->x1;
    double x2norm = testext->x2;
    int count_sol_norm = testext->count_sol;

    int count_sol = SqSol(testent, &x1, &x2);

    char buffer[200];

    sprintf(buffer, "NO: a = %lg, b = %lg, c = %lg -> x1 = %lg, x2 = %lg, count_sol = %i",\
    testent->a, testent->b, testent->c, x1, x2, count_sol);

    switch(count_sol_norm){
        case 2:
            if(!(count_sol_norm == count_sol && IsSameDbl(x1, x1norm)== 1 && IsSameDbl(x2, x2norm) == 1)){
                printf("%s(should be x1 = %lg, x2 = %lg, count_sol = %i)\n", buffer, x1norm, x2norm, count_sol_norm);
            }
            break;
        case 1:
            if(!(count_sol_norm == count_sol && IsSameDbl(x1, x1norm)== 1)){
                printf("%s(should be x1 = %lg, count_sol = %i)\n", buffer, x1norm, count_sol_norm);
            }
            break;
        case 0:

        case INF_SOL:
            if(!(count_sol_norm == count_sol)){
                printf("%s(should be count_sol = %i)\n", buffer, count_sol_norm);
            }
            break;
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

