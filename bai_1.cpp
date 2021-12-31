// NGUYEN DANG QUY
// CNTT - K62
// 6251071076

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

// Nhap mang
void nhapMang(int *a, int n){
	for(int i=0; i<n; i++) {
		printf("a[%d] = ", i+1);
		scanf("%d", a+i);
	}
}

// Xuat mang voi 1 dong khong qua 10 phan tu
void xuatMang(int *a, int n) {
	if(n==0) {
		printf("- Trong mang khong con phan tu nao!");
	}
	else {
		printf("- Mang cua ban la\n");
		for(int i=0; i<n; i++) {
			printf("%5d", *(a+i));
			if((i+1)%10==0){
				printf("\n");
			}
		}
	}
}

// Tim phan tu lon nhat, nho nhat cua mang
void timphantuMax_Min(int *a, int n) {
	int min = *a;
	int max = *a;
	for(int i=0; i<n; i++) {
		if(*(a+i) > max) max = *(a+i);
	}
	for(int i=0; i<n; i++) {
		if(*(a+i) < min) min = *(a+i);
	}
	printf("- Phan tu lon nhat trong mang la: %d", max);
	printf("\n- Phan tu nho nhat nhat trong mang la: %d", min);
}

// Vi tri phan tu duong nho nhat 
void vitriPhanTuDuongMin(int *a, int n) {
	int min;
	int vitri=-1;
	for(int i=0; i<n; i++) {
		if(*(a+i) > 0) {
			min = *(a+i);
			vitri = i;
		}
	}
	for(int i=0; i<n; i++) {
		if(*(a+i) > 0 && *(a+i) < min) {
			min = *(a+i);
			vitri = i;
		}
	}
	if(vitri == -1) {
		printf("- Khong co phan tu duong nao trong mang!");
	}
	else {
		printf("- Vi tri phan tu duong nho nhat trong mang la vi tri so %d", vitri+1);		
	}
}

// Tong cua mang 
void tongcuaMang(int *a, int n) {
	int tong = 0;
	for(int i=0; i<n; i++) {
		tong += *(a+i);
	}
	printf("- Tong cua mang la: %d", tong);
}

// Trung binh cong, trung binh nhan cua mang
void TBC_TBN(int *a, int n) {
	// Trung binh cong
	float TBC;
	int tong = 0;
	for(int i=0; i<n; i++) {
		tong += *(a+i);
	}
	TBC = tong/n;
	printf("- Trung binh cong la: %.2f", TBC);
	// Trung binh nhan
	float TBN;
	int tich=1;
	for(int i=0; i<n; i++) {
		tich *= *(a+i);
	}
	float soMu = 1.0/n;
	if (int(soMu) == soMu && soMu > 0) {
		printf("\n- Trung binh nhan cua mang la: %.2f", pow(tich, soMu));
	}
	else if (soMu >= 0 && tich == 0) {
		printf("\n- Trung binh nhan cua mang la: %d", tich);
	}
	else if (int(soMu) == soMu && soMu<=0 && tich!=0) {
		printf("\n- Trung binh nhan cua mang la: %.2f", pow(tich, soMu));
	}
	else if (int(soMu) != soMu && tich>0) {
		printf("\n- Trung binh nhan cua mang la: %.2f", pow(tich, soMu));
	}
	else {
		printf("\n- Khong the tinh trung binh nhan!");
	}
}

// Tim kiem phan tu x nhap tu ban phim
void timkiemphantuX(int *a, int n, int x) {
	printf("- Nhap phan tu can tim: ");
	scanf("%d", &x);
	int vitri;
	bool timkiem = false;
	for(int i=0; i<n; i++) {
		if(*(a+i) == x) {
			timkiem = true;
			vitri=i;
			break;
		}
	}
	if(timkiem == true) {
		printf("- Da tim thay phan tu %d nam o vi tri: %d", x, vitri+1);
	}
	else {
		printf("- Khong tim thay phan tu %d trong mang!", x);
	}
}

