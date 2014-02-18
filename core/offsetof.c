#include <stdio.h>

#define offsetof(Type, elem)((size_t)&(((Type *)0)->elem))


typedef struct {
    int num;
    char *name;
    int grade;
} Stu;

int main()
{
    printf("%d\n", offsetof(Stu, num));
    printf("%d\n", offsetof(Stu, name));
    printf("%d\n", offsetof(Stu, grade));
 
    return 0;
}
