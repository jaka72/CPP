#include <stdio.h>
#include <limits.h>


int main(int argc, char **argv)
{
    double a = 879879087;
    double b = 67548976597;

    printf("result: %f\n", a * b);
    printf("result: %ld\n", LONG_MAX);
    printf("result: %lld\n", LONG_LONG_MAX);
// 9223372036854775807
}