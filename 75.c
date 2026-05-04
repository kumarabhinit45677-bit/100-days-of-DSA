#include <stdio.h>
#include <stdlib.h>

int maxLen(int arr[], int n)
{
    int sum = 0, maxLen = 0;

    // hash map using array (range assumption)
    int map[100000] = {0}; // initialize to 0
    for(int i = 0; i < 100000; i++)
        map[i] = -2; // mark as not seen

    map[50000] = -1; // sum = 0 at index -1

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        int key = sum + 50000; // shift to avoid negative index

        if(map[key] != -2)
        {
            int len = i - map[key];
            if(len > maxLen)
                maxLen = len;
        }
        else
        {
            map[key] = i;
        }
    }

    return maxLen;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d", maxLen(arr, n));
    return 0;
}
