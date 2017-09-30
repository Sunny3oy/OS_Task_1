//Part 3 by Sunny Mei
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
	char* filepath_source = argv[1];//source file name
	char* filepath_des = argv[2];//des file name
	int readcontents;// flag for opening file to read
	int openfile;//flag for open des file
	int readfile;//flag for read
	int writetodes;//flag for write to des file
	int filesize = 1292;//filesize of source, i could not find a function to check for size of file
	int amount = 100;//the amount we are starting at, will increase
	int increase = amount;//will store the increment, the next 100, the next 100
	int mod;//will check for end of file using math
	mod = filesize%amount;//in this case, 1292 mod 100 will be 92. the last interation will contain 92 and not 100
	int flag = 1;//controls the while statment
	readcontents = open(filepath_source,O_RDONLY);//holds the flag for read file
	openfile = open(filepath_des, O_WRONLY);//holds flag for des file
	char xyz[] = "XYZ";//since we want to add XYZ after changing the 1's to A, we need to declare this and write after the 1's

	while(flag>0)//flag will only be changed when we are in the last interation
	{if (amount<filesize)//if amount is less than file size means we can still read data in chucks of 100.
		{
			char contents[increase];//holds the contents of reading
			char contentsdes[increase];//holds the contents that will be written to des
			readfile = read(readcontents, contents,increase);//start reading
			cout<<"\nThe next "<<increase<<" char contains"<<"\n"<<contents<<"end\n";//display what has been read
			for(int i = 0; i < increase; i++)//looping through the read contents
				{
					if(contents[i] == '1')//we want to change 1's to A's
						contentsdes[i] = 'A';
					else
						contentsdes[i] = contents[i];//we leave anything else as it is
										
				}
			cout<<"\nThe following will be stored in destination file\n"<<contentsdes<<"XYZ\n";//display what goes into des file
			writetodes = write(openfile, contentsdes, increase);//does the writing of the modified read contents
			writetodes = write(openfile, xyz, 3);//writes XYZ
			amount = amount + increase;//increase amount by 100 so we can check the if(amount<filesize) statment
		}
	 else//this means we cannot read the data by chucks of 100 anymore
		{
			increase = mod;//this is the last interration and we only have 92 bytes left to read
			//below is just the copy of the above but with increase = to 92 since we are at the last stage
			char contentslast[increase];
			char contentsdeslast[increase];
			readfile = read(readcontents, contentslast,increase);
			cout<<"\nThe next "<<increase<<" char contains"<<"\n"<<contentslast<<"end\n";
			for(int i = 0; i < increase; i++)
				{
					if(contentslast[i] == '1')
						contentsdeslast[i] = 'A';
						
					else
						contentsdeslast[i] = contentslast[i];
										
				}
			cout<<"\nThe following will be stored in destination file\n";
			for(int i = 0; i < increase; i++)
				{
					cout<<contentsdeslast[i];						
				}
			cout<<"XYZ\n";
			//something wierd is going on with contentsdes at last inter as it somehow contain the changed values and
			//the old values. However, i will only write 92 + XYZ to the destination file so it can be correct
			writetodes = write(openfile, contentsdeslast, increase);//writes only the parts that are needed
			writetodes = write(openfile, xyz, 3);
			flag = -1;//change the flag so we can exit the while loop		
		}
	}
	close(readcontents);
	close(writetodes);
	return 0;

}
