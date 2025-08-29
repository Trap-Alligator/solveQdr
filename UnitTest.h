#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "NumOfSol.h"

void PrintWrong(qadr *testent, double x1, double x2, double x1norm, double x2norm, int count_sol_norm, int count_sol);
void TestHelp(qadr *testent, qadr_res *testext);
void UnitTest();

#endif
