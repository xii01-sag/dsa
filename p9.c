#include <stdio.h>
#include <stdlib.h>
struct T
{
    int c, x, y, z;
    struct T *next;
};
typedef struct T T;
T *create(int c, int x, int y, int z)
{
    T *t = malloc(sizeof(T));
    t->c = c;
    t->x = x;
    t->y = y;
    t->z = z;
    t->next = t;
    return t;
}
void insert(T **h, int c, int x, int y, int z)
{
    T *t = create(c, x, y, z);
    if (!*h)
        *h = t;
    else
    {
        T *cur = *h;
        while (cur->next != *h)
            cur = cur->next;
        cur->next = t;
        t->next = *h;
    }
}
void display(T *h)
{
    if (!h)
    {
        printf("Empty\n");
        return;
    }
    T *c = h;
    do
    {
        printf("%dx^%dy^%dz^%d", c->c, c->x, c->y, c->z);
        c = c->next;
        if (c != h)
            printf(" + ");
    } while (c != h);
    printf("\n");
}
T *add(T *p1, T *p2)
{
    T *r = NULL, *a = p1, *b = p2;
    do
    {
        insert(&r, a->c + b->c, a->x, a->y, a->z);
        a = a->next;
        b = b->next;
    } while (a != p1 && b != p2);
    return r;
}
void freePoly(T **h)
{
    if (!*h)
        return;
    T *c = *h, *n;
    do
    {
        n = c->next;
        free(c);
        c = n;
    } while (c != *h);
    *h = NULL;
}
int main()
{
    T *p1 = NULL, *p2 = NULL, *sum;
    insert(&p1, 6, 2, 2, 1);
    insert(&p1, -4, 0, 1, 5);
    insert(&p1, 3, 3, 1, 1);
    insert(&p1, 2, 1, 5, 1);
    insert(&p1, -2, 1, 1, 3);
    insert(&p2, 2, 2, 2, 1);
    insert(&p2, 5, 0, 1, 5);
    insert(&p2, -1, 3, 1, 1);
    printf("Polynomial 1: ");
    display(p1);
    printf("Polynomial 2: ");
    display(p2);
    sum = add(p1, p2);
    printf("Sum: ");
    display(sum);
    freePoly(&p1);
    freePoly(&p2);
    freePoly(&sum);
    return 0;
}
