#include <stdio.h>
#define SIZE 10
struct H
{
    int key, used;
};
int hash(int k) { return k % SIZE; }
int main()
{
    struct H t[SIZE];
    int n, k, i, idx;
    for (i = 0; i < SIZE; i++)
        t[i].used = 0;
    printf("Enter number of keys: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        idx = hash(k);
        while (t[idx].used)
            idx = (idx + 1) % SIZE;
        t[idx].key = k;
        t[idx].used = 1;
        printf("Inserted %d at %d\n", k, idx);
    }
    printf("\nIndex  Key\n");
    for (i = 0; i < SIZE; i++)
        printf("%d\t%s\n", i, t[i].used ? (sprintf((char[20]){}, "%d", t[i].key), (char[20]){}) : "Empty");
    return 0;
}
