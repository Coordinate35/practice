# include<stdio.h>

void insert_sort(int left, int right, int* a)
{
    int i, j;
    for (i = left + 1; i < right; i++)
    {
        j = i;
        while ((a[j] < a[j-1]) && (j > left))
        {
            if (a[j] < a[j-1])
            {
                a[j]   = a[j] ^ a[j-1];
                a[j-1] = a[j-1] ^ a[j];
                a[j]   = a[j] ^ a[j-1];
            }
            j--;
        }
    }
}

int partition(int left, int right, int stardard, int* a)
{
    int i, j;
    j = left;
    for (i = left; i <= right; i++)
    {
        if (a[i] < stardard)
        {
            a[j] = a[j] ^ a[i];
            a[i] = a[i] ^ a[j];
            a[j] = a[j] ^ a[i];
            j++;
        }
    }
    return j - 1;
}

int select(int left, int right, int* a)
{
    int group, i, j, n;
    int median[5];
    n     = right - left + 1;
    group = n / 5;
    j     = 0;
    for (i = left; i <= n; i += 5)
    {
        insert_sort(i, i + 4, a);
        median[j] = a[i + 2];
        j++;
    }
    if (0 != n % 5)
    {
        insert_sort(i, right, a);
        median[j] = a[(right + i) / 2];
        j++;
        group++;
    }
    if (0 != j / 5)
    {
        select(0, group, median);
    }
    else
    {
        return a[(right + left) / 2];
    }
}

int find(int position, int n, int* a)
{
    int k;
    k = 0;
    left = 0;
    right = n;
    while (k != position)
    {
        stardard = select(left, right, a);
        k = partition(left, right, stardard, a);
        if (k > position)
        {
            right = k;
        }
        else if (k < position)
        {
            left = k;
        }
    }
    return a[k];
}

int main()
{
    int n, left, right, i, j, position, result;
    //position表示查找第position大的数
    int a[20];
    scanf("\d\d", &n, &position);
    for (i = 0; i < n; i++)
    {
        scanf("\d", a + i);
    }
    result = find(position, n, a);
    printf("\d\n", result);
    return 0;
}
