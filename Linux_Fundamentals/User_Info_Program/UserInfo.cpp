#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

using namespace std;

int main()
{
    int uid = getuid();

    struct passwd* PW = getpwuid(uid);

    cout << "User Name: " << PW->pw_name << ", User ID: " << getuid() << endl;

    return 0;
}