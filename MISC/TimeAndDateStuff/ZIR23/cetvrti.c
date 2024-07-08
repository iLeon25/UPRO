#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dayOfWeek(time_t time) {
    if (time == 0) {
        printf("GRESKA\n");
        exit(0);
    }

    // Calculate the number of days since January 1, 1970
    int days_since_epoch = time / (24 * 60 * 60);

    // The epoch started on a Thursday (4th day of the week)
    int epoch_start_day = 4;

    // Calculate the day of the week
    int day_of_week = (days_since_epoch + epoch_start_day) % 7;

    // Adjust to make Monday = 1, Tuesday = 2, ..., Sunday = 7
    if (day_of_week == 0) {
        day_of_week = 7; // Sunday
    }

    return day_of_week;
}

int dayOfWeekToday(void) {
    // Get the current time
    time_t current_time = time(NULL);

    // Call dayOfWeek to determine the current day of the week
    return dayOfWeek(current_time);
}













