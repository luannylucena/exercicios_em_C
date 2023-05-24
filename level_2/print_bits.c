/*
Escreva uma função que receba um byte e o imprima em binário SEM UMA NOVA LINHA NO FINAL.

Sua função deve ser declarada da seguinte forma:

void print_bits(unsigned char octet);

*/

void print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit;
    
    while(i--)
    {
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
    }
}