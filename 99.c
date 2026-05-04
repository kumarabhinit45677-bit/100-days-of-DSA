#include <stdio.h>
#include <stdlib.h>

// Structure for car
struct Car {
    int pos;
    int speed;
};

// Sort by position descending
int cmp(const void* a, const void* b) {
    return ((struct Car*)b)->pos - ((struct Car*)a)->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    struct Car cars[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].pos);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    // Sort cars by position (descending)
    qsort(cars, n, sizeof(struct Car), cmp);

    double lastTime = 0;
    int fleets = 0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > lastTime) {
            fleets++;           // new fleet
            lastTime = time;
        }
        // else: joins existing fleet
    }

    printf("%d", fleets);

    return 0;
}