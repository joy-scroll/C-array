#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b);
void swapd(int **a, int **b);
void bitcheck(int a);
void reverse(int *a);
int arrmax(int a[], int n);
int arrsecmax(int a[], int n);
void prime(int *a, int n);

int main() {
    int a, b, n;
    int *A;
    int *p, *q;

    printf("Enter two numbers: ");
    scanf("%d", &a);
    scanf("%d", &b);

    p = &a;
    q = &b;

    printf("Enter array size: ");
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    if (A == NULL) {
        printf("Memory allocation failed");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &A[i]);
    }

    swap(&a, &b);
    swapd(&p, &q);
    bitcheck(a);
    reverse(&a);
    prime(A, n);
    int M = arrmax(A, n);
    int SM = arrsecmax(A, n);

    printf("\nMaximum element: %d", M);
    printf("\nSecond maximum element: %d", SM);

    free(A);

    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
    printf("\nSwapped: %d, %d", *a, *b);
}

void swapd(int **a, int **b) {
    int t = **a;
    **a = **b;
    **b = t;
    printf("\nSwapped using double pointers: %d, %d", **a, **b);
}

void bitcheck(int a) {
    if (a & 1) {
        printf("\n%d is Odd",a);
    } else {
        printf("\n%d is Even",a);
    }
}

void reverse(int *a) {
    int c = 0;
    int x= *a;
    while (*a > 0) {
        c = c * 10 + (*a % 10);
        *a = *a / 10;
    }
    
    printf("\n%d Reverse: %d", x,c);
}

int arrmax(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > m) {
            m = a[i];
        }
    }
    return m;
}

int arrsecmax(int a[], int n) {
    int max1 = arrmax(a, n);
    int max2 = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] != max1 && (max2 == -1 || a[i] > max2)) {
            max2 = a[i];
        }
    }
    return max2;
}

void prime(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int l = 0;
        for (int j = 1; j <= a[i]; j++) {
            if (a[i] % j == 0) {
                l++;
            }
        }
        if (l == 2) {
            sum += a[i];
        }
    }
    printf("\nSum of prime numbers in the array: %d", sum);
}
