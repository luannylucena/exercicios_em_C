#include <stdio.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *tmp;
    int swap;

    tmp = lst; //para manter um ponteiro para o início original da lista, já que a lista será modificada durante a ordenação.
    while(lst->next != NULL) //percorre a lista enquanto o próximo elemento não for nulo
    {
        if(((*cmp)(lst->data, lst->next->data)) == 0) //Se o resultado da comparação for igual a zero, isso significa que os elementos estão fora de ordem e precisam ser trocados
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;

            lst = tmp; //o ponteiro lst é restaurado para o valor original (tmp), o que permite recomeçar a verificação da ordenação desde o início.
        }
        else
            lst = lst->next; //Se o resultado da comparação for diferente de zero, significa que os elementos estão em ordem e a função avança para o próximo elemento na lista, atribuindo o valor de lst->next a lst.
    }
    lst = tmp; //Após percorrer toda a lista e realizar as trocas necessárias, a função atribui o valor de tmp de volta a lst para garantir que a lista retornada seja o início original da lista.
    return(lst);
}