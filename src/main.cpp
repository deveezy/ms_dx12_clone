#include <stdio.h>
#include <Utility.h>

int main()
{
    int a = __LINE__;
    printf("%s\n", STRINGIFY_BUILTIN(5));
    ERROR("hello");
    return 0;
}