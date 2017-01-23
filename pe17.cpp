#include "utility.h"

int count_letters_less_than_1000() {
    iVec units {0};
    for(auto word: {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}) {
        // cout << word << ' ';
        units.push_back(strlen(word));
    }
    iVec teens {strlen("ten")};
    for(auto word: {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}) {
        teens.push_back(strlen(word));
    }
    iVec tens {0};
    for(auto word: {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}) {
        // cout << word << ' ';
        tens.push_back(strlen(word));
    }
    // for(auto v: {units, teens, tens})
    //     print(v);
    // cout << units[3] + hundred + tens[4] + units[2] << '\n';
    // cout << units[1] + hundred + teens[5] << '\n';
    auto count_letters = [=](int x) -> int {
        int h, t, u;
        h = (x/100) % 10;
        t = (x/10) % 10 ;
        u = x % 10;
        // print(iVec{h, t, u, units[u], teens[u], tens[t]});
        int res = units[h] + (h>0) * strlen("hundred");
        if ((h != 0) && (t+u !=0)) {
            // cout << res << "before\n";
            res += strlen("and");
            // cout << res << "after\n";
            // cout << "larger than 100 and not exact\n\n";
        }
        if (t==1) {
            // cout << res << "before\n";
            res += teens[u];
            // cout << res << "after\n";
            // cout << "teens\n\n";
        } else {
            // cout << res << "before\n";
            res += tens[t] + units[u];
            // cout << res << "after\n";
            // cout << "non teens\n\n";
        }
        return res;
    };
    // for (auto num: {99, 199, 299, 399, 499, 599, 699, 799, 899}) {
    // for (auto num: {10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 28, 30, 31, 32, 33, 34, 35, 36, 37, 38, 40, 41, 42, 43, 44, 45, 46, 47, 48, 50, 51, 52, 53, 54, 55, 56, 57, 58, 60, 61, 62, 63, 64, 65, 66, 67, 68, 70, 71, 72, 73, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 85, 86, 87, 88, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 199, 299, 399, 499, 599, 699, 799, 899}) {
    // for (auto num: {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 119, 129, 139, 149, 159, 169, 179, 189, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 219, 229, 239, 249, 259, 269, 279, 289, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 319, 329, 339, 349, 359, 369, 379, 389, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 419, 429, 439, 449, 459, 469, 479, 489, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 519, 529, 539, 549, 559, 569, 579, 589, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 619, 629, 639, 649, 659, 669, 679, 689, 700, 701, 702, 703, 704, 705, 706, 707, 708, 709, 719, 729, 739, 749, 759, 769, 779, 789, 800, 801, 802, 803, 804, 805, 806, 807, 808, 809, 819, 829, 839, 849, 859, 869, 879, 889, 900, 901, 902, 903, 904, 905, 906, 907, 908, 909, 919, 929,}) {
        // cout << "cout for " << num+1 << " is " << count_letters(num+1) << '\n';
        // cout << count_letters(num+1) << ", ";
        // wait();
    // } cout << '\n';
    int res = strlen("onethousand");
    for(auto num: range(1,1000)) {
        res += count_letters(num);
        // cout << count_letters(num) << ",";
    }
    // 21124
    return res;
}

int main() {
    cout << count_letters_less_than_1000();
}

