#include <stdio.h>

int obebBul(int nums[], int boyut);
int obeb(int num1, int num2);
int okekBul(int nums[], int boyut);
int okek(int num1, int num2);

int main(){
	
    int n;
    int boyut;
    
    printf("Kac sayi gireceksiniz?: ");
    scanf("%d", &boyut);
    int nums[boyut];
    
    for(int i = 0; i < boyut; i++){
        printf("\nSayi girin:\n");
        scanf("%d", &n);
        nums[i] = n; //Filling the num array
    }
    
    int obeb = obebBul(nums, boyut);
    printf("\nOBEB: %d", obeb);
    
    int okek = okekBul(nums, boyut);
    printf(" OKEK: %d", okek);
    
    return 0;
}

int obebBul(int nums[], int boyut){
    int result = 0;
    for(int i = 0; i < boyut; i++){
        result = obeb(result, nums[i]);
        if(result == 1) return 1;
    }
    return result;
}

int obeb(int num1, int num2){
    if(num2 == 0) return num1;
    return obeb(num2, (num1 % num2));
}

int okek(int num1, int num2){
    return num1 * num2 / obeb(num1, num2);
}

int okekBul(int nums[], int boyut){
    int result = nums[0];
    for(int i = 1; i < boyut; i++){
        result = okek(result, nums[i]);
        if(result == 1) return 1;
    }
    return result;
}
