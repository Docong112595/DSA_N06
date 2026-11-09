#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;
typedef struct tagNode {
    Data infor;
    struct tagNode *link;
} Node;
typedef struct {
    Node *pHead;
    Node *pTail;
    int spt;
} LList;
void initList(LList *L) {
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
int emptyList(LList L) {
    return (L.spt == 0);
}
void insert_Head(LList *L, Data x) {
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));
    if(pp == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }
    pp->infor = x;
    pp->link = NULL;
    if(emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    }
    else {
        pp->link = L->pHead;
        L->pHead = pp;
    }
    L->spt++;
}
void insert_Tail(LList *L, Data x) {
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));
    if(pp == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }
    pp->infor = x;
    pp->link = NULL;
    if(emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    }
    else {
        L->pTail->link = pp;
        L->pTail = pp;
    }
    L->spt++;
}
int insert_After(LList *L, int masv, Data x) {
    Node *pp, *q;
    q = L->pHead;
    while(q != NULL && q->infor.masv != masv) {
        q = q->link;
    }
    if(q == NULL) {
        return 0;
    }
    pp = (Node*)malloc(sizeof(Node));
    if(pp == NULL) {
        printf("Khong du bo nho!\n");
        return 0;
    }
    pp->infor = x;
    pp->link = q->link;
    q->link = pp;
    if(q == L->pTail) {
        L->pTail = pp;
    }
    L->spt++;
    return 1;
}
void nhap(Data *x) {
    printf("Nhap ma SV: ");
    scanf("%d", &x->masv);
    if(x->masv > 0) {
        printf("Nhap ho ten: ");
        scanf(" %29[^\n]", x->hoten);
        printf("Nhap diem mon 1: ");
        scanf("%f", &x->d1);
        printf("Nhap diem mon 2: ");
        scanf("%f", &x->d2);
        printf("Nhap diem mon 3: ");
        scanf("%f", &x->d3);
    }
}
void in(Data x) {
    printf("Ten: %s\n", x.hoten);
    printf("Ma SV: %d\n", x.masv);
    printf("Diem 1: %.2f\n", x.d1);
    printf("Diem 2: %.2f\n", x.d2);
    printf("Diem 3: %.2f\n", x.d3);
}
void processList(LList L) {
    Node *pp;
    pp = L.pHead;
    if(emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }
    while(pp != NULL) {
        in(pp->infor);
        printf("--------------------\n");
        pp = pp->link;
    }
    printf("Tong so sinh vien: %d\n", L.spt);
}
void freeList(LList *L) {
    Node *pp;
    while(L->pHead != NULL) {
        pp = L->pHead;
        L->pHead = L->pHead->link;
        free(pp);
    }
    L->pTail = NULL;
    L->spt = 0;
}
int main() {
    LList L;
    Data x;
    int kt = 0;
    int chon;
    int masv;
    initList(&L);
    do {
        printf("\nCHUONG TRINH LAM VIEC VOI DSLK DON SV\n");
        printf("\n1: Them nut vao dau danh sach");
        printf("\n2: Them nut vao cuoi danh sach");
        printf("\n3: Them nut vao sau mot nut khac");
        printf("\n9: Duyet danh sach");
        printf("\n0: Thoat");
        printf("\nMoi ban chon: ");
        scanf("%d", &chon);
        switch(chon) {
            case 1:
                nhap(&x);
                if(x.masv > 0) {
                    insert_Head(&L, x);
                }
                break;
            case 2:
                nhap(&x);
                if(x.masv > 0) {
                    insert_Tail(&L, x);
                }
                break;
            case 3:
                printf("Nhap ma SV muon them sau: ");
                scanf("%d", &masv);
                nhap(&x);
                if(x.masv > 0) {
                    if(insert_After(&L, masv, x)) {
                        printf("Them thanh cong!\n");
                    }
                    else {
                        printf("Khong tim thay sinh vien!\n");
                    }
                }
                break;
            case 9:
                processList(L);
                break;
            case 0:
                printf("Bye bye!\n");
                kt = 1;
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(kt == 0);
    freeList(&L);
    return 0;
}
