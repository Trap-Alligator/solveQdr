#define INF_SOL -1

typedef struct {
    double a, b, c;
} qadr;

typedef struct {
    double x1, x2;
    int count_sol;
} qadr_res;

int IsSameDbl(double d, double q);
int SqSol(qadr *eqal, double *x1, double *x2);
int NotCorSq(qadr *eqal, double *x1);
void NumOfSol(qadr *eqal);
void TestHelp(qadr *testent, qadr_res *testext);
void UnitTest();
void ScanInput(qadr *eqal);
