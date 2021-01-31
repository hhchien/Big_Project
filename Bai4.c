#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i,j,n,count;
    srand(time(NULL));
    char number[13][3] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    char type[4][5] = {"Ro","Co","Bich","Tep"};

    bool c[13][4];
    bool hand[13][4];

    for(i=0;i<13;i++){
        for(j=0;j<4;j++){
            c[i][j] = false;
            hand[i][j] = false;
        }
    }

    for(n=0;n<4;n++){
        printf("Nhung la bai tren tay nguoi %d la:\n",n+1);

        for(count =0;count<13;count ++ ){
        int x = rand() % 52;

        if(c[x/4][x%4] == false){
            c[x/4][x%4] == true;
            hand[x/4][x%4] == true;
        } else {
            if(x == 51){
                x = 0;
            } else {
                x++;
            }
                c[x/4][x%4]=true;
                hand[x/4][x%4]=true;
            }
        printf("%s %s\n", number[x/4], type[x%4]);
        }
    //kiem tra tu quy

        for (int x=0;x<52;x=x+4)
            if (hand[x/4][x%4]==hand[x/4][x%4 +1]&&hand[x/4][x%4 +1]==hand[x/4][x%4 + 2]&&hand[x/4][x%4 + 2]==hand[x/4][x%4+3]&&hand[x/4][x%4+3]==true)
                printf("Nguoi choi %d co tu quy %s\n", n+1, number[x/4]);
    //reset bool hand//
        for (i=0;i<13;i++)
            for (j=0;j<4;j++)
                hand[i][j] = false;
    }
    return 0;
}
