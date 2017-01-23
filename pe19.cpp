#include "utility.h"
// Counting Sundays
// https://projecteuler.net/problem=19
// 1 Jan 1900 was a Monday.
// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

int get_day_number(int year, int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return 28 + ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
    }
    throw std::invalid_argument("Month must be among 1 to 12.");
}

int main() {
    int cnt = 0;
    int weekday = 0;    // begin at Monday
    for (int year = 1900; year <= 2000; ++year) {
        for (int month = 1; month <= 12; ++month) {
            if (year >= 1901 && weekday % 7 == 6) {
                ++cnt;
            }
            weekday += get_day_number(year, month);
            // cout << weekday;
            // wait();
        }
    }
    cout << cnt;
}
