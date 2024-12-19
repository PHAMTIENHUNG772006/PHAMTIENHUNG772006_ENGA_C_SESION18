#include <stdio.h>
#include <string.h>
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

    int Size = 5;
    char nameDel[50];
    printf("Nhap ten sinh vien can xoa: ");
    getchar();  
    fgets(nameDel, sizeof(nameDel), stdin);
    int found = 0;
    for (int i = 0; i < Size; i++) {
        if (strcmp(sv[i].name, nameDel) == 0) {
            found = 1;
            printf("Sinh vien %s da duoc tim thay. Xoa sinh vien...\n", sv[i].name);
            for (int j = i; j < Size - 1; j++) {
                sv[j] = sv[j + 1];
            }
            Size--;
            break;
        }
    }

    if (!found) {
        printf("Sinh vien %s khong ton tai trong danh sach.\n", nameDel);
    } else {
        printf("\nDanh sach sinh vien sau khi xoa:\n");
        for (int i = 0; i < Size; i++) {
            printf("Sinh vien %d:\n", sv[i].id);
            printf("Ten: %s\n", sv[i].name);
            printf("Tuoi: %d\n", sv[i].age);
            printf("So dien thoai: %s\n", sv[i].phoneNumber);
            printf("\n");
        }
    }

    return 0;
}

