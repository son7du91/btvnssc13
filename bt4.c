#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int n = 0; 
void nhapMang(int arr[]);
void inMang(int arr[]);
void themPhanTu(int arr[], int value, int position);
void suaPhanTu(int arr[], int value, int position);
void xoaPhanTu(int arr[], int position);
void sapXepMang(int arr[], int order);
int timKiemTuyenTinh(int arr[], int value);
int timKiemNhiPhan(int arr[], int value);
int main() {
    int arr[MAX_SIZE];
    int choice, position, value, order;
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                nhapMang(arr);
                break;
            case 2:
                inMang(arr);
                break;
            case 3:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them (0 to %d): ", n);
                scanf("%d", &position);
                themPhanTu(arr, value, position);
                break;
            case 4:
                printf("Nhap vi tri can sua (0 to %d): ", n - 1);
                scanf("%d", &position);
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                suaPhanTu(arr, value, position);
                break;
            case 5:
                printf("Nhap vi tri can xoa (0 to %d): ", n - 1);
                scanf("%d", &position);
                xoaPhanTu(arr, position);
                break;
            case 6:
                printf("Lua chon sap xep:\n1. Giam dan\n2. Tang dan\n");
                scanf("%d", &order);
                sapXepMang(arr, order);
                break;
            case 7:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                printf("Lua chon: 1. Tim kiem tuyen tinh 2. Tim kiem nhi phan: ");
                int searchChoice;
                scanf("%d", &searchChoice);
                if (searchChoice == 1) {
                    int index = timKiemTuyenTinh(arr, value);
                    if (index != -1) {
                        printf("Tim thay gia tri %d o vi tri %d\n", value, index);
                    } else {
                        printf("Khong tim thay gia tri %d\n", value);
                    }
                } else if (searchChoice == 2) {
                    int index = timKiemNhiPhan(arr, value);
                    if (index != -1) {
                        printf("Tim thay gia tri %d o vi tri %d\n", value, index);
                    } else {
                        printf("Khong tim thay gia tri %d\n", value);
                    }
                }
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }
    return 0;
}
void nhapMang(int arr[]) {
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
void inMang(int arr[]) {
    printf("Gia tri cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void themPhanTu(int arr[], int value, int position) {
    if (n >= MAX_SIZE) {
        printf("Mang da day, khong the them phan tu.\n");
        return;
    }
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    n++;
}
void suaPhanTu(int arr[], int value, int position) {
    if (position >= 0 && position < n) {
        arr[position] = value;
    } else {
        printf("Vi tri khong hop le.\n");
    }
}
void xoaPhanTu(int arr[], int position) {
    if (position >= 0 && position < n) {
        for (int i = position; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    } else {
        printf("Vi tri khong hop le.\n");
    }
}
void sapXepMang(int arr[], int order) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((order == 1 && arr[i] < arr[j]) || (order == 2 && arr[i] > arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang sau khi sap xep:\n");
    inMang(arr);
}
int timKiemTuyenTinh(int arr[], int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
int timKiemNhiPhan(int arr[], int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}