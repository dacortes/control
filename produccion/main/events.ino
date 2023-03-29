/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evnets.ino                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:28:38 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/29 17:28:38 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"control.h"

void    print_temp()
{
    int temp = 0;
    int t = 0;

    temp = analogRead(STemperatureA);
    t = ((temp * 5000.0)) / 1023 / 10;
    nArdu.setValue(t);
    tArdu.setValue(t);
    if (t >= 26 && t <= 70)
    {
        digitalWrite(Vent1,HIGH);
        digitalWrite(Vent2,HIGH);
    }
    else
    {
        digitalWrite(Vent1,LOW);
        digitalWrite(Vent2,LOW);
    }
}

void    print_date()
{
    DateTime now = rtc.now();
    int dia = now.date();
    int mes = now.month();
    int Year = now.year();
    int hora = now.hour();
    int minuto = now.minute();
    int segundo = now.second();

    nday.setValue(dia);
    nmonth.setValue(mes);
    nYear.setValue(Year);
    nHr.setValue(hora);
    nMn.setValue(minuto);
    nSg.setValue(segundo);
}

void    print_temp_dig()
{
    int temp = 0;
    
    ds18b20.requestTemperatures();
    temp = ds18b20.getTempCByIndex(0); //obtener temperatura
    nInver.setValue(temp);
    tInver.setValue(temp);
}

void    automatic()
{
    uint32_t Auto;

    bAuto.getValue(&Auto);
    switch (Auto)
    {
    case HIGH:
        digitalWrite(ledAuto,HIGH);
        Estado = 1;
        break;
    case LOW:
        digitalWrite(ledAuto,LOW);
        Estado = 0;
        break;
    }    
}

void    switch_relay()
{
    uint32_t status;

    Bomba1.getValue(&status);
    if (status)
        digitalWrite(BLechugas,LOW);
    else
        digitalWrite(BLechugas,HIGH);
}

/* Funcion rango de minutos*/
static int ft_minutes(int minutes)
{
    if (minutes >= 0 && minutes <= 9)
        return (ON1);
    else if (minutes >= 40 && minutes <= 49)
        return (ON2);
    else
        return (OFF);
    return (OFF);
}

/* funcion de ciclo por horas*/
static bool ft_hour(int hour, int minutes)
{
    if ((hour >= 6 && hour <= 20) && (ft_minutes(minutes) == ON1
        || ft_minutes(minutes) == ON2))
        return (true);
    else if (hour == 22 && ft_minutes(minutes) == ON1)
        return (true);
    else if (hour == 0  && ft_minutes(minutes) == ON1)
        return (true);
    else if (hour == 2  && ft_minutes(minutes) == ON1)
        return (true);
    else if (hour == 4  && ft_minutes(minutes) == ON1)
        return (true);
    else
        return (false);
    return (false);
}

void    ft_irrigation()
{
    DateTime now = rtc.now();
    int hora    =now.hour();
    int minuto  =now.minute();
    int segundo = now.second();

    if (ft_hour(hora, minuto))
        digitalWrite(BLechugas,LOW);
    else
        digitalWrite(BLechugas,HIGH);
}

