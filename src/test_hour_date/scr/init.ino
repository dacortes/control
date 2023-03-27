/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:23:45 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/05 15:23:45 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/hidroteg.h"

void    init_pins()
{
    pinMode(relay_one, OUTPUT);
}

void    init_status()
{
    digitalWrite(relay_one, HIGH);
}

void    init_events()
{
    btn_auto.attachPop(event_relay_one, relay_one);
}

void    init_date(int day, int month, int year)
{
    day = now.date();
    month = now.month();
    year = now.year();
    /* envio de datos */
    n_day.setValue(day);
    n_month.setValue(month);
    n_year.setValue(year);
}

void    init_hour(int hour, int minute, int second)
{
    hour = now.hour();
    minute = now.minute();
    second = now.second();
    /* envio de datos */
    n_hour.setValue(hour);
    n_minu.setValue(minute);
    n_seco.setValue(second);
}