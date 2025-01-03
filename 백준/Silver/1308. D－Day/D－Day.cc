#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int daysInMonth(int year, int month) {
    if (month == 2) {
      if(isLeapYear(year))
      return 29;
      else
      return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

int dateToDays(int year, int month, int day) {
    int days = 0;

    for (int y = 1; y < year; ++y) {
      if(isLeapYear(y))
      days+=366;
      else
      days+=365;
       
    }

    for (int m = 1; m < month; ++m) {
        days += daysInMonth(year, m);
    }

    days += day;

    return days;
}

int main() {
    int todayYear, todayMonth, todayDay;
    int DdayYear, DdayMonth, DdayDay;

    cin >> todayYear >> todayMonth >> todayDay;
    cin >> DdayYear >> DdayMonth >> DdayDay;

    int todayDays = dateToDays(todayYear, todayMonth, todayDay);
    int DdayDays = dateToDays(DdayYear, DdayMonth, DdayDay);

    int diff = DdayDays - todayDays;

    if (DdayYear - todayYear > 1000 || (DdayYear - todayYear == 1000 && DdayMonth >= todayMonth && DdayDay >= todayDay)) {
        cout << "gg" ;
    } else {
        cout << "D-" << diff ;
    }

}
