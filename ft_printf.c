#include <stdarg.h>
#include <unistd.h>

void    ft_putstr(char *str)
{
    if(!str)
        str = "(null)";
    while(*str)
    {
        *i = write(1, str++, 1);
    }
}

void    ft_putnbr(long long int num, int base, int *i)
{
    if(num < 0)
    {
        num *= -1;
        *i = write(1, "-", 1);
    }
    if(num >= base)
        ft_putnbr((num / base), base , i);
    *i += write(1, &"0123456789abcdef"[num % base], 1);
}

int ft_printf(const char *str, ...)
{
    int i = 0;
    va_list arg;
    va_start(arg, str);

    while(*str)
    {
        if(*str == '%' && (str + 1))
        {
            str++;
            
        }
    }
}