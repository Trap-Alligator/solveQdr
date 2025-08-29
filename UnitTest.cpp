#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "UnitTest.h"
#include "NumOfSol.h"

//-----------------------------------------------------------------------------------------------
//! Печать неправильно решенного примера
//! На вход даются коэф., получившиеся корни и кол-во ответов, правильные корни и кол-во ответов
//-----------------------------------------------------------------------------------------------
void PrintWrong(qadr *testent, double x1, double x2, double x1norm, double x2norm, int count_sol_norm, int count_sol){
    printf("NO: a = %lg, b = %lg, c = %lg\nCurrent: x1 = %lg, x2 = %lg, count_sol = %i\n",\
    testent->a, testent->b, testent->c, x1, x2, count_sol);
    printf("Ans: x1 = %lg, x2 = %lg, count_sol = %i\n", x1norm, x2norm, count_sol_norm);
}

//----------------------------------------------------------------------
//! Обработка готовых входных данных
//! На вход даются получившиеся ответы и правильные ответы
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
//! Тестирование программы на готовых входных данных
//------------------------------------------------------------
void UnitTest(){
    FILE* key_test = fopen("KeyForTest.txt", "r");
    if(key_test == 0){
        printf("Wrong file\n");
    }
    else{
        qadr testent[5] = {};
        qadr_res testext[5] = {};
        for(int i = 0; i < 5; i++){
            fscanf(key_test, "%lg, %lg, %lg, %lg, %lg, %i", &(testent[i].a), &(testent[i].b),
             &(testent[i].c), &(testext[i].x1),  &(testext[i].x2), &(testext[i].count_sol));
            TestHelp(&testent[i], &testext[i]);
        }
    }
}

