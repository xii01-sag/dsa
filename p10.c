#include <stdio.h>
#include <stdlib.h>
struct N
{
    int d;
    struct N *l, *r;
};
typedef struct N N;
N *newNode(int v)
{
    N *t = malloc(sizeof(N));
    t->d = v;
    t->l = t->r = NULL;
    return t;
}
N *insert(N *r, int v)
{
    if (!r)
        return newNode(v);
    if (v < r->d)
        r->l = insert(r->l, v);
    else if (v > r->d)
        r->r = insert(r->r, v);
    return r;
}
void inorder(N *r)
{
    if (r)
    {
        inorder(r->l);
        printf("%d ", r->d);
        inorder(r->r);
    }
}
void preorder(N *r)
{
    if (r)
    {
        printf("%d ", r->d);
        preorder(r->l);
        preorder(r->r);
    }
}
void postorder(N *r)
{
    if (r)
    {
        postorder(r->l);
        postorder(r->r);
        printf("%d ", r->d);
    }
}
N *search(N *r, int k)
{
    if (!r || r->d == k)
        return r;
    return k < r->d ? search(r->l, k) : search(r->r, k);
}
void freeBST(N *r)
{
    if (r)
    {
        freeBST(r->l);
        freeBST(r->r);
        free(r);
    }
}
int main()
{
    N *root = NULL;
    int ch, k, a[] = {6, 9, 5, 2, 8, 15, 24, 14, 7};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, a[i]);
    while (1)
    {
        printf("\n1.Inorder 2.Preorder 3.Postorder 4.Search 5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        case 4:
            printf("Enter key: ");
            scanf("%d", &k);
            printf(search(root, k) ? "Found\n" : "Not Found\n");
            break;
        case 5:
            freeBST(root);
            exit(0);
        default:
            printf("Invalid\n");
        }
    }
}
