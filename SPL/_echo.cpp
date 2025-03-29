
 #include <unistd.h>
#include <iostream>
#include <string.h>


int main(int argc, char *argv[]){
int fd ,size = -1;
    for(int i=1; i<argc;i++){
        size = strlen(argv[i]);

        fd = write(1 , argv[i] , size);
        
        if(fd == -1){
            return -1;
        }
        
          
        if (i < argc - 1) {
            if (write(1, " ", 1) == -1) {
                return -1;
            }
        }
        
    }
    fd = write(1 , "\n" , 1);
    return 0;

}
