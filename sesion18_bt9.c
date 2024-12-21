#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dish{
    int id;
    char name[50];
    float price;
};

void printMenu(struct Dish *menu, int size);
void addMenu(struct Dish *menu, int *size, int x);
void editMenu(struct Dish *menu, int *size, int x);
void deleteMenu(struct Dish *menu, int *size, int x);
void sapXep(struct Dish *menu, int size, int choice);
void searchMenu(struct Dish *menu, int size, char name[]);

int main(){
    int choice;
    int size = 5;
    int x;
    char name[50];
    struct Dish menu[20] = {
        {1, "Tra Da", 5.000},
        {2, "Tra Vai", 25.000},
        {3, "Tra o long", 30.000},
        {4, "Tra Tac", 10.000},
        {5, "Huong Duong", 25.000}
    };

    do{
        printf("\n********MENU*******\n");
        printf("1.  In ra gia tri phan tu mon an trong menu theo mon an\n");
        printf("2. them mot phan tu vao vi tri chi dinh\n");
        printf("3. sua mot phan tu o vi tri chi dinh\n");
        printf("4. xoa mot phan tu o vi tri chi dinh\n");
        printf("5. sap xep cac phan tu\n");
        printf("6. tim kiem cac phan tu theo name nhap vao\n");
        printf("7. Thoat\n");
        printf("hay chon chuc nang (1-7): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printMenu(menu, size);
                break;
            case 2:
                addMenu(menu, &size, x);
                break;
            case 3:
                editMenu(menu, &size, x);
                break;
            case 4:
                deleteMenu(menu, &size, x);
                break;
            case 5:
                sapXep(menu, size, choice);
                break;
            case 6:
                searchMenu(menu, size, name);
                break;
            case 7:
                printf("da thoat chuong trinh\n");
                break;
            default:
                printf("Loi: Chuc nang khong hop le\n");
        }
    } while(choice != 7);

    return 0;
}

void printMenu(struct Dish *menu, int size){
    for(int i = 0; i < size; i++){
        printf("%d. %s : %.2f VND\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

void addMenu(struct Dish *menu, int *size, int x) {
    printf("Moi ban nhap vi tri them (1-%d): ", *size + 1);
    scanf("%d", &x);
    if (x < 1 || x > *size + 1) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = *size; i >= x; i--) {
        menu[i] = menu[i - 1];
    }
    printf("Nhap ten mon an: ");
    getchar();  
    fgets(menu[x - 1].name, sizeof(menu[x - 1].name), stdin);
    menu[x - 1].name[strcspn(menu[x - 1].name, "\n")] = 0; 
    printf("Nhap gia mon an: ");
    scanf("%f", &menu[x - 1].price);
    (*size)++;
    printf("Mon an da duoc them vao vi tri %d.\n", x);
}

void editMenu(struct Dish *menu, int *size, int x) {
    printf("Moi ban nhap vi tri sua (1-%d): ", *size);
    scanf("%d", &x);
    if (x < 1 || x > *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    printf("Nhap ten mon an can sua: ");
    getchar();  
    fgets(menu[x - 1].name, sizeof(menu[x - 1].name), stdin);
    menu[x - 1].name[strcspn(menu[x - 1].name, "\n")] = 0; 
    printf("Nhap gia mon an: ");
    scanf("%f", &menu[x - 1].price);
    printf("Mon an da duoc sua o vi tri %d.\n", x);
}

void deleteMenu(struct Dish *menu, int *size, int x) {
    printf("Moi ban nhap vi tri xoa (1-%d): ", *size);
    scanf("%d", &x);
    if (x < 1 || x > *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = x - 1; i < *size - 1; i++) {
        menu[i] = menu[i + 1];
    }
    (*size)--;
    printf("Mon an da duoc xoa khoi vi tri %d.\n", x);
}

void sapXep(struct Dish *menu, int size, int choice) {
    int sortChoice;
    printf("1. Sap xep tang dan\n");
    printf("2. Sap xep giam dan\n");
    printf("Hay chon chuc nang (1-2): ");
    scanf("%d", &sortChoice);

    switch (sortChoice) {
        case 1:
            for (int i = 0; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (menu[i].price > menu[j].price) {
                        struct Dish temp = menu[i];
                        menu[i] = menu[j];
                        menu[j] = temp;
                    }
                }
            }
            printMenu(menu, size);
            break;
        case 2:
            for (int i = 0; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    if (menu[i].price < menu[j].price) {
                        struct Dish temp = menu[i];
                        menu[i] = menu[j];
                        menu[j] = temp;
                    }
                }
            }
            printMenu(menu, size);
            break;
        default:
            printf("Du lieu sai, vui long nhap lai.\n");
    }
}

void searchMenu(struct Dish *menu, int size, char name[]) {
    printf("Nhap ten mon an can tim: ");
    getchar(); 
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; 
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(menu[i].name, name)) {
            printf("Mon an: %s, Gia: %.2f VND\n", menu[i].name, menu[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an theo ten '%s'.\n", name);
    }
}

