#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "UnitTest.h"
#include "NumOfSol.h"

void ScanInput(qadr *eqal);
bool IsSameStr(const char* s1, const char* s2);

int main(int argc, const char* argv[]) {
    if(argc == 2 && IsSameStr(argv[1], "-t")){
        UnitTest();
    }

    qadr eqal = {};
    printf("Enter the coefficients of the qadr.:\n");
    ScanInput(&eqal);

    return 0;
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

bool IsSameStr(const char* s1, const char* s2){
    int i = 0;
    while(s1[i] != '\0' || s2[i] != '\0'){
        if(s1[i] != s2[i]){
            return false;
        }
        i++;
    }
    return true;
}





