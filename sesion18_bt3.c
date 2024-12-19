#include<stdio.h>
#include<stdlib.h>
struct SinhVien{
	char name[50];
    char numberPhone[20];
	int age;
};
int main(){
struct SinhVien sv1;
for(int i=0;i<=5;i++){
	printf("moi ban nhap thong tin sinh vien %d \n",i+1);
	printf("moi ban nhap ten  : ");
	fgets(sv1.name,sizeof(sv1.name),stdin);
    printf("moi ban nhap tuoi : ");
    scanf("%d",&sv1.age);
	printf("moi ban nhap so dien thoai: ");
	getchar();
	fgets(sv1.numberPhone,sizeof(sv1.numberPhone),stdin);

}
for(int i=0;i<5;i++){    
	printf("ten cua sinh vien %d la : %s",i+1,sv1.name);
	printf("tuoi cua sinh sien %d la : %d\n",i+1,sv1.age);
	printf("so dien thoai cua sinh vien %d la : %s\n",i+1,sv1.numberPhone);
	printf("\n");
}	
  return 0;
}

