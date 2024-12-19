#include<stdio.h>
struct SinhVien{
	char name[50];
    char numberPhone[20];
	int age;
};
int main(){
	struct SinhVien cn1;
    strcpy(cn1.name," Pham Tien Hung");
    strcpy(cn1.numberPhone,"0876109917");
    cn1.age = 18;
    printf("ten cua ban la : %s \n", cn1.name);
    printf("tuoi cua ban la  : %d \n", cn1.age);
    printf("so dien thoai cua ban la : %s \n",cn1.numberPhone);
  return 0;
}


