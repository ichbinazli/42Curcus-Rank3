#include <stdarg.h> //va_arg, va_list, va_start, va_end
#include <unistd.h> //write

void ft_putstr(char *str, int *i)
{
    if(!str)
        str = "(null)";
    while(*str)
        *i += write(1, str++, 1); //i yazılan karakter sayısını takip etmek için
}

void    ft_putnbr(long long int num, int base, int *i)
{
    if(num < 0)
    {
        num *= -1;
        *i += write(1, "-", 1);
    }
    if(num >= base) //belirtilen tabanda yazmak için (10, 16)
        ft_putnbr((num / base), base, i); //sayımız belirtilen tabandan büyük eşitse o tabana bölünüp recursive yapılır
    *i += write(1, &"0123456789abcdef"[num % base], 1); //16lık taban ise
}


int ft_printf(const char *str, ... )
{
    int i = 0; //retun değerimiz
    va_list arg;
    va_start(arg, str);

    while(*str)
    {
        if(*str == '%' && *(str + 1))
        {
            str++;
            if(*str == 's')
                ft_putstr(va_arg(arg, char *), &i);
            else if(*str == 'd')
                ft_putnbr((long long int)va_arg(arg, int), 10, &i);
            else if(*str == 'x')
                ft_putnbr((long long int)va_arg(arg, unsigned int), 16, &i);
        }
        else
            i += write(1, str, 1);
        str++;
    }
    va_end(arg);
    return(i);
}

/*#include <stdio.h>
int main()
{
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    printf("Hexadecimal for %d is %x\n", 42, 42);
    ft_printf("%s\n", "toto");
    printf("%s\n", "toto");
    ft_printf("%s\n", NULL);
}*/
