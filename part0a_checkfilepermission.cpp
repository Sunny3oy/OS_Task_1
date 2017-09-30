//part 0a by Sunny Mei
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char* argv[])
{
	char* filepath = argv[1];
	int returnval, checkread, checkwrite; 
	//define a new int variables that will store the value to check for read/write access
	// Check file existence
	returnval = access (filepath, F_OK);

	if (returnval == 0)
		printf ("\n %s exists\n", filepath);
	else
	{
		if (errno == ENOENT)
			printf ("%s does not exist\n", filepath);
		else if (errno == EACCES)
			printf ("%s is not accessible\n", filepath);
		return 0;
	} 

// Check read access
	
	checkread = access(filepath,R_OK);//using the same method to check for file exsistance, we use R_OK to check for read permission
	if(checkread == 0)//if 0, we can read the file
		printf("\n Read permission is allowed for %s \n", filepath);
	else
	{
		printf("\n Read permission is banned for %s \n", filepath);
	}

		
// Check write access
	checkwrite = access(filepath,W_OK);//using the same method above, we use W_OK to check for write permission
	if(checkwrite == 0)//if 0, we can write the file
	   printf("\n %s can be written\n", filepath);
	else
	{
		printf("\n No good! Can't write\n");
	}
	
return 0;
}
