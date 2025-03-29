#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

void moveFile(const char* source, const char* destination) {
    if (rename(source, destination) == 0) {
        printf("Moved %s to %s\n", source, destination);
        return;
    }
    
    perror("Error: Unable to move file using rename, falling back to copy and delete");
    
    int src_fd = open(source, O_RDONLY);
    if (src_fd == -1) {
        perror("Error: Unable to open source file");
        return;
    }
    
    int dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error: Unable to create destination file");
        close(src_fd);
        return;
    }
    
    char buffer[4096];
    ssize_t bytesRead;
    while ((bytesRead = read(src_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dest_fd, buffer, bytesRead) != bytesRead) {
            perror("Error: Failed to write to destination file");
            close(src_fd);
            close(dest_fd);
            return;
        }
    }
    
    if (bytesRead == -1) {
        perror("Error: Failed to read from source file");
    }
    
    close(src_fd);
    close(dest_fd);
    
    if (unlink(source) == -1) {
        perror("Error: Failed to delete source file after copying");
        return;
    }
    
    printf("Moved %s to %s\n", source, destination);
}


int main(int argc, char *argv[]) {
    // Write your code here
    // Do not write a main() function. Instead, deal with mv_main() as the main function of your program.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }
    
    struct stat stat_buf;
    if (stat(argv[1], &stat_buf) == -1) {
        perror("Error: Source file does not exist");
        return 1;
    }
    
    moveFile(argv[1], argv[2]);
    return 0;
    
}
