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

#include"hidroteg.h"

void    init_rtc()
{
    rtc.begin();
    if (!rtc.isrunning())
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void    init_pins()
{
    pinMode(relay_one, OUTPUT);
    pinMode(relay_two, OUTPUT);
}

void    init_status()
{
    digitalWrite(relay_one, HIGH);
    digitalWrite(relay_two, HIGH);
}

void    init_events()
{
    btn_auto.attachPop(ft_automatic, &btn_auto);
    btn_manu.attachPop(ft_manual, &btn_manu);
}

void    init_date(int day, int month, int year, DateTime now)
{
    day = now.day();
    month = now.month();
    year = now.year();
    /* envio de datos */
    n_day.setValue(day);
    n_month.setValue(month);
    n_year.setValue(year);
}

void    init_hour(int hour, int minute, int second, DateTime now)
{
    hour = now.hour();
    minute = now.minute();
    second = now.second();
    /* envio de datos */
    n_hour.setValue(hour);
    n_minu.setValue(minute);
    n_seco.setValue(second);
}