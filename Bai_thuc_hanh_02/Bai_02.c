#include <stdio.h>
#include <stdlib.h>
int main() {
    int h, c;
    int i, j;
    printf("Nhap so hang va so cot: ");
    scanf("%d%d", &h, &c);
    if(h <= 0 || c <= 0) {
        printf("Kich thuoc ma tran khong hop le!\n");
        return 1;
    }
    int **ma = (int **)malloc(h * sizeof(int *));
    if(ma == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }
    for(i = 0; i < h; i++) {
        ma[i] = (int *)malloc(c * sizeof(int));
        if(ma[i] == NULL) {
            printf("Khong du bo nho tai dong %d!\n", i);
            for(j = 0; j < i; j++) {
                free(ma[j]);
            }
            free(ma);
            return 1;
        }
    }
    for(i = 0; i < h; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &ma[i][j]);
        }
    }
    printf("Ma tran %dx%d vua tao:\n", h, c);
    for(i = 0; i < h; i++) {
        for(j = 0; j < c; j++) {
            printf("%d\t", ma[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < h; i++) {
        free(ma[i]);
    }
    free(ma);
    return 0;
}