/**
clens = np.array([3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8, 6, 9, 9, 11, 10, 10, 9, 11, 11, 10, 6, 9, 9, 11, 10, 10, 9, 11, 11, 10, 5, 8, 8, 10, 9, 9, 8, 10, 10, 9, 5, 8, 8, 10, 9, 9, 8, 10, 10, 9, 5, 8, 8, 10, 9, 9, 8, 10, 10, 9, 7, 10, 10, 12, 11, 11, 10, 12, 12, 11, 6, 9, 9, 11, 10, 10, 9, 11, 11, 10, 6, 9, 9, 11, 10, 10, 9, 11, 11, 10, 10, 13, 13, 15, 14, 14, 13, 15, 15, 14, 13, 19, 19, 21, 21, 20, 20, 22, 21, 21, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 16, 22, 22,24, 23, 23, 22, 24, 24, 23, 15, 21, 21, 23, 22, 22, 21, 23, 23, 22, 15, 21, 21, 23, 22, 22, 21, 23, 23, 22, 15, 21, 21, 23, 22, 22, 21, 23, 23, 22, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 10, 13, 13, 15, 14, 14, 13, 15, 15, 14, 13, 19, 19, 21, 21, 20, 20, 22, 21, 21, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 15, 21, 21, 23, 22, 22, 21, 23, 23, 22, 15, 21, 21, 23, 22, 22, 21, 23, 23, 22, 15, 21, 21, 23, 22, 22, 21, 23, 23, 22, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23,16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 12, 15, 15, 17, 16, 16, 15, 17, 17, 16, 15, 21, 21, 23, 23, 22, 22, 24, 23, 23, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 19, 25, 25, 27, 26, 26, 25, 27, 27, 26, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 11, 14, 14, 16, 15, 15, 14, 16, 16, 15, 14, 20, 20, 22, 22, 21, 21, 23, 22, 22, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 16, 22, 22, 24, 23, 23, 22,24, 24, 23, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 11, 14, 14, 16, 15, 15, 14, 16, 16, 15, 14, 20, 20, 22, 22, 21, 21, 23, 22, 22, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 10, 13, 13, 15,14, 14, 13, 15, 15, 14, 13, 19, 19, 21, 21, 20, 20, 22, 21, 21, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 15, 21, 21, 23, 22, 22, 21, 23, 23, 22, 15, 21, 21, 23, 22, 22, 21, 23, 23, 22, 15, 21, 21, 23, 22, 22, 21, 23, 23, 22, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 12, 15, 15, 17, 16, 16, 15, 17, 17, 16, 15, 21, 21, 23, 23, 22, 22, 24, 23, 23, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17,23, 23, 25, 24, 24, 23, 25, 25, 24, 19, 25, 25, 27, 26, 26, 25, 27, 27, 26, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 12, 15, 15, 17, 16, 16, 15, 17, 17, 16, 15, 21, 21, 23, 23, 22, 22, 24, 23, 23, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 19, 25, 25, 27, 26, 26, 25, 27, 27, 26, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 11, 14, 14, 16, 15, 15, 14, 16, 16, 15, 14, 20, 20, 22, 22, 21, 21, 23,22, 22, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 16, 22, 22, 24, 23, 23, 22, 24, 24, 23, 18, 24, 24, 26, 25, 25, 24, 26, 26, 25, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24, 17, 23, 23, 25, 24, 24, 23, 25, 25, 24,])


clens = np.array([3,3,5,4,4,3,5,5,4,3,9,9,11,11,10,10,12,11,11,6,12,12,14,13,13,12,14,14,13,6,12,12,14,13,13,12,14,14,13,5,11,11,13,12,12,11,13,13,12,5,11,11,13,12,12,11,13,13,12,5,11,11,13,12,12,11,13,13,12,7,13,13,15,14,14,13,15,15,14,6,12,12,14,13,13,12,14,14,13,6,12,12,14,13,13,12,14,14,13,13,16,16,18,17,17,16,18,18,17,16,19,19,21,21,20,20,22,21,21,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,18,21,21,23,22,22,21,23,23,22,18,21,21,23,22,22,21,23,23,22,18,21,21,23,22,22,21,23,23,22,20,23,23,25,24,24,23,25,25,24,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,13,16,16,18,17,17,16,18,18,17,16,19,19,21,21,20,20,22,21,21,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,18,21,21,23,22,22,21,23,23,22,18,21,21,23,22,22,21,23,23,22,18,21,21,23,22,22,21,23,23,22,20,23,23,25,24,24,23,25,25,24,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,15,18,18,20,19,19,18,20,20,19,18,21,21,23,23,22,22,24,23,23,21,24,24,26,25,25,24,26,26,25,21,24,24,26,25,25,24,26,26,25,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,22,25,25,27,26,26,25,27,27,26,21,24,24,26,25,25,24,26,26,25,21,24,24,26,25,25,24,26,26,25,14,17,17,19,18,18,17,19,19,18,17,20,20,22,22,21,21,23,22,22,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,21,24,24,26,25,25,24,26,26,25,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,14,17,17,19,18,18,17,19,19,18,17,20,20,22,22,21,21,23,22,22,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,21,24,24,26,25,25,24,26,26,25,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,13,16,16,18,17,17,16,18,18,17,16,19,19,21,21,20,20,22,21,21,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,18,21,21,23,22,22,21,23,23,22,18,21,21,23,22,22,21,23,23,22,18,21,21,23,22,22,21,23,23,22,20,23,23,25,24,24,23,25,25,24,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,15,18,18,20,19,19,18,20,20,19,18,21,21,23,23,22,22,24,23,23,21,24,24,26,25,25,24,26,26,25,21,24,24,26,25,25,24,26,26,25,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,22,25,25,27,26,26,25,27,27,26,21,24,24,26,25,25,24,26,26,25,21,24,24,26,25,25,24,26,26,25,15,18,18,20,19,19,18,20,20,19,18,21,21,23,23,22,22,24,23,23,21,24,24,26,25,25,24,26,26,25,21,24,24,26,25,25,24,26,26,25,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,22,25,25,27,26,26,25,27,27,26,21,24,24,26,25,25,24,26,26,25,21,24,24,26,25,25,24,26,26,25,14,17,17,19,18,18,17,19,19,18,17,20,20,22,22,21,21,23,22,22,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,19,22,22,24,23,23,22,24,24,23,21,24,24,26,25,25,24,26,26,25,20,23,23,25,24,24,23,25,25,24,20,23,23,25,24,24,23,25,25,24])

plens = np.array([ 3,  3,  5,  4,  4,  3,  5,  5,  4,  3,  6,  6,  8,  8,  7,  7,  9,
        8,  8,  6,  9,  9, 11, 10, 10,  9, 11, 11, 10,  6,  9,  9, 11, 10,
       10,  9, 11, 11, 10,  5,  8,  8, 10,  9,  9,  8, 10, 10,  9,  5,  8,
        8, 10,  9,  9,  8, 10, 10,  9,  5,  8,  8, 10,  9,  9,  8, 10, 10,
        9,  7, 10, 10, 12, 11, 11, 10, 12, 12, 11,  6,  9,  9, 11, 10, 10,
        9, 11, 11, 10,  6,  9,  9, 11, 10, 10,  9, 11, 11, 10, 10, 16, 16,
       18, 17, 17, 16, 18, 18, 17, 16, 19, 19, 21, 21, 20, 20, 22, 21, 21,
       19, 22, 22, 24, 23, 23, 22, 24, 24, 23, 19, 22, 22, 24, 23, 23, 22,
       24, 24, 23, 18, 21, 21, 23, 22, 22, 21, 23, 23, 22, 18, 21, 21, 23,
       22, 22, 21, 23, 23, 22, 18, 21, 21, 23, 22, 22, 21, 23, 23, 22, 20,
       23, 23, 25, 24, 24, 23, 25, 25, 24, 19, 22, 22, 24, 23, 23, 22, 24,
       24, 23, 19, 22, 22, 24, 23, 23, 22, 24, 24, 23, 10, 16, 16, 18, 17,
       17, 16, 18, 18, 17, 16, 19, 19, 21, 21, 20, 20, 22, 21, 21, 19, 22,
       22, 24, 23, 23, 22, 24, 24, 23, 19, 22, 22, 24, 23, 23, 22, 24, 24,
       23, 18, 21, 21, 23, 22, 22, 21, 23, 23, 22, 18, 21, 21, 23, 22, 22,
       21, 23, 23, 22, 18, 21, 21, 23, 22, 22, 21, 23, 23, 22, 20, 23, 23,
       25, 24, 24, 23, 25, 25, 24, 19, 22, 22, 24, 23, 23, 22, 24, 24, 23,
       19, 22, 22, 24, 23, 23, 22, 24, 24, 23, 12, 18, 18, 20, 19, 19, 18,
       20, 20, 19, 18, 21, 21, 23, 23, 22, 22, 24, 23, 23, 21, 24, 24, 26,
       25, 25, 24, 26, 26, 25, 21, 24, 24, 26, 25, 25, 24, 26, 26, 25, 20,
       23, 23, 25, 24, 24, 23, 25, 25, 24, 20, 23, 23, 25, 24, 24, 23, 25,
       25, 24, 20, 23, 23, 25, 24, 24, 23, 25, 25, 24, 22, 25, 25, 27, 26,
       26, 25, 27, 27, 26, 21, 24, 24, 26, 25, 25, 24, 26, 26, 25, 21, 24,
       24, 26, 25, 25, 24, 26, 26, 25, 11, 17, 17, 19, 18, 18, 17, 19, 19,
       18, 17, 20, 20, 22, 22, 21, 21, 23, 22, 22, 20, 23, 23, 25, 24, 24,
       23, 25, 25, 24, 20, 23, 23, 25, 24, 24, 23, 25, 25, 24, 19, 22, 22,
       24, 23, 23, 22, 24, 24, 23, 19, 22, 22, 24, 23, 23, 22, 24, 24, 23,
       19, 22, 22, 24, 23, 23, 22, 24, 24, 23, 21, 24, 24, 26, 25, 25, 24,
       26, 26, 25, 20, 23, 23, 25, 24, 24, 23, 25, 25, 24, 20, 23, 23, 25,
       24, 24, 23, 25, 25, 24, 11, 17, 17, 19, 18, 18, 17, 19, 19, 18, 17,
       20, 20, 22, 22, 21, 21, 23, 22, 22, 20, 23, 23, 25, 24, 24, 23, 25,
       25, 24, 20, 23, 23, 25, 24, 24, 23, 25, 25, 24, 19, 22, 22, 24, 23,
       23, 22, 24, 24, 23, 19, 22, 22, 24, 23, 23, 22, 24, 24, 23, 19, 22,
       22, 24, 23, 23, 22, 24, 24, 23, 21, 24, 24, 26, 25, 25, 24, 26, 26,
       25, 20, 23, 23, 25, 24, 24, 23, 25, 25, 24, 20, 23, 23, 25, 24, 24,
       23, 25, 25, 24, 10, 16, 16, 18, 17, 17, 16, 18, 18, 17, 16, 19, 19,
       21, 21, 20, 20, 22, 21, 21, 19, 22, 22, 24, 23, 23, 22, 24, 24, 23,
       19, 22, 22, 24, 23, 23, 22, 24, 24, 23, 18, 21, 21, 23, 22, 22, 21,
       23, 23, 22, 18, 21, 21, 23, 22, 22, 21, 23, 23, 22, 18, 21, 21, 23,
       22, 22, 21, 23, 23, 22, 20, 23, 23, 25, 24, 24, 23, 25, 25, 24, 19,
       22, 22, 24, 23, 23, 22, 24, 24, 23, 19, 22, 22, 24, 23, 23, 22, 24,
       24, 23, 12, 18, 18, 20, 19, 19, 18, 20, 20, 19, 18, 21, 21, 23, 23,
       22, 22, 24, 23, 23, 21, 24, 24, 26, 25, 25, 24, 26, 26, 25, 21, 24,
       24, 26, 25, 25, 24, 26, 26, 25, 20, 23, 23, 25, 24, 24, 23, 25, 25,
       24, 20, 23, 23, 25, 24, 24, 23, 25, 25, 24, 20, 23, 23, 25, 24, 24,
       23, 25, 25, 24, 22, 25, 25, 27, 26, 26, 25, 27, 27, 26, 21, 24, 24,
       26, 25, 25, 24, 26, 26, 25, 21, 24, 24, 26, 25, 25, 24, 26, 26, 25,
       12, 18, 18, 20, 19, 19, 18, 20, 20, 19, 18, 21, 21, 23, 23, 22, 22,
       24, 23, 23, 21, 24, 24, 26, 25, 25, 24, 26, 26, 25, 21, 24, 24, 26,
       25, 25, 24, 26, 26, 25, 20, 23, 23, 25, 24, 24, 23, 25, 25, 24, 20,
       23, 23, 25, 24, 24, 23, 25, 25, 24, 20, 23, 23, 25, 24, 24, 23, 25,
       25, 24, 22, 25, 25, 27, 26, 26, 25, 27, 27, 26, 21, 24, 24, 26, 25,
       25, 24, 26, 26, 25, 21, 24, 24, 26, 25, 25, 24, 26, 26, 25, 11, 17,
       17, 19, 18, 18, 17, 19, 19, 18, 17, 20, 20, 22, 22, 21, 21, 23, 22,
       22, 20, 23, 23, 25, 24, 24, 23, 25, 25, 24, 20, 23, 23, 25, 24, 24,
       23, 25, 25, 24, 19, 22, 22, 24, 23, 23, 22, 24, 24, 23, 19, 22, 22,
       24, 23, 23, 22, 24, 24, 23, 19, 22, 22, 24, 23, 23, 22, 24, 24, 23,
       21, 24, 24, 26, 25, 25, 24, 26, 26, 25, 20, 23, 23, 25, 24, 24, 23,
       25, 25, 24, 20, 23, 23, 25, 24, 24, 23, 25, 25, 24])

*/