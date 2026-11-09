#include<stdio.h>
int main(){
    int n;
    float a[100];
    float *p;
    p = a;
    printf("Nhap n: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%f", p + i);
	}
    for(int i=0; i<n; i++){
        printf("%.2f ", *(p + i));
	}
    return 0;
}
