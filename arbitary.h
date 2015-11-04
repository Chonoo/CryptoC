#ifndef ARBITARY_H
# define ARBITARY_H
# include <stdint.h>

typedef unsigned char		t_byte;
typedef uint64_t			t_wideint;
typedef uint32_t			t_int;

typedef struct				s_arbitary_int
{
	t_int					*value;
	t_int					length;
	t_byte					sign;
}							t_arbint;

t_arbint					*arbint_add(t_arbint *n1, t_arbint *n2);

#endif
