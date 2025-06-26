#include <stdio.h>

// Write a program endtab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same
// spacing. Use the same tab stops as for detab. When either tab or a single blank would suffice to reach tab stop,
// which should be given preference?
//
// a--b---c

const int TAB_STOP = 8;

int main(void) {
    int c;
    int space_count = 0;
    int column = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
        } else {
            // Process any pending spaces
            if (space_count > 0) {
                while (space_count > 0) {
                    if ((column % TAB_STOP == 0) && (space_count >= TAB_STOP)) {
                        putchar('\t');
                        space_count -= TAB_STOP;
                        column += TAB_STOP;
                    } else if ((column % TAB_STOP == 0) && (space_count > 1)) {
                        putchar('\t');
                        int to_tab_stop = TAB_STOP;
                        space_count -= to_tab_stop;
                        column += to_tab_stop;
                    } else {
                        putchar(' ');
                        space_count--;
                        column++;
                    }
                }
            }
            putchar(c);
            if (c == '\n') {
                column = 0;
            } else if (c == '\t') {
                column += TAB_STOP - (column % TAB_STOP);  // tabs jump to next stop
            } else {
                column++;
            }
        }
    }

    return 0;
}
