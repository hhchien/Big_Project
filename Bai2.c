#include<stdio.h>
#include<string.h>
#define NMAX 208

typedef struct Object{
  int weight;
  int value;
  int quantity;
  char name[NMAX];
}obj;

void vpw(double *a, obj *b, int n){
  for(int i = 0; i < n; i++){
    *(a+i) = (b+i)->value*1.0/(b+i)->weight;
  }
}

void swap(int *a, int *b){
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void swapobj(obj *a, obj * b){
  swap(&a->weight, &b->weight);
  swap(&a->value, &b->value);
  char tmp[NMAX];
  strcpy(tmp, a->name);
  strcpy(a->name, b->name);
  strcpy(b->name, tmp);
}


void sortobj(double *a, obj *b, int n){
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      if(*(a+j) > *(a+i)){
        double tmp = *(a+i);
        *(a+i) = *(a+j);
        *(a+j) = tmp;
        swapobj(b+i, b+j);
      }
    }
  }
}

int main(){
  obj a[NMAX];
  int n, w, maxv = 0;
  double b[NMAX];
  FILE *read = fopen("bag.inp", "r");
  fscanf(read, "%d %d", &n, &w);
  for(int i = 0; i < n; i++){
    fscanf(read, "%d %d %s", &(a+i)->weight, &(a+i)->value, (a+i)->name);
  }
  vpw(b, a, n);
  sortobj(b, a, n);
  for(int i = 0; i < n; i++){
    a[i].quantity = w/a[i].weight;
    w = w % a[i].weight;
    maxv += a[i].value*a[i].quantity;
  }
  printf("Max value: %d\nList of objects and quantities:\n", maxv);
  for(int i = 0; i < n; i++){
    if(a[i].quantity > 0) printf("%s %d\n", a[i].name, a[i].quantity);
  }
  fclose(read);
  return 0;
}
