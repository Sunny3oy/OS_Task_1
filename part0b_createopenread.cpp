//part0b by Sunny Mei
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char* argv[])
{
	int createfile;//Will handle the file we need to create
	char* filepath = argv[1];
	int checkex;//Will check if file existence 
	// Check file existence
	checkex = access (filepath, F_OK);//Bitwise OR flag

	if (checkex == 0)
		printf ("\n %s exists, no need to make a new one\n", filepath);
	else
	{
		createfile = open(filepath,O_RDWR|O_CREAT);//File not found, will make a new file. Enables read and write
		printf ("\n %s does not exists, need to make one\n", filepath);
	}
	return 0;
}

