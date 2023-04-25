/*
Escreva uma função que reverta (no local) uma string.

Ele deve retornar seu parâmetro.

Sua função deve ser declarada da seguinte forma: char *ft_strrev(char *str);

*/

int ft_strlen(char *str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        i++;
    }
    return(i);
}

char *ft_strrev(char *str)
{
    int i = 0;
    int len;
    char aux;

    while(i <= len/2)
    {
        len = ft_strlen(str);
        aux = str[i];
        str[i] = str[len - 1];
        str[len - 1] = aux;
        i++;
        len--;
    }
    return(str);
}