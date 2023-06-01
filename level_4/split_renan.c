/*
Escreva uma função que pegue uma string, divida-a em palavras e as retorne como
uma matriz de strings terminada em NULL.

Uma "palavra" é definida como parte de uma string delimitada por espaços/tabs/new
linhas ou pelo início/fim da string.

Sua função deve ser declarada da seguinte forma: char    **ft_split(char *str);
*/

//primeira coisa: conto as palavras
//sgundo: conto quantos caracteres tem a palavra

//"\t\t\t\t\t  \t\t\n\n\n\n Luanny\t \n usando \n \t split \t yeaaaay ! \n\n\n\n\n\t\t\t "
//"\t\t\t\t\t  \t\t\n\n\n\n Luanny\t \n usando \n \t split \t yeaaaay !"

#include <stdlib.h>

char  **ft_split(char *str)
{
    int i = 0;
    int j = 0; //para contar meus caracteres de cada palavra;
    int k = 0; //para percorer a cópia da minha palavra;
    int line = 0;
    char **word;
    int count_words = 0; 

    while(str[i])
    {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            i++;
        }
        else
        {
            count_words++;
            while(str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0') //tem que ser diferente de '\0 pq não posso contá-lo
                i++;
        }
    }
    //faço com (char *) pq tenho várias palavras dentro dele. 
    word = malloc(sizeof(char *) * (count_words + 1));
    if(word == NULL)
        return(NULL);
    while(line < count_words)
    {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            i++;
        }
        else
        {
            while(str[j] != ' ' && str[j] != '\t' && str[j] != '\n' && str[j] != '\0')
                j++;
            word[line] = malloc(sizeof(char) * ((j - i) + 1)); 
            if(word[line] == NULL)
                return(NULL);
            while(i < j) //o i é ocomeço da minha palavra e o j é o final de cada palavra.
            {
                word[line][k] = str[i]; //teho 2 índices pq é ponteiro de ponteiro.
                k++;
                i++;
            }
            word[line][k] = '\0';
        }
    }
    word[line] = NULL; //condição que a quesoa pede. Que termine com null.
    return(word);
}
