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

    int idEdit;
    printf("Nhap ID cua sinh vien muon sua: ");
    scanf("%d", &idEdit);
    getchar(); 
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (sv[i].id == idEdit) {
            found = 1;
            printf("Sinh vien %d tim thay:\n", sv[i].id);
            printf("Ten hien tai: %s\n", sv[i].name);
            printf("Nhap ten moi: ");
            fgets(sv[i].name, sizeof(sv[i].name), stdin);
            sv[i].name[strcspn(sv[i].name, "\n")] = '\0'; 
            printf("Nhap tuoi moi: ");
            scanf("%d", &sv[i].age);

            printf("Thong tin sinh vien sau khi sua:\n");
            printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ID %d.\n", idEdit);
    }
    printf("\nDanh sach sinh vien sau khi sua:\n");
    for (int i = 0; i < 5; i++) {
        printf("Sinh vien %d:\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n", sv[i].phoneNumber);
        printf("\n");
    }

    return 0;
}


