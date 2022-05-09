#include <stdio.h>
#include <string.h>
#include "util.h"

#define NUMVALS 10

int main() {
    
    double vals[NUMVALS] = {1.2, 5, 78.4, 23.0, 0.004, 4.5, 23, 6.5, 9999.0, 10.0};

    person me;
    strcpy(me.name, "Gandalf");
    me.age = 2019;

    printf("Mean: %lf\n", getmean(vals, NUMVALS));
    print_person_info(&me);

    return 0;
}
