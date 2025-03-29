#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>

void copyFile(const char* source, const char* destination) {
    int src_fd = open(source, O_RDONLY);
    if (src_fd == -1) {
        std::cerr << "Error: Unable to open source file " << source << "\n";
        return;
    }
    
    int dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        std::cerr << "Error: Unable to create destination file " << destination << "\n";
        close(src_fd);
        return;
    }
    
    char buffer[4096];
    ssize_t bytesRead;
    while ((bytesRead = read(src_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dest_fd, buffer, bytesRead) != bytesRead) {
            std::cerr << "Error: Failed to write to " << destination << "\n";
            close(src_fd);
            close(dest_fd);
            return;
        }
    }
    
    if (bytesRead == -1) {
        std::cerr << "Error: Failed to read from " << source << "\n";
    }
    
    close(src_fd);
    close(dest_fd);
    std::cout << "Copied " << source << " to " << destination << "\n";
}

int main(int argc, char *argv[]) {
    // Write your code here
    // Do not write a main() function. Instead, deal with cp_main() as the main function of your program.
    
if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }
    
    struct stat stat_buf;
    if (stat(argv[1], &stat_buf) == -1) {
        perror("Error: Source file does not exist");
        return 1;
    }
    
    copyFile(argv[1], argv[2]);
    return 0;
}
