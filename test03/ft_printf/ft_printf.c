#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void putstr(char *str, int *size)
{
	if(!str)
		str = "(null)";
	while(*str)
	{
		write(1,str, 1);
		str++;
		*size = *size + 1;
	}
}

void putnbr(long long int str, int bite, int *size)
{
	char *c="0123456789abcdef";

	if(str < 0)
	{
		write(1, "-",1);
		str = str*-1;
		*size = *size + 1;
	}
	if (str >= bite)
		putnbr(str / bite, bite, size);
	write(1,&c[str%bite], 1);
	*size = *size + 1;
}



int ft_printf(const char*format, ...)
{
	int size = 0;
	va_list form;

	va_start(form, format);
	while(*format)
	{
		if(*format == '%' && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if(*format == 's')
				putstr(va_arg(form, char *), &size);
			else if(*format == 'd')
				putnbr((long long int)va_arg(form,int), 10,&size);
			else if(*format == 'x')
				putnbr((long long int)va_arg(form, unsigned int), 16,&size);
		}	
		else
		{
			write(1,format, 1);
			size++;
		}
		format++;
	}
	va_end(form);
	return(size);
}

int main()
{
	int i = 0;
	i = ft_printf("%d\n", 10);

	printf("%d\n", i);
	int j = 0;
	j = printf("%s\n", "toto");
	printf("%d\n", j);
}