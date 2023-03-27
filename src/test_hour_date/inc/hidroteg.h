/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidroteg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:26:06 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/28 20:26:06 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIDROTEG_H
# define HIDROTEG_H

# include "Nextion.h"
# include <OneWire.h>
# include <DallasTemperature.h>
# include <Sodaq_DS3231.h>
# include <Wire.h>
# include <RTClib.h>

/* Declaración de pines */
# define relay_one 8

/* Configurar :año- mes- dia- hora- minutos- segundo */
/*DateTime dt(2021, 1, 6,  15, 11, 0, 0);*/
RTC_DS3231 rtc;
/* Declaración de los objetos a utilizar [pagina id:0, componente id:1,
nombrecomponente: "obj_name"]*/

/* Botones de la pagina 1 */
NexDSButton btn_auto = NexDSButton(1, 2, "btn_auto");
NexDSButton btn_manu = NexDSButton(1, 2, "btn_manu");

/* ============================== HORA =======================================*/

NexNumber n_hour = NexNumber(3, 6, "n_hour");
NexNumber n_minu = NexNumber(3, 7, "n_minu");
NexNumber n_seco = NexNumber(3, 8, "n_seco");

/* ============================== FECHA ======================================*/

NexNumber n_day = NexNumber(3, 9, "n_day");
NexNumber n_month = NexNumber(3, 10, "n_month");
NexNumber n_year = NexNumber(3, 11, "n_year");

/* Registro de los btns de la lista de eventos*/
NextTouch *nex_listen_list[] =
{
    &btn_auto,
    &btn_manu,
    NULL
};

/* Declaración de variables */
int     day = 0;
int     month = 0;
int     year = 0;
int     hour = 0;
int     minute = 0;
int     second = 0;
/* ============================== FUNCIONES ==================================*/
/* events.ino */
void    event_relay_one(void *ptr);
/* init.ino */
void    init_rtc()
void    init_pins();
void    init_status();
void    init_events();
void    init_date(int day, int month, int year);
void    init_hour(int hour, int minute, int second);

/* events.ino*/
void    event_relay_one(void *ptr);
bool    ft_hour(int hour);

#endif