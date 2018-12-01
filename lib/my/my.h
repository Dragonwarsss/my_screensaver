/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_h_
#define MY_PRINTF_H_

typedef struct s_function function_t;

struct s_function {
    void (*ptr)(int);
    char c;
    function_t *next;
};

int my_printf(char *str, ...);
void my_put_nbr(int nb);
void my_put_nbr_binary(int nb);
void my_put_nbr_hexa(int nb);
void my_put_nbr_hexaup(int nb);
void my_put_nbr_octal(int nb);
void my_put_ptr(int nb);
void my_put_nbr_unsigned(int nb);
void my_putstr(char *str);
void my_putchar(int nb);

int my_atoi(char *s);

void free_ll(function_t *fnc);
function_t *push_ll(function_t *fnc, char c);
function_t *create_ll_3(function_t *fnc);
function_t *create_ll_2(function_t *fnc);
function_t *create_ll();

int my_strlen(char *str);
int my_strcomp(char *s1, char *s2);

#endif
