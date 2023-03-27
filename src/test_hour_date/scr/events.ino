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

#include"../inc/hidroteg.h"

/* Funcion de off-on rele manual */
void event_relay_one(void *ptr)
{
    unit32_t    state;
    
    automatic.getValue(&state);
    if (state == true)
        digitalWrite(relay_one, LOW);
    else
        digitalWrite(relay_one, HIGH);
}

/* Funcion de off-on rele automatico */
void event_relay_two(void *ptr)
{
    unit32_t    state;
    
    automatic.getValue(&state);
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
bool ft_range(int minutes, int seconds)
{
    int ON_INTERVAL;
    int OFF_INTERVAL;
    
    ON_INTERVAL = 0;
    OFF_INTERVAL = 0;
    if (minutes != minutes + 1)
    {
        OFF_INTERVAL++;
        if (OFF_INTERVAL == 10 && seconds == 0 && ON_INTERVAL == 0)
            OFF_INTERVAL = 0;
        if (OFF_INTERVAL == 9 && seconds == 59)
        {
            ON_INTERVAL++;
            if (ON_INTERVAL == 30 && seconds == 0)
                ON_INTERVAL = 0;
        }
        if (OFF_INTERVAL >= 0 && OFF_INTERVAL <= 9)
            return (true);
        else
            return (false);
    }
    return (false);
}
