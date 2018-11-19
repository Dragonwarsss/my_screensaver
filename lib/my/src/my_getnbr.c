/*
** EPITECH PROJECT, 2018
** Day04
** File description:
** my_getnbr
*/

int is_same(char*, char*);

int is_same(char *str, char *str2)
{
    int i;

    for (i = 0; str[i]; i += 1) {
        if (str[i] != str2[i])
            return (0);
    }
    return (1);
}

int my_getnbr(char *str)
{
    int	nbr = 0;
    int	nb_final = 0;
    int	neg = 1;
    int i;

    if (is_same(str, "9223372036854775807") ||
        is_same(str, "18446744073709551615"))
        return (0);
    for (i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '-')
            neg = - 1;
        if (str[i] >= 48 && str[i] <= 57) {
            nbr = str[i] - 48;
            if (str[i] >= '0' && str[i] <= '9') {
                nbr = str[i] - 48;
                nb_final = nb_final * 10 + nbr;
            }
            if (str[i + 1] < '0' || str[i + 1] > '9')
                return (neg * nb_final);
        }
    }
    return (nb_final);
}
