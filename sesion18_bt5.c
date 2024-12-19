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
    int n;
    int found = 0;
    printf("Nhap id cua sinh vien can sua: ");
    scanf("%d", &n);
    for (int i = 0; i < 5; i++) {
        if (sv[i].id == n) {
            found = 1;
            printf("Sinh vien tim thay: \n");
            printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
            printf("Nhap ten moi: ");
            getchar(); 
            fgets(sv[i].name, sizeof(sv[i].name), stdin);
            printf("Nhap tuoi moi: ");
            scanf("%d", &sv[i].age);
            printf("Thong tin sinh vien sau khi sua :\n");
            printf("sinh vien %d",sv[i].id);
			printf("ten cua sinh vien %d la : %s\n",i+1,sv[i].name);
			printf("tuoi cua sinh sien %d la : %d\n",i+1,sv[i].age);
			printf("so dien thoai cua sinh vien %d la : %s\n",i+1,sv[i].phoneNumber);
			printf("\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co id %d\n", n);
    }
    printf("\nDanh sach sinh vien sau khi sua:\n");
    for (int i = 0; i < 5; i++) {
    	printf("sinh vien %d\n",sv[i].id);
		printf("ten cua sinh vien %d la : %s\n",i+1,sv[i].name);
		printf("tuoi cua sinh sien %d la : %d\n",i+1,sv[i].age);
		printf("so dien thoai cua sinh vien %d la : %s\n",i+1,sv[i].phoneNumber);
		printf("\n");
    }

    return 0;
}