// Sap xep tang dan, giam dan
void sapxep(int *a, int n) {
	int luachon;
	printf("\t1. Tang dan");
	printf("\n\t2. Giam dan");
	printf("\n\tLua chon cua ban la: ");
	scanf("%d", &luachon);
	switch(luachon) {
		case 1:
			// Tang dan
			for(int i=0; i<n-1; i++) {
				for(int j=i+1; j<n; j++) {
					if(*(a+i) > *(a+j)) {
						int temp = *(a+i);
						*(a+i) = *(a+j);
						*(a+j) = temp;
					}
				}
			}
			printf("\t- Mang theo thu tu tang dan la: ");
			for(int i=0; i<n; i++) {
				printf("%d ", *(a+i));
			}
			break;
		case 2:
			// Giam dan (cung co the xuat nguoc lai)
			for(int i=0; i<n-1; i++) {
				for(int j=i+1; j<n; j++) {
					if(*(a+i) < *(a+j)) {
						int temp = *(a+i);
						*(a+i) = *(a+j);
						*(a+j) = temp;
					}
				}
			}
			printf("\t- Mang theo thu tu giam dan la: ");
			for(int i=0; i<n; i++) {
				printf("%d ", *(a+i));
			}
			break;
		default: 
			printf("\t- Lua chon sai!");
			break;
	}
}

// Xuat day dao nguoc
void xuatDaoNguoc(int *a, int n) {
	for(int i=0; i<n/2; i++) {
		int temp = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = temp;
	}
	printf("- Day dao nguoc la: ");
	for(int i=0; i<n; i++) {
		printf("%d ", *(a+i));
	}
}

// Them vi tri x vao vi tri k
void themXvaoK(int *a, int &n, int x, int k) {
	printf("- Nhap gia tri can them: "); scanf("%d", &x);
	do {
		printf("- Nhap vi tri can them: "); scanf("%d", &k);
		if((k-1) >  n || (k-1) < 0) {
			printf("- Vi tri them vao khong ton tai. Vui long nhap lai!");
		}
	}while((k-1) > n || (k-1) < 0);
	n++;
	for(int i=n-1; i>=k; i--) {
		*(a+i) = *(a+i-1);
	}
	*(a+k-1) = x;
}

// Xoa phan tu vi tri k
void xoaPhanTuvitriK(int *a, int &n, int k) {
	do {
		printf("- Nhap vao vi tri can xoa: ");
		scanf("%d", &k);
		if(k<1 || k>n) {
			printf("- Vi tri xoa khong ton tai vui long nhap lai!");
		}
	}while(k<1 || k>n);
	for(int i=k-1; i<n-1; i++) {
		*(a+i) = *(a+i+1);
	}
	n--;
}

// Dem so phan tu duong va in ra tong cac phan tu duong trong mang
void DemvaInPhanTuDuong(int *a, int n) {
	int dem=0;
	int tong=0;
	for(int i=0; i<n; i++) {
		if(*(a+i) > 0){
			tong += *(a+i);
			dem++;
		}
	}
	printf("- So luong phan tu duong trong mang la: %d", dem); 
	printf("\n- Tong phan tu duong trong mang la: %d", tong);
}


// Kiem tra mang co doi xung hay khong
void kiemtraMangDoiXung(int *a, int n) {
	bool kiemtra = true;
	for(int i = 0; i<n/2; i++) {
		if(*(a+i) != *(a+(n-i-1))) {
			kiemtra = false;
			break;
		}
	}
	if(kiemtra == true) {
		printf("- Mang vua nhap doi xung");
	}
	else {
		printf("- Mang vua nhap KHONG doi xung");
	}
}

// Kiem tra mang co tang dan hay khong
void kiemtraMangtangdan(int *a, int n) {
	bool kiemtra = true;
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if(*(a+i) > *(a+j)) {
				kiemtra = false;
				break;
			}
		}
	}
	if(kiemtra==true) {
		printf("- Mang vua nhap la mang tang dan");
	}
	else {
		printf("- Mang vua nhap KHONG tang dan");
	}
}

// Kiem tra trong day co bao nhieu phan tu la so nguyen to
bool kiemtraSNT(int x) {
	if(x < 2) return false;
	for(int i=2; i<=sqrt(x); i++) {
		if(x%i==0) return false;
	}
	return true;
}
void kiemtracobaonhieuSNT(int *a, int n) {
	int dem=0;
	for(int i=0; i<n; i++) {
		if(kiemtraSNT(*(a+i)) == true) {
			dem++;
		}
	}
	printf("- Trong day co: %d SNT", dem);
}

// Kiem tra trong day co bao nhieu cap so ma so sau bang tong 2 so truoc
void kiemtrasoSaucobangtong_2soTruoc(int *a, int n) {
	int dem=0;
	for(int i=2; i<n; i++) {
		if(*(a+i) == *(a+i-1) + *(a+i-2)) {
			dem++;
		}
	}
	printf("- So cap so co sau bang tong 2 so truoc la: %d", dem);
}
	
// Kiem tra co bao nhieu cap ai + aj (i#j) la so nguyen to
void kiemtracapso_ai_aj_laSNT(int *a, int n) {
	int dem=0;
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if(kiemtraSNT( (*(a+i)+*(a+j))) == true){
				dem++;
			}
		}
	}
	printf("- So cap so ai + aj la SNT la: %d", dem);
}

int main() {
	int n;
	int *a;
	int x;
	int k;
	printf("\t\t\t-----Vui long nhap mang truoc!------\n");
	do {
		printf("- Nhap so luong phan tu n: ");
		scanf("%d", &n);
	}while(n<1);
	a = (int*) malloc (n*sizeof(int));
	nhapMang(a, n);
	int luachon;
	printf("1 . Xuat mang toi da khong qua 10 phan tu tren 1 hang\n");
	printf("2 . Tim phan tu lon nhat, nho nhat cua mang\n");
	printf("3 . Tim va in ra vi tri duong nho nhat\n");
	printf("4 . Tinh tong cua mang\n");
	printf("5 . Tinh trung binh cong, trung binh nhan mang\n");
	printf("6 . Tim kiem phan tu\n");
	printf("7 . Sap xep mang theo thu tu tang dan, giam dan\n");
	printf("8 . Xuat day dao nguoc\n");
	printf("9 . Them phan tu\n");
	printf("10. Xoa phan tu\n");
	printf("11. Dem so phan tu duong va in ra tong cac phan tu duong cua mang\n");
	printf("12. Kiem tra mang co doi xung hay khong\n");
	printf("13. Kiem tra mang co sap xep theo thu tu tang dan hay khong\n");
	printf("14. Kiem tra trong day co bao nhieu so nguyen to\n");
	printf("15. Kiem tra trong day co bao nhieu so ma so sau bang tong 2 so truoc\n");
	printf("16. Kiem tra trong day co bao nhieu cap ai + aj (i # j) la so nguyen to\n");
	printf("0 . Thoat");
	Menu: do {
		printf("\n\n----------- Nhap lua chon cua ban: ");
		scanf("%d", &luachon);
		switch(luachon) {
			case 1:
				xuatMang(a, n);
				break;
			case 2:
				timphantuMax_Min(a, n);
				break;
			case 3:
				vitriPhanTuDuongMin(a, n);
				break;
			case 4:
				tongcuaMang(a, n);
				break;
			case 5:
				TBC_TBN(a, n);
				break;
			case 6: 
				timkiemphantuX(a, n, x);
				break;
			case 7:
				sapxep(a, n);
				break;
			case 8:
				xuatDaoNguoc(a, n);
				break;
			case 9:
				themXvaoK(a, n, x, k);
				break;
			case 10:
				xoaPhanTuvitriK(a, n, k);
				break;
			case 11:
				DemvaInPhanTuDuong(a, n);
				break;
			case 12:
				kiemtraMangDoiXung(a, n);
				break;
			case 13:
				kiemtraMangtangdan(a, n);
				break;
			case 14:
				kiemtracobaonhieuSNT(a, n);
				break;
			case 15:
				kiemtrasoSaucobangtong_2soTruoc(a, n);
				break;
			case 16:
				kiemtracapso_ai_aj_laSNT(a, n);
				break;
			case 0:
				break;
			default: 
				printf("Ban da nhap sai vui long nhap lai!\n");
				goto Menu;
		}
		printf("\n");
	}while(luachon != 0);
}
