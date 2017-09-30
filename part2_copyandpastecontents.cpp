//Part 2 by Sunny Mei
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
	//assuming both source and destination files exsist
	char* filepath_source = argv[1];
	int readcontents;// int vairables that holds flags
	int readfile;
	readcontents = open(filepath_source,O_RDONLY);
	char contents[1292];
	readfile = read(readcontents, contents,1292);
	cout<<"The source file contains"<<"\n"<<contents<<"\n";
	close(readcontents);
	//above is the same as in part 2
	
	char* filepath_des = argv[2];//des file name
	int openfile;//flag for open des file
	int writetodes;//flag for write to des file
	int readdes;
	char contentsdes[1292];
	openfile = open(filepath_des, O_WRONLY);//holds flag for des file
	writetodes = write(openfile, contents, 1292);//does the writing stored in contents to des file
	close(openfile);
	openfile = open(filepath_des, O_RDONLY);	
	readdes = read(openfile, contentsdes, 1292);//reads from the des file to make sure the contents are there
	cout<<"The destination file contains"<<"\n"<<contentsdes<<"\n";
	close(openfile);	
	return 0;

}
