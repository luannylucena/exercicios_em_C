int max(int *tab, unsigned int len)
{
    unsigned int i = 0;
    unsigned int result;

    result = tab[i]; // atribui o valor do primeiro elemento do array "tab" à variável "result"
    while(i < len)
    {
        if(result < tab[i])
        {
            result = tab[i];
        }
        i++;
    }
    return(result);
}