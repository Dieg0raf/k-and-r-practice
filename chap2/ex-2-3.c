#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const int HEX = 16;
const int valuesAF[6] = {10, 11, 12, 13, 14, 15};

// hexadecimal string to integer
int htoi(const char s[]) {
    const int size = strlen(s) - 1;
    int ret = 0, j = 0;
    for (int i = size; i > 0 && (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') ||
                       (s[i] >= 'A' && s[i] <= 'F') || (i == 1 && (s[i] == 'X' || s[i] == 'x'));
         i--) {
        if (i == 0 && s[i] != '0') {
            fprintf(stderr, "Not a valid hexadecimal string\n");
            return -1;
        }

        if (isdigit(s[i]) && i > 1) {
            ret += (s[i] - '0') * pow(HEX, j);
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            ret += valuesAF[s[i] - 'A'] * pow(HEX, j);
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            ret += valuesAF[s[i] - 'a'] * pow(HEX, j);
        }
        j++;
    }
    return ret;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Need to pass in a string\n");
        return 1;
    }

    int ret;
    if ((ret = htoi(argv[1])) < 0) {
        return ret;
    }
    printf("%s == %d\n", argv[1], ret);
    return 0;
}
