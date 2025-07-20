#include <stdio.h>

int main(int argc, char* argv[]) {
    char* s[] = {"grep", "-nx", "diego"};
    char** p = s;
    printf("%c\n", (*++p)[0]);
    printf("%c\n",
           *++p[0]);  // *++(p[0]) incrementing the address of "-nx" (e.g., 0x01 = '-', so 0x01 + 1 = 0x02 = 'n')
    // Incrementing the address of the pointer that points to "-nx" allows us to iterate through the string and not the
    // strings inside of the array
}
