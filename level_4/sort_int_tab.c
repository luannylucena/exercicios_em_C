/*

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

// BUBBLE SORT 
// recebe um array de inteiros (tab) e o tamanho do array (size) como parâmetros. A função tem como objetivo ordenar o array em ordem crescente.

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    int temp;

    //a função entra em um loop while que continua enquanto i é menor que size - 1. Isso garante que o loop seja executado até o penúltimo elemento do array, pois a comparação é feita com o próximo elemento (tab[i + 1]).
    while(i < (size -1))
    {
        if(tab[i] > tab[i + 1]) // se o tab[i] for maior que o próximo elemento 'tab[i + 1]'...
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            
            i = 0; //Após realizar a troca, a função redefine o valor de i como 0. Isso ocorre porque, após a troca, é necessário verificar novamente desde o início se há mais elementos fora de ordem. 
        }
        else 
            i++; //Se a condição do if não for atendida, ou seja, os elementos estiverem em ordem, a função incrementa i em 1 para verificar o próximo par de elementos.
    }
}
