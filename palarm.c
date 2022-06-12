#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdbool.h>

char arr1[] = { 'H', 'O', 'L', 'A'};
int i = 1;
bool x = true;

void sig_add(int signum){
  arr1[0] = ' ';
  arr1[1] = 'B';
  arr1[2] = 'Y';
  arr1[3] = 'E';


  printf("\nSe detecta senal, cambiando valor a %s\n",arr1);
}

void sig_res(int signum){
  arr1[0] = 'H';
  arr1[1] = 'O';
  arr1[2] = 'L';
  arr1[3] = 'A';
  printf("\nSe detecta senal, cambiando valor a %s\n",arr1);
}

void sig_end(int signum){
  i = 2;
  printf("\nSe detecta senal de cierre, termina loop y proceso\n");
}

void sig_alarm(int signum){
  x = !x;
  //printf(x ? "\ntrue" : "\nfalse");
  
}

int main(){
  //Manejador de señal - 10
  signal(SIGUSR1,sig_add);
  //Manejador de señal - 14
  signal(SIGALRM,sig_alarm);
  //Manejador de señal - 12
  signal(SIGUSR2,sig_res); 
  //Manejador de señal
  signal(SIGINT,sig_end); 

  alarm(1);

  alarm(3);

  alarm(5);

  alarm(7);
  
  //Esperando señal
  while(i == 1)
  {    
    printf(x ? "\ntrue" : "\nfalse");
    //impresión de información de la señal
    printf("\tEsperando senal ALARM o SIGUSR1. o SIGUSR2. Valor actual. %s\n",arr1);
    //Retraso de 1s
    sleep(1);
  }
  return 0;
  
}