/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

#include <stdlib.h>
#include <stdio.h>
/*********************** ITOA (int to char) ********************/

// Primeiro de tudo, preciso saber a qte de dígitos que a palavra tem.
// Só consigo contar numeros de trás pra frente por conta dos operadores (+-*/%).
// Sempre que divido por 10 eu to tirando 1 dígito, e é de trás pra frente. Assim é a maneira que vou contar qtos núemros tenho.

char *ft_itoa(int nbr)
{
    int i = 0;
    long cpy_number = nbr; // vai guardar uma cópia do número para que eu mexa com ela. 
    char *str; // a string que vai ser criada

    //aqui é enquanto for diferente de zero, pois qdo a divisão for zero, acabou os numeros.
    do //dessa forma ele sempre emtra no while. para entrar qdo for zero, pois se não perco um dígito.
    {
        nbr = nbr/10; 
        i++; //aqui dou mais ++ pq estou contando.. dividi por 10, tenho 1 número, então somo. Depois de novo, tenho 2 núemros e assim vai.. 
    } while(nbr != 0);

    if(cpy_number < 0) // para tratar sinal de menos. 
        i++; // para ter o espaço na memória para colocar o sinal de menos.
    
    str = malloc(sizeof(char) * (i + 1));
    if(str == NULL)
        return(NULL);
    str[i] = '\0';
    
    if(cpy_number < 0) // para escrever o sinal de menos na saída.
    {
        str[0] = '-';
        cpy_number *= (-1); // para não dar problema embaixo. 
    }
    //agora vou mexer com a cópia, que foi onde guardei meu número.
    do
    {
        str[i - 1] = cpy_number % 10 + '0'; // aqui eu tenho o dígito 4 (ex: 1234), pois o módulo guarda o resto, o resto aqui é o 4, primeiro núemro que vou botar na posição
        cpy_number = cpy_number/10; // aqui eu divido por 10 pra diminuir o número(seria como um i-- pra passar pro próximo caracter)
        i--;
    } while(cpy_number);
    return(str);
}

int main()
{
    char *str;
    
    str = ft_itoa(-2147483648);
    printf("%s\n", str);
    str = ft_itoa(2147483647);
    printf("%s\n", str);
    str = ft_itoa(-2);
    printf("%s\n", str);
    str = ft_itoa(0);
    printf("%s\n", str);
}
