#include <stdlib.h>
#include <stdio.h>
#include "arbitary.h"

t_arbint		*arbint_add(t_arbint *n1, t_arbint *n2)
{
	t_wideint	value;
	t_int		i;
	t_arbint	*result;
	t_int		min_length;

	i = 0;
	result = malloc(sizeof(t_arbint));
	result->length = (n1->length > n2->length) ? n1->length : n2->length;
	result->value = malloc(sizeof(t_int) * (++(result->length)));
	value = 0;
	result->sign = n1->sign ^ n2->sign;
	min_length = n1->length < n2->length ? n1->length : n2->length;
	while (i < min_length)
	{
		value += (t_wideint)n1->value[i] + (t_wideint)n2->value[i];
		result->value[i] = (t_int)value;
		value >>= 32;
		i++;
	}
	n1 = n1->length > n2->length ? n1 : n2;
	while (i < result->length - 1)
	{
		value += (t_wideint)n1->value[i];
		result->value[i] = (t_int)value;
		value >>= 32;
		i++;
	}
	result->value[i] = value;
	return (result);
}



int		main(void)
{
	t_arbint	*n1;
	t_arbint	*n2;
	t_arbint	*n3;

	n1 = malloc(sizeof(t_arbint));
	n1->value = malloc(sizeof(t_int) * 2);
	n1->length = 2;
	n1->value[0] = 333333333;
	n1->value[1] = 2332;
	n2 = malloc(sizeof(t_arbint));
	n2->value = malloc(sizeof(t_int));
	n2->length = 1;
	n2->value[0] = 333333333;
	n3 = arbint_add(n1, n2);
	printf("|%u||%u|", n3->value[0], n3->value[1]);
}
