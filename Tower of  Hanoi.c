#include <stdio.h>
#include <stdlib.hT
    if(n==1){
        printf("\nMove from %c to %c",source,dest);
    }
    else{
        towerofhanoi(n-1,source,spare,dest);
        towerofhanoi(1,source,dest,spare);
        towerofhanoi(n-1,spare,dest,source);
    }

}


int main()
{
    int n = 3;
    towerofhanoi(n,'A','C','B');
    return 0;
}
