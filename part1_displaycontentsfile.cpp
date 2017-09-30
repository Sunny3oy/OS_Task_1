//part 1 by Sunny Mei
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>
using namespace std;

int main (int argc, char* argv[])
{
	
	char* filepath = argv[1];
	int readcontents, checkex, fd;// int vairables that holds flags
	int readfile;
	checkex = access (filepath, F_OK);//check for file exsistance
	fd = open(argv[1],O_RDONLY);//check if we can open the file
	if (checkex == 0)
	{cout<<"\nThis file has been found\n";
		if(fd == -1)
		{
		cout<<"\nOpen system call failled\n";
		return 1;
		}
		else
		{
		readcontents = open(filepath,O_RDWR);
		char contents[1080];
		readfile = read(readcontents, contents,1080);
		cout<<"This file contains"<<"\n"<<contents<<"\n";
		close(fd);
		return 0;				
		}
	}
	else
	{
	cout<<"\nFile not found\n";
	return 1;
	}			

}
