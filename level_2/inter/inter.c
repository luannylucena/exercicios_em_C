#include <unistd.h>

//Essa função retorna 1 se o caractere já apareceu anteriormente na string e 0 caso contrário.

//O programa principal (função "main") verifica se o número de argumentos é igual a 3 e, em seguida, itera 
//sobre a primeira string (argumento 1) e verifica se o caractere atual não apareceu anteriormente na mesma string. 
//Em caso afirmativo, o programa itera sobre a segunda string (argumento 2) e verifica se o caractere atual também aparece na segunda string. 
//Se isso acontecer, o programa escreve o caractere na saída padrão. Finalmente, o programa escreve um caractere de nova linha ("\n") na saída padrão para terminar a saída.

int check(int i, char c, char *str)
{
    int j = 0;

    while(j < i)
    {
        if(str[j] == c) //se encontrar o caracter na mesma string antes da posição que ele tá, significa que ele ta duplicado. 
            return(1); //retorna 1 para dizer que é verdadeiro que o caracter está duplicado.
        j++;
    }
    return(0);
}

int main(int argc, char **argv)
{
    if(argc == 3)
    {
        int i = 0;
        int j = 0;
        char *str1 = argv[1];
        char *str2 = argv[2];

        while(str1[i] != '\0')
        {
            if(!check(i, str1[i], str1)) //vou percorrer a string 1, se a função for negativa, siginifica que não temos letras repetida, então entra nesse loop.
            {
                j = 0;
                while(str2[j] != '\0') 
                {
                    if(str1[i] == str2[j])
                    {
                        write(1, &str1[i], 1); //se encontro um caracter igual, imprimo na ordem da string 1.
                    break;
                    }
                j++;
                }
            }
            i++;
        }
    }
    write(1, "\n", 1);
}