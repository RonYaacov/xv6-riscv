#include "user.h"


int
calc_sum(int i, int j){
  int sum = 0;
  for (int k = i; k < j; k++) {
    sum += k;
  }
  return sum;
}

int calc_total_sum(int *array, int n){
  int sum = 0;
  for (int i = 1; i < n+1; i++) {
    sum += array[i];
  }
  return sum;
}

int main(){
    int n = 8;
    int pids[n];

    int forkn_status_code = forkn(n, pids);
    if (forkn_status_code < 0){
        printf("forkn failed\n");
        return -1;
    }
    for(int i = 0; i < n; i++){
        if (pids[i] == 0){
            int part_sum = calc_sum(i*(1 << 16)/n, (i+1)*(1 << 16)/n); 
            exit(part_sum, "exit");
        }
    }
    
    
    int array[1] = {0};
    int status[64] = {0};
    waitall(array, status);
    for(int i = 0; i<n; i++){
        printf("child %d clculated %d\n", pids[i], status[i+1]);
    }
    int total_sum = calc_total_sum(status, n);
    printf("process done: %d\n", array[0]);
    printf("total sum: %d\n", total_sum);
    return 0;
}