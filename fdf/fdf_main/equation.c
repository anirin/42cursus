/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:36:24 by atsu              #+#    #+#             */
/*   Updated: 2023/07/29 15:17:48 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double get_slope(t_cor cor1, t_cor cor2)
{
	double slope;

	slope = (cor2.y - cor1.y) / (cor2.x - cor1.x);
	return slope;
}

double get_intercept(t_cor cor1, double slope)
{
	double intercept;

	intercept = cor1.y - (slope * cor1.x);
	return intercept;
}