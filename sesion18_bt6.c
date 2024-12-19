#include<stdio.h>
#include<string.h>
struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};
int main() {
    struct SinhVien sv[50] = {
        {1, "Pham Tien Hung", 18, "0876109917"},
        {2, "Tran Minh Tu", 21, "0987654321"},
        {3, "Le Thi Lan", 22, "0145833445"},
        {4, "Dang Thi Hong Hue", 18, "0437765432"},
        {5, "Pham Van Ly", 24, "092249155"}
    };
    int size = 5;
        printf("Nhap thong tin sinh vien moi:\n");
        sv[size].id = size + 1;
        printf("Ten: ");
        getchar(); 
        fgets(sv[size].name, sizeof(sv[size].name), stdin);
        printf("Tuoi: ");
        scanf("%d", &sv[size].age);
        printf("So dien thoai: ");
        getchar();  
        fgets(sv[size].phoneNumber, sizeof(sv[size].phoneNumber), stdin);
        size++;
        printf("\nDanh sach sinh vien sau khi them moi:\n");
        for (int i = 0; i < size; i++) {
            printf("Sinh vien %d:\n", sv[i].id);
            printf("Ten: %s\n", sv[i].name);
            printf("Tuoi: %d\n", sv[i].age);
            printf("So dien thoai: %s\n", sv[i].phoneNumber);
            printf("\n");
        }
    return 0;
}

