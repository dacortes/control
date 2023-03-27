/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.ino                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:40:58 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/03 12:40:58 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"hidroteg.h"

/* Funcion de off-on rele manual */
void event_relay_one(void *ptr)
{
    uint32_t    state;
    
    btn_auto.getValue(&state);
    if (state == true)
        digitalWrite(relay_one, LOW);
    else
        digitalWrite(relay_one, HIGH);
}

/* Funcion de off-on rele automatico */
void event_relay_two(void *ptr)
{
    uint32_t    state;
    
    btn_manu.getValue(&state);
    if (state == true)
        digitalWrite(relay_two, LOW);
    else
        digitalWrite(relay_two, HIGH);
}

/* Funcines ciclos del riego*/
/* funcion de ciclo por horas*/
bool ft_hour(int hour)
{
    if ((hour >= 6 && hour <= 20))
        return (true);
    else if (hour == 22)
        return (true);
    else if (hour == 2)
        return (true);
    else if (hour == 4)
        return (true);
    else
        return (false);
    return (false);
}

/* Funcion rango de minutos*/
bool ft_minutes(int minutes, int seconds, int hour)
{
    if (minutes >= 0 && minutes <= 9)
        return (true);
    else if (minutes >= 40 && minutes <= 49)
        return (true);
    else
        return (false);
    return (false);
}
