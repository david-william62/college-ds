#include <stdio.h>
int findIndex(int degree, int degrees[], int size) {
    for (int i = 0; i < size; i++) {
        if (degrees[i] == degree) {
            return i;
        }
    }
    return -1;
}
void main() {
    int s1, s2, i, j;
    printf("Enter number of terms in 1st and 2nd polynomial \n");
    scanf("%d %d", &s1, &s2);
    int c1[s1], d1[s1], c2[s2], d2[s2];
    int max_terms = s1 + s2;
    int sc[max_terms], sd[max_terms];
    printf("Enter the coefficient and degree of 1st polynomial \n");
    for (i = 0; i < s1; i++) {
        scanf("%d %d", &c1[i], &d1[i]);
    }
    printf("Enter the coefficient and degree of 2nd polynomial \n");
    for (i = 0; i < s2; i++) {
        scanf("%d %d", &c2[i], &d2[i]);
    }
    for (i = 0; i < max_terms; i++) {
        sc[i] = 0;
        sd[i] = -1;
    }
    int result_size = 0;
    for (i = 0; i < s1; i++) {
        int index = findIndex(d1[i], sd, result_size);
        if (index == -1) {
            sd[result_size] = d1[i];
            sc[result_size] = c1[i];
            result_size++;
        } else {
            sc[index] += c1[i];
        }
    }
    for (i = 0; i < s2; i++) {
        int index = findIndex(d2[i], sd, result_size);
        if (index == -1) {
            sd[result_size] = d2[i];
            sc[result_size] = c2[i];
            result_size++;
        } else {
            sc[index] += c2[i];
        }
    }
    printf("Resultant Polynomial is: ");
    for (i = 0; i < result_size; i++) {
        printf("(%dx^(%d))", sc[i], sd[i]);
        if (i < result_size - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}
