/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:57:17 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/03 22:51:48 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_invalid_str(int argc, char **argv);
{
    int i;
    int j;
    char *str;

    i = 1;
    j = 0;
    while(i < argc)
    {
        str = argv[i++];
        j = 0;
        while(str[j] != '\0')
        {
            if (ft_issapce(str[j]) == NG && ft_isdigit(str[j]) == NG && is_plus_minus(str[j]) == NG)
                return (NG);
            if (is_plus_minus(str[j]) == OK && ft_isdigit(str[j]) == NG)
                return (NG);
            j++;
        }
    }
    return (OK);
}

int check_duplication()
{
    while()
}

int error_check(int argc, char **argv)
{
    if (argc <= 1)
        return (NG);
	check_invalid_str(argc, argv);//maybe list is better than  array in first set because size is unkonwn 
    check_over_flow();
	check_duplication();
}
