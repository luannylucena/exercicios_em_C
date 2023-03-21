#include <stdlib.h>
#include <stdio.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
    int i = -1;

    while(++i < n & s2[i])
        s1[i] = s2[i];
    s1[i] = '\0';
    return(s1);
}

char **ft_split(char *str)
{
    int i = 0; //percorre a string de entrada da esquerda p/ direita
    int j = 0; //usada para as palavras. Determina o início de cada palavra
    int k = 0; //para rastrear o índice atual da matriz de saída.
    int wc = 0; //conta as palavras

    //Qdo o 'i' encontra um caractere de espaço em branco, ele avança p/ próximo caractere.
    //Se i encontrar um caractere que não seja de espaço em branco, ele avança para o final 
    //da palavra atual, contando-a e incrementando o índice 'j' ao mesmo tempo. 
    //Qdo o final da string é alcançado, o número total de palavras é igual ao valor de 'wc'.

    // A segunda parte da função aloca memória para a matriz de strings de saída, usando o número 
    //de palavras calculado anteriormente. A matriz é um ponteiro para um conjunto de ponteiros de 
    //caracteres, onde cada ponteiro de caractere aponta para uma das palavras resultantes. 
    //A memória para a matriz é alocada dinamicamente usando a função malloc.

    //A terceira parte da função percorre a string de entrada novamente, desta vez copiando cada palavra 
    //encontrada na matriz de strings de saída. Quando uma palavra é encontrada, a função aloca memória 
    //para uma nova string na matriz usando malloc, copia a palavra da string de entrada para a nova 
    //string na matriz usando ft_strncpy, e avança para a próxima palavra.

    //Quando uma palavra é encontrada, a função aloca memória suficiente para essa palavra na matriz de 
    //saída out, copia a palavra da string de entrada str para a matriz out, e atualiza o índice k para 
    //apontar para a próxima posição na matriz.

    //esse primeiro while percorre a string e conta qtas palavras existem.
    while(str[i])
    {
        //esse while ignora espaços em branco no início da string ou entre as palavras
        while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++; //incrementa qdo acha um espaço em branco
        if(str[i]) //Se o próximo caractere na string str for nulo, significa que é a ultima palavrae a contagem está completa.
            wc++; //Caso contrário, o loop interno terminará quando encontrar o final da palavra atual, e a variável wc será incrementada em 1 para contar essa palavra
        //esse loop encontra o o início e o fim de cada palavra da string.
        while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++; //Quando o loop termina, a variável i aponta para o final da
            // palavra atual ou para o final da string str.
    }
    char **out = (char **)malloc(sizeof(char *) * (wc + 1));
    i = 0;
    while(str[i])
    {
        while(str[i] &&(str[i] == ' ' || str[i] == '\t' || str[i] '\n'))
            i++;
        j = i;
        while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
        if(i > j) //Se a palavra tiver mais de um caractere (ou seja, i for maior que j), a palavra é alocada dinamicamente na memória usando malloc e a função ft_strncpy é usada 
        //para copiar a palavra da string str para a matriz de strings de saída out
        {
            out[k] = (char *)malloc(sizeof(char *) * (i - j) + 1);
            ft_strncpy(out[k++], &str[j], i - j);
            //O índice k é incrementado para apontar para a próxima posição na matriz de strings out
        }
    }
    out[k] = NULL;
    return (out);
}