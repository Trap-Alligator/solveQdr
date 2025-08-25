g++ -c qd.cpp -o qd.o -Wall -Wextra -Werror=vla
g++ -c UnitTest.cpp -o UnitTest.o -Wall -Wextra -Werror=vla
g++ qd.o UnitTest.o -o qd.exe
.\qd.exe
