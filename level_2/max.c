int max(int *tab, unsigned int len)
{
    int max;

	if(!tab)
		return(0);
	max = tab[len - 1];
	while((int)len >= 0)
	{
		if(max < tab[len -1])
			max = tab[len-1];
		len--;
	}
	return(max);
}