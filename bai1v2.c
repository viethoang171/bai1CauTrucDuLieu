#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define maxn 100000
int array[maxn], first, end;
long long sumArray[maxn], sumMax;
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
        if (i == 0)
            sumArray[i] = array[i];
        else
            sumArray[i] = sumArray[i - 1] + array[i];
    }
    sumMax = array[0];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (i == 0)
            {
                if (sumMax > sumArray[j])
                {
                    sumMax = sumArray[j];
                    first = 0;
                    end = j;
                }
            }
            else
            {
                if (sumArray[j] - sumArray[i - 1] > sumMax)
                {
                    sumMax = sumArray[j] - sumArray[i - 1];
                    first = i;
                    end = j;
                }
            }
        }
    printf("\n");
    printf("Tong day con lon nhat la: %d\n", sumMax);
    printf("Day con do la: ");
    for (int i = first; i <= end; i++)
        printf("%d ", array[i]);
    return 0;
}