#include <stdio.h>

char leap[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char nonleap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char* daytab[2] = {leap, nonleap};

int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);

    if ((year < 0) || (month < 1 || month > 12) || (day < 1 || day > *(*(daytab + leap) + month))) {
        return -1;
    }

    for (i = 1; i < month; i++) {
        day += *(*(daytab + leap) + i);
    }
    return day;
}

void month_day(int year, int yesterday, int* pmonth, int* pday) {
    int i, leap;
    leap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);

    if ((year < 0) || (yesterday < 0 || yesterday > (leap ? 366 : 365)) || (pmonth == NULL || pday == NULL)) {
        return;
    }

    for (i = 1; yesterday > *(*(daytab + leap) + i); i++) {
        yesterday -= *(*(daytab + leap) + i);
    }
    *pmonth = i;
    *pday = yesterday;
}

int main(int argc, char* argv[]) {
    int m, d, dy;
    month_day(1988, 60, &m, &d);
    dy = day_of_year(2024, 3, 1);
    printf("Month %d - Day %d\n", m, d);
    printf("March 1 is the %d day\n", dy);
    return 0;
}
