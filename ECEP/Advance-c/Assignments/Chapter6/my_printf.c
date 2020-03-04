#include <stdio.h>
#include <stdarg.h>

void my_printf(const char *format, ...)
{
	//Declare all the local variables here
	char ch;
	int i;
	float f;
	double d;

	//Declare one local buffer
	char buffer[20] = {'\0'};

	//Declare the pointer of type va_list
	va_list ap;

	//Init the pointer after the format
	va_start(ap, format);

	//Declare the temp pointer
	const char *p = format;

	//Loop till the end of the string
	while (*p)
	{
		if (*p == '%')
		{
			//Check the next character + jump to that case
			switch (*++p)
			{
				case 'c':
					ch = (char)va_arg(ap, int);
					fputc(ch, stdout);
					break;

					//For int data type
				case 'd':
					i = va_arg(ap, int);
					//This function converts int to ascii + storing the ascii in the local buffer
					sprintf(buffer, "%d", i);

					//Print the buffer content to the ouput terminal
					fputs((const char *)buffer, stdout);
					break;

				case 'f':
					f = (float)va_arg(ap, double);
					//This function converts float to ascii + storing the ascii in the local buffer
					sprintf(buffer, "%g", f);

					//Print the buffer content to the ouput terminal
					fputs((const char *)buffer, stdout);
					break;

				case 'l':
					switch (*++p)
					{
						case 'f':
							f = va_arg(ap, double);
							//This function converts float to ascii + storing the ascii in the local buffer
							sprintf(buffer, "%lf", f);

							//Print the buffer content to the ouput terminal
							fputs((const char *)buffer, stdout);
							break;

					}
			}
		}
		//Simply display all the characters to the output terminal
		else
		{
			fputc(*p, stdout);
		}
		//Inc. the pointer
		p++;
	}
}

int main()
{
	char ch = 'A';
	int i = 32;
	float f = 32.54;
	double d = 32.546;

	//Call the my_printf function
	my_printf("The value of ch : %c\n", ch);

	//call the my_printf function to print the int value
	my_printf("The value of i  : %d\n", i);

	//call the my_printf function to print the float value
	my_printf("The value of f : %f\n", f);

	//call the my_printf function to print the double value
	my_printf("The value of d : %lf\n", d);

	return 0;
}
