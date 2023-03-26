#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define maxn 100000
int array[maxn], first, end;
long long sum, sumMax;
int main()
{
    int n; // so luong phan tu trong mang
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    printf("\n Nhap cac phan tu: ");
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % maxn - 5000;
        printf("%d ", array[i]);
    }
    sumMax = array[0];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
                sum += array[k];
            if (sum > sumMax)
            {
                sum = sumMax;
                first = i;
                end = j;
            }
        }
    printf("\n");
    printf("Tong day con lon nhat la: %d\n", sumMax);
    printf("Day con do la: ");
    for (int i = first; i <= end; i++)
        printf("%d ", array[i]);
    return 0;
}