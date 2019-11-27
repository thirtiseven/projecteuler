#include <stdio.h>

static const int *month_lengths(int year) {
	static const int NON_LEAP_YEAR[] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	static const int LEAP_YEAR[] = {
		31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ?
		LEAP_YEAR : NON_LEAP_YEAR;
}

int main(void) {
	int first_sundays = 0;
	int day_of_the_week = 2;    // 0 = Sun, 6 = Sat.  1 Jan 1901 was a Tuesday.
	for (int year = 1901; year <= 2000; ++year) {
		const int *lengths = month_lengths(year);
		for (int month = 0; month < 12; month++) {
			if (day_of_the_week == 0) {
				first_sundays++;
			}
			day_of_the_week = (day_of_the_week + lengths[month]) % 7;
		}
	}
	printf("There are %d Sundays that fell on the first of the month\n",
		   first_sundays);
}