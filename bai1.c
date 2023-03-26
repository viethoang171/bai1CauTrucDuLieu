#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define maxn 100000
int array[maxn], first[maxn], end[maxn];
long long sumArray[maxn];
int main()
{
    clock_t start, endd;
    start = clock();
    int n; // so luong phan tu trong mang
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    printf("\n Nhap cac phan tu: ");
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % maxn - 5000;
        printf("%d ", array[i]);
        if (i == 0)
            sumArray[i] = array[i];
        else
        {
            if (array[i] > sumArray[i - 1] + array[i])
            {
                sumArray[i] = (sumArray[i - 1] > array[i]) ? sumArray[i - 1] : array[i];
                first[i] = (sumArray[i - 1] > array[i]) ? first[i - 1] : i;
                end[i] = (sumArray[i - 1] > array[i]) ? end[i - 1] : i;
            }
            else
            {
                sumArray[i] = (sumArray[i - 1] > sumArray[i - 1] + array[i]) ? sumArray[i - 1] : sumArray[i - 1] + array[i];
                first[i] = first[i - 1];
                end[i] = (sumArray[i - 1] > sumArray[i - 1] + array[i]) ? end[i] : i;
            }
        }
    }
    printf("\n");
    printf("Tong day con lon nhat la: %d\n", sumArray[n - 1]);
    printf("Day con do la: ");
    for (int i = first[n - 1]; i <= end[n - 1]; i++)
        printf("%d ", array[i]);
    endd = clock();
    double cpuTimeUse = (double)(endd - start) / CLOCKS_PER_SEC;
    printf("\nThoi gian chay la: %lf secs", cpuTimeUse);
    return 0;
}