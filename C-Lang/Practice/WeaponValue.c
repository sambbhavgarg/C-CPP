#include<stdio.h>

void toBinary(int);

int main(){
  int x[3] = {344, 34, 12};
  for(int i=0; i<2; i++){
    x[i+1] = x[i]^x[i+1];
  }
  toBinary(x[2]);
}

void toBinary(int n){
  // int count = 0;
  while (n) {
      if (n & 1)
        printf("1");
        // count++;
      else
        printf("0");
      n >>= 1;
  }
  printf("\n");
}

/*

int main(){
  int n, strings, temp;
  string str;
  scanf("%d%d", &n, &str);
  int x[str];
  for(int i=0; i<strings; i++){
    cin>>str;
    temp = stoi(str, 0, 2);
    cout<<n;
  }
  for(int i=0; i<strings; i++){
    scanf("%d", )
  }
  for(int i=0; i<2; i++){
    x[i+1] = x[i]^x[i+1];
  }
  toBinary(x[2]);
}

void toBinary(int n){
  int count = 0;
  while (n) {
      if (n & 1)
          count++;
      n >>= 1;
  }
  printf("%d\n", count);
}
*/
