#include "philo.h"

int main() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("Saniye: %ld\n", tv.tv_sec);
    printf("Mikrosaniye: %ld\n", tv.tv_usec);
    return 0;
}