#include <unistd.h>
#include <iostream>

int main(){



	char* path = get_current_dir_name();

	if(path == NULL)
		std::cout << "ERROR !\n";

	else {
		std::cout << path << std::endl;

		return 0;
	}
}
