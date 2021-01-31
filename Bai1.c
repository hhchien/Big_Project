#include<stdio.h>

unsigned long long giaithua(int n){

    unsigned long long tich = 1;

    for(int i=1;i<=n;i++){
        tich = tich * i;
    }
    return tich;
}

unsigned long long tohop(int n, int k){
    return giaithua(n) / (giaithua(k)*giaithua (n-k));
}

int main(){
    int count =0;
    FILE *fptr1, *fptr2;

    int n,k;

    char line[80];

    fptr1 = fopen("TOHOP.INP", "r");

    while(fgets(line,80,fptr1) != NULL){
        count ++;
    }
    fclose(fptr1);

    fptr1 = fopen("TOHOP.INP", "r");
    fptr2 = fopen("TOHOP.OUT", "w");

    for(int i=0;i<count;i++){
        fscanf(fptr1,"%d %d",&n,&k);
        fprintf(fptr2,"%d\n",tohop(n,k));
    }

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}
