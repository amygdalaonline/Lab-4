#include <stdio.h>

extern int array_sum(const int *arr, int n);

// argc count = how many command line arguments
// argv files = array of strings
int main(int count, char **files) {
    // opens file with name files[1]
    // r = open for reading
    FILE *fp = fopen(files[1], "r");
    
    // if *fp == NULL (so if fail)
    if (!fp) {
        printf("file error\n");
        return 1; // exit with error
    }

    int n;

    // reads one int from file
    // %d == read an int
    // &n = store result into variable 'n'
    // so if file starts with 50, n = 50
    fscanf(fp, "%d", &n);

    int a[1000];   // fixed size array, assuming n <= 1000
    
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &a[i]); // each loop iteratation reads one int from file
    }

    // closes file
    fclose(fp);

    printf("Sum: %d\n", array_sum(a, n));
    return 0;

}