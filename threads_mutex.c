#include <stdio.h>
#include <pthread.h>

#define THREADS 4
#define ITERATIONS 100000
long long counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *unsafe_increment(void *arg) {
    (void)arg;
    for (int i = 0; i < ITERATIONS; ++i) counter++; /* Data race */
    return NULL;
}
void *safe_increment(void *arg) {
    (void)arg;
    for (int i = 0; i < ITERATIONS; ++i) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
void run_test(void *(*worker)(void *), const char *label) {
    pthread_t threads[THREADS];
    counter = 0;
    for (int i = 0; i < THREADS; ++i) pthread_create(&threads[i], NULL, worker, NULL);
    for (int i = 0; i < THREADS; ++i) pthread_join(threads[i], NULL);
    printf("%s counter = %lld (expected %d)\n", label, counter, THREADS * ITERATIONS);
}
int main(void) {
    run_test(unsafe_increment, "Without mutex (race condition)");
    run_test(safe_increment, "With mutex");
    pthread_mutex_destroy(&lock);
    return 0;
}
