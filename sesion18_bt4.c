#include<stdio.h>
#include<stdlib.h>
struct SinhVien{
	char name[50];
    char numberPhone[20];
	int age;
	int id;
};
int main(){
struct SinhVien sv[5];
for(int i=0;i<=5;i++){
	sv[i].id = i+1;
	printf("moi ban nhap thong tin sinh vien %d \n",i+1);
	printf("sinh vien %s\n", sv[i].id+i);
	printf("moi ban nhap ten  : ");
	fgets(sv[i].name,sizeof(sv[i].name),stdin);
    printf("moi ban nhap tuoi : ");
    scanf("%d",&sv[i].age);
	printf("moi ban nhap so dien thoai: ");
	getchar();
	fgets(sv[i].numberPhone,sizeof(sv[i].numberPhone),stdin);

}
for(int i=0;i<5;i++){
	printf("sinh vien %d",sv[i].id);
	printf("ten cua sinh vien %d la : %s",i+1,sv[i].name);
	printf("tuoi cua sinh sien %d la : %d\n",i+1,sv[i].age);
	printf("so dien thoai cua sinh vien %d la : %s\n",i+1,sv[i].numberPhone);
	printf("\n");
}
  return 0;
}

