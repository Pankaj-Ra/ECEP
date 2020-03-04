/***************************************************************************************************************************************************
*Title      : Stegnography 
*Author     : Pankaj Rangta
*Date       : 06/07/2015
*Description: Stegnography is a process of encoding information in a image file in such a way that naked eyes can't distinguish between original and encoded image.
              In this program we are using LSB bit encoding technique to store info in LSB bits of image file.
****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function use to encode information in image
void encoding(char *info, char *s_image, char *e_image)
{
	//Declare all image, file pointers and required variables
	FILE *f_img, *e_info, *e_img;
	char e_pass[4];
	unsigned char ch;
	char msg;
	int i, j, width, height;
	long int img_size, size_info_passed;
	unsigned int info_size, mask;

        //Open image file in read mode
	f_img = fopen(s_image, "rb");
	printf("\n\e[1;34m---------------------------------------------------------\e[0m\n");
 
        //Error condition
	if (f_img == NULL)
	{
		printf("f_img: Failed to open image\n");
		exit (0);
	}
 
        //Open/Create file in write mode 
	e_img = fopen(e_image, "wb");

        //Error condition
	if (e_img == NULL)
	{
		printf("e_img: Failed to open image\n");
		exit (0);
	}

        //Open information file in read mode
	e_info = fopen(info, "rb");

        //Error condition
	if (e_info == NULL)
	{
		printf("e_info: Failed to open file\n");
		exit (0);
	}

        //Get password from the user
	printf("\n\e[1;33mEnter a 4 character long  password\e[0m\n");
	scanf("%[^\n]%*c", &e_pass);

        //Findout image size using fseek
	fseek(f_img, 0, SEEK_END);
	img_size = ftell(f_img);
	printf("\n\e[1;32mSize of image:\e[0m \e[1;33m%li bytes\e[0m\n", img_size);

        //Findout information size
	fseek(e_info, 0, SEEK_END);
	info_size = ftell(e_info);
	printf("\e[1;32mSize of info :\e[0m \e[1;33m%d bytes\e[0m\n", info_size);

        //Findout pixel ratio of image store after 18th  position 
	fseek(f_img, 18, SEEK_SET);
	fread(&width, 4, 1, f_img);
	fread(&height, 4, 1, f_img);

	printf("\e[1;32mPixel Ratio  :\e[0m \e[1;33m%d x %d\e[0m\n", width, height);

        //Reset all file pointers to starting position
	fseek(f_img, 0, SEEK_SET);
	fseek(e_img, 0, SEEK_SET);
	fseek(e_info, 0, SEEK_SET);

        //Calculate size of total information need to store in LSB bits of image file
	size_info_passed = 54 + (strlen(e_pass) * 8) + sizeof(info_size) * 8 + (info_size * 8);
	printf("\e[1;32mSize of info passed:\e[0m \e[1;33m%d bytes\e[0m\n", size_info_passed);

        //Exit if size of info need to pass is more than size of image
	if(size_info_passed > img_size)
	{
		printf("Size of information is more than the size of image used\n");
		exit (0);
	}

        //Copy header file of image as it is
	for (i = 0; i < 55; i++)
	{
		fread(&ch, sizeof(char), 1, f_img);
		fwrite(&ch, sizeof(char), 1, e_img);
	}

        //Encode password in first 32 LSB bits of image after header
	for (i = 0; i < 4; i++)
	{
		for (j = 7; j >= 0; j--)
		{
			mask = 1 & (e_pass[i] >> j);
			fread(&ch, sizeof(char), 1, f_img);
			ch &= 254;
			ch += mask;
			fwrite(&ch, sizeof(char), 1, e_img);
		}
	}

        //Encode size of information file in image
	for (j = 31; j >= 0; j--)
	{
		mask = 1 & (info_size >> j);
		fread(&ch, sizeof(char), 1, f_img);
		ch &= 254;
		ch += mask;
		fwrite(&ch, sizeof(char), 1, e_img);
	}

        //Encode all information file in remaining bits of image
	while (fread(&msg, sizeof(char), 1, e_info))
	{
		for (j = 7; j >= 0; j--)
		{
			mask = 1 & (msg >> j);
			fread(&ch, sizeof(char), 1, f_img);
			ch &= 254;
			ch += mask;
			fwrite(&ch, sizeof(char), 1, e_img);
		}
	}
 
        //Copy the rest part of image as it is
	while (fread(&ch, sizeof(char), 1, f_img))
	{
		fwrite(&ch, sizeof(char), 1, e_img);
	}

	printf("\e[1;32mInformation is encoded successfully in file:\e[0m \e[1;33m%s\e[0m\n\n", e_image);
	printf("\e[1;34m---------------------------------------------------------\e[0m\n\n");

	//Close all files
	fclose(f_img);
	fclose(e_img);
	fclose(e_info);
}

//Function is use to decode information from the incoded image
void decoding(char *e_image, char *info)
{
	//Declare file pointers, strings and required variables of following data type
	FILE *e_img, *d_info;
	char  r_pass[4], d_pass[4];
	unsigned char ch;
	char msg;
	int i, j;
	unsigned int mask, info_size, pass;

        //Open encoded image in read binary mode
	e_img = fopen(e_image, "rb");
        
	printf("\n\e[1;34m---------------------------------------------------------\e[0m\n");
        //Error condition
	if (e_img == NULL)
	{
		printf("e_img: Failed to open image\n");
		exit (0);
	}

        //Open/create file to store decoded info in write binary mode
	d_info = fopen(info, "wb");

        //Error condition
	if (d_info == NULL)
	{
		printf("d_info: Failed to open file\n");
		exit (0);
	}

        //Get password from user to decode info
	printf("\n\e[1;33mEnter the password\e[0m\n");
	scanf("%[^\n]%*c", &r_pass);

        //Decode password from the image starting from 55th position and store in string d_pass
	fseek(e_img, 55, SEEK_SET);
	for (i = 0; i < 4; i++)
	{
		pass = 0;
		for (j = 7; j >= 0; j--)
		{
			fread(&ch, sizeof(char), 1, e_img);
			pass <<= 1;
			mask = 1 & ch;
			pass |= mask;
		}
		d_pass[i] = pass;
	}
	d_pass[i] = '\0';

        //If password doesn't match, print error condition and exit
	if (strcmp(r_pass, d_pass))
	{
		printf("\nWrong Password\n\n");
		exit (0);
	}

        //Decode size of information file
	pass = 0;
	for (j = 0; j < 32; j++)
	{
		fread(&ch, sizeof(char), 1, e_img);
		pass <<= 1;
		mask = 1 & ch;
		pass |= mask;
	}
	info_size = pass;

        //Decode information form image
	for (i = 0; i < info_size; i++)
	{
		pass = 0;
		for (j = 7; j >= 0; j--)
		{
			fread(&ch, sizeof(char), 1, e_img);
			pass <<= 1;
			mask = 1 & ch;
			pass |= mask;
		}
		fwrite(&pass, sizeof(char), 1, d_info);
	}
	printf("\n\e[1;32mInformation is Decoded successfully in file:\e[0m \e[1;33m%s\e[0m\n\n", info);
	printf("\e[1;34m---------------------------------------------------------\e[0m\n\n");

	//Close all files
	fclose(e_img);
	fclose(d_info);
}

int main(int argc, char *argv[])
{
	//Using switch case to identify the number of arguments passed by user and call the respective function
	switch (argc)
	{
		case 5:
		        //if first argument passed by user is "-e" call encoding func()
			if (!strcmp(argv[1], "-e"))
			{
				encoding(argv[2], argv[3], argv[4]);
				break;
			}
		case 4:
		        //if first argument passed by user is "-d" call decoding func()
			if (!strcmp(argv[1], "-d"))
			{
				decoding(argv[2], argv[3]);
				break;
			}
		default :
		        //print default condition if arguments passed by user are not enough
			printf("Not enough argument passed\n");
	}

	return 0;
}
