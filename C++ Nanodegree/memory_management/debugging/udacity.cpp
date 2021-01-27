/*
To compile and run with debugger, we have to:
1. g++ -g udacity.cpp (-g compiles and provides symbols)
2. gdb ./a.out

Interesting commands are
- list (show source-code)
- break [line] (set breakpoint on line)
- run (to run the program)
- step (to step after breakpoint)
- p [variable] (print content in variable)
- p &[variable] (print address of variable)
- x/7tb [address] to see what is inside that adress. 
    - "7" = how many units to print
    - "t" = to print ints as binary, "x" print it as hexadecimal
    - "b" = format of the units, b is byte
- x/1tb will print just 1 unit (byte), try it with incrementing the last digit of p &[variable] by 1!

More commands in cheat-sheet: https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf
*/

#include <stdio.h>

int main()
{
    char str1[]= "UDACITY";
    printf("%s",str1);

    return 0;
}