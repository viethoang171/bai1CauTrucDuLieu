#include <stdio.h>
#define maxn 10000
int array[maxn], sumArray[maxn], sumResult, first, end;
int main()
{
    int n; // so luong phan tu trong mang
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    printf("\n Nhap cac phan tu: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        if (i == 0)
            sumArray[i] = array[i];
        else
            sumArray[i] = sumArray[i - 1] + array[i];
    }
    sumResult = array[0];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (i == 0)
            {
                if (sumArray[j] > sumResult)
                {
                    first = i;
                    end = j;
                    sumResult = sumArray[j];
                }
            }
            else
            {
                if (sumArray[j] - sumArray[i - 1] > sumResult)
                {
                    first = i;
                    end = j;
                    sumResult = sumArray[j] - sumArray[i - 1];
                }
            }
    printf("Tong day con lon nhat la: %d\n", sumResult);
    printf("Day con do la: ");
    for (int i = first; i <= end; i++)
        printf("%d ", array[i]);
    return 0;
}