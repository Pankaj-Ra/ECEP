						//mp3_tag.c.....reads the tags of mp3 file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t get_tag_size(FILE *fp);
unsigned int get_frame_size(FILE *fp);
void get_frame_info(FILE *fp, int size, char *str);
void get_image(FILE *fp, int size, char *image);

int main(int argc, char *argv[])
{
    //Declaration of required variables
    FILE *fp, *fd;
    char tag_id[3], frame_id[4];
    int i, j;
    size_t tag_size;
    unsigned char ch;
    unsigned int frame_size;

    //Checking for command line ardument
    if(argc < 2)
    {
    	printf("Please Enter the mp3 file path\n");
    	return -1;
    }

    //opening the file in read mode
    fp = fopen(argv[1], "rb");

    //Error checking
    if(fp == NULL)
    {
    	printf("fopen : Failed\n");
    	return -1;
    }

    printf("\e[1;33m%s\e[0m\n", argv[1]);
    printf("\e[1;34m----------------------\e[0m\n");

    //geting tag id
    tag_id[3] = '\0';
    fread(tag_id, sizeof(char), 3, fp);
    printf("       \e[1;32mTag\e[0m\e[1;34m :\e[0m  \e[1;33m%sv\e[0m", tag_id);

    fread(&ch, sizeof(char), 1, fp);
    printf("\e[1;33m%c\e[0m", ch + 48);
    fread(&ch, sizeof(char), 1, fp);
    printf("\e[1;33m.%c\e[0m\n", ch + 48);

    //getting the tag size
    fseek(fp, 6, SEEK_SET);
    tag_size = get_tag_size(fp);  
//    printf("size: %lu", tag_size);

    //Getting the header file of the mp3 file
    fseek(fp, 10, SEEK_SET);
    fd = fopen("dest.txt", "wb");
    while(tag_size--)
    {
    	if(fread(&ch, sizeof(char), 1, fp))
	{
	    fwrite(&ch, sizeof(char), 1, fd);
	}
    }
    fclose(fp);
    fclose(fd);

    //Reading the header file
    fp = fopen("dest.txt", "rb");

    //Error check
    if(fp == NULL)
    {
    	printf("fopen : Failed\n");
    	return -1;
    }

    //geting the frame id and frame information
    frame_id[4] = '\0';
    while(fread(&ch, sizeof(char), 1, fp))
    {
    	fseek(fp, -1, SEEK_CUR);
    	fread(frame_id, sizeof(char), 4, fp);
    	if(!strcmp(frame_id, "TPE1"))
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 2, SEEK_CUR);
	    get_frame_info(fp, frame_size, "Artist");
	}
	
	else if(!strcmp(frame_id, "TIT2"))
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 2, SEEK_CUR);
	    get_frame_info(fp, frame_size, "Song Name");
	}
	else if(!strcmp(frame_id, "TALB"))
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 2, SEEK_CUR);
	    get_frame_info(fp, frame_size, "Album");
	}
	else if(!strcmp(frame_id, "TCON"))
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 2, SEEK_CUR);
	    get_frame_info(fp, frame_size, "Genere");
	}
	else if(!strcmp(frame_id, "TYER"))
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 2, SEEK_CUR);
	    get_frame_info(fp, frame_size, "Year");
	}
	else if(!strcmp(frame_id, "TRAC"))
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 2, SEEK_CUR);
	    get_frame_info(fp, frame_size, "Track");
	}
	else if(!strcmp(frame_id, "TBPM"))
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 2, SEEK_CUR);
	    get_frame_info(fp, frame_size, "Info");
	}
	else if(!strcmp(frame_id, "TPUB"))
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 2, SEEK_CUR);
	    get_frame_info(fp, frame_size, "Publisher");
	}
	else if(!strcmp(frame_id, "TRCK"))
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 2, SEEK_CUR);
	    get_frame_info(fp, frame_size, "Track");
	}
	else if(!strcmp(frame_id, "APIC"))
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 3, SEEK_CUR);
	    get_image(fp, frame_size, "Image");
	}
	
	else
	{
	    frame_size = get_frame_size(fp);
	    fseek(fp, 2 + frame_size, SEEK_CUR);
	}
    }

    return 0;
}

size_t get_tag_size(FILE *fp)
{
    int i = 4;
    char ch;
    size_t size = 0;
    while(i--)
    {
    	size <<= 7;
    	if(fread(&ch, sizeof(char), 1, fp))
	{
	    size |= ch;
	}
    }
    return size;
}
unsigned int get_frame_size(FILE *fp)
{
    int i = 4;
    size_t size = 0;
    unsigned char ch;
    while(i--)
    {
    	size <<= 8;
    	if(fread(&ch, sizeof(char), 1, fp))
	{
	    size |= ch;
	}
    }

    return size;
}

void get_frame_info(FILE *fp, int size, char *str)
{
    unsigned char ch;
    printf("\e[1;32m%10s\e[0m \e[1;34m:\e[0m  ", str);
    while(size--)
    {
    	if(fread(&ch, sizeof(char), 1, fp))
	{
	    printf("\e[0;31m%c\e[0m", ch);
	}
    }
    printf("\n");
}

void get_image(FILE *fp, int size, char *image)
{
	FILE *img;
	unsigned ch;

	img = fopen("Tag_img.jpeg", "wb");

	if (img == NULL)
	{
		printf("img: Failed to open jpeg file\n");
	}
	printf("\e[1;32m%10s\e[0m \e[1;34m:\e[0m  ", image);
        printf("\e[0;31m./Tag_img.jpeg\e[0m\n");

	while (fgetc(fp));
	while (fgetc(fp));

	while (size--)
	{
		fread(&ch, sizeof(char), 1, fp);
		fwrite(&ch, sizeof(char), 1, img);
	}
}


