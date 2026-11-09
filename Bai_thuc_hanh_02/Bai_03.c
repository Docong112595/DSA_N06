#include<stdio.h>
typedef struct{
    char hoten[30];
    int masv;
    float d1, d2, d3;
} sv;
void nhap(sv *p, int n){
	int i;
    for(i=0; i<n; i++){
        printf("\nNhap sinh vien %d:\n", i + 1);
        printf("Ho ten: ");
        scanf(" %[^\n]", (p+i)->hoten);
        printf("Ma SV: ");
        scanf("%d", &(p+i)->masv);
        printf("Diem 1: ");
        scanf("%f", &(p+i)->d1);
        printf("Diem 2: ");
        scanf("%f", &(p+i)->d2);
        printf("Diem 3: ");
        scanf("%f", &(p+i)->d3);
    }
}
void in(sv *p, int n){
	int i;
    for(i=0; i<n; i++){
        printf("\nSinh vien %d:\n", i + 1);
        printf("Ho ten: %s\n", (p+i)->hoten);
        printf("Ma SV: %d\n", (p+i)->masv);
        printf("Diem 1: %.2f\n", (p+i)->d1);
        printf("Diem 2: %.2f\n", (p+i)->d2);
        printf("Diem 3: %.2f\n", (p+i)->d3);
    }
}
int main(){
    sv a[100];
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    nhap(a, n);
    printf("\nDANH SACH SINH VIEN:\n");
    in(a, n);
    return 0;
}
