#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int list[], int first, int last, int gap, int* comp_count, int* move_count) {
    int i, j, key;
 
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        (*comp_count)++;
        
        for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
            (*move_count)++;
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n) {
    int i, gap;
    int comp_count = 0; // 비교 횟수 초기화
    int move_count = 0; // 이동 횟수 초기화

    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0)
            gap++;
        print_array(list, n);
        for (i = 0; i < gap; i++) {
            insertion_sort(list, i, n - 1, gap, &comp_count, &move_count);
        }
    }
    int avg_move_count = move_count / n;
    int avg_comp_count = comp_count / n;

    printf("avg_move_count:%d\n", avg_move_count);
    printf("avg_comp_count:%d\n", avg_comp_count);
}

int main(void) {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
   
    printf("Original List: ");
    for (i = 0; i < n; i++) {
        list[i] = rand() % 100;
        printf("%d ", list[i]);
    }
    printf("\n");

    shell_sort(list, n);
    printf("Shell Sort: ");
    print_array(list, n);

    return 0;
}