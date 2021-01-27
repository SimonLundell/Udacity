#include <stdio.h>

void CallByValue(int i) { // this should consume more space,thus a higher address, but my PC is too good.
    int j = 1;
    printf("Call-by-value: %p\n", &j);
}

void CallByPointer(int *i) {
    int j = 1;
    printf("Call-by-pointer: %p\n", &j);
}

void CallByReference(int &i) {
    int j = 1;
    printf("Call-by-reference: %p\n", &j);
}

// We will be able to see the j variable in comparison to the i variable on the stack go get an idea which method is most efficient.
int main() {
    int i = 0;
    printf("stack bottom: %p\n", &i);

    CallByValue(i);

    CallByPointer(&i);

    CallByReference(i);
}

/* Should be output. The complier optimizes it for us so we wont see it.
stack bottom: 0x7ffeefbff698
call-by-value: 0x7ffeefbff678 // Call by value requires 32 bytes, it reserves space for return address, copy of input variable
call-by-pointer: 0x7ffeefbff674 // takes -36 bytes!
call-by-reference: 0x7ffeefbff674

n this section, we have argued at length that passing a parameter by reference avoids a costly copy and should - 
in many situations - be preferred over passing a parameter by value. 
Yet, in the experiment above, we have witnessed the exact opposite.

Can you explain why? 

Let us take a look at the size of the various parameter types using the sizeof command:

printf("size of int: %lu\n", sizeof(int));
printf("size of *int: %lu\n", sizeof(int *));

The output here is

size of int: 4
size of *int: 8

Obviously, the size of the pointer variable is larger than the actual data type. As my machine has a 64 bit architecture, an address requires 8 byte.

As an experiment, you could use the -m32 compiler flag to build a 32 bit version of the program. This yields the following output:

size of int: 4
size of *int: 4

In order to benefit from call-by-reference, the size of the data type

*/