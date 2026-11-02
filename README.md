# DSA_N06

# Bai tap chuong 1:

# Bai 1: Ve so do khoi thuat toan giai pt ax2 + bx + c = 0

# Bai 2: Ve so do khoi giai thuat kiem tra 1 so nguyen duong co phai la so nguyen to khong? Danh gia do phuc tap cua giai thuat su dung

# Bai 3: Ve so do khoi giai thuat tim so lon nhat trong mang n so nguyen. Danh gia thuat toan su dung

# Bai 4: Ve so do khoi giai thuat tim boi so chung nho nhat cua 2 so nguyen duong. Danh gia thuat toan su dung

# Bai 5: Kiem tra N nguyen to hay khong?

# Bai 6: Ve so do khoi doan chuong trinh sau. Cho biet ket qua thuc hien chuong trinh voi: N=28; N=20; N=-9; N=6
int ktra(int N){
	if(N <= 0) return 0;
	int S = 0;
	for(int i = 1; i <= N/2; i++)
		if(N % i == 0)
			S += i;
	if(S == N) return 1;
	return 0;
}
