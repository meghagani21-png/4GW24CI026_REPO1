#include <stdio.h>
#include <stdlib.h>

struct day {
    char *dayname;
    char *activity;
    int date;
};

void create(struct day *day) {
    day->dayname = (char*)malloc(sizeof(char) * 20);
    day->activity = (char*)malloc(sizeof(char) * 100);

    printf("Enter the day name: ");
    scanf("%s", day->dayname);

    printf("Enter the date: ");
    scanf("%d", &day->date);

    printf("Enter the activity: ");
    scanf("%s", day->activity);
}

void read(struct day *calendar, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nEnter details for day %d\n", i + 1);
        create(&calendar[i]);
    }
}

void display(struct day *calendar, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nDay %d\n", i + 1);
        printf("Day name : %s\n", calendar[i].dayname);
        printf("Date     : %d\n", calendar[i].date);
        printf("Activity : %s\n", calendar[i].activity);
    }
}

void freememory(struct day *calendar, int size) {
    for (int i = 0; i < size; i++) {
        free(calendar[i].dayname);
        free(calendar[i].activity);
    }
}

int main() {
    int size;

    printf("Enter the size: ");
    scanf("%d", &size);   // ← FIXED HERE

    struct day *calendar = (struct day*)malloc(sizeof(struct day) * size);
    if (calendar == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    read(calendar, size);
    display(calendar, size);
    freememory(calendar, size);
    free(calendar);

    return 0;
}
