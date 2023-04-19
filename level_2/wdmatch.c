/* Escreva um programa que receba duas strings e verifique se é possível escrever a primeira string com os caracteres da segunda string, 
   respeitando a ordem em que esses caracteres aparecem na segunda string.

   Se possível, o programa exibe a string, seguida de um \n, caso contrário, ele simplesmente exibe um \n.

   Se o número de argumentos não for 2, o programa exibe um \n.*/

   #include <unistd.h>

   void wdmatch(char *str1, char *str2)
   {
        int i = 0;
        int j = 0;

        while(str2[j] != '\0')
        {
            if(str1[i] == str2[j])
                i++;
            if(str1[i] == '\0')
            {
                write(1, str1, i);
                break;
            }
            j++;
        }
        
   }

   int main(int argc, char **argv)
   {
        if(argc != 3)
        {
            write(1, "\n", 1);
            return(1);
        }
        wdmatch(argv[1], argv[2]);
        return(0);
   }