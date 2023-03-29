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
# include <Wire.h>
//# include <RTClib.h>
# include <Sodaq_DS3231.h>

/* ============================== MACROS =====================================*/

# define ON1 1
# define ON2 2
# define OFF 0
/* Declaración de pines */
# define relay_one 8
# define relay_two 9
# define sn_temperature 4

/* ============================== SENSOR_TEMPERATURE =========================*/

OneWire communication (sn_temperature);
DallasTemperature ds18b20 (&communication);
/* Configurar :año- mes- dia- hora- minutos- segundo */
/*DateTime dt(2021, 1, 6,  15, 11, 0, 0);*/
//RTC_DS3231 rtc;
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
NexTouch *nex_listen_list[] =
{
    &btn_auto,
    &btn_manu,
    NULL
};

/* Declaración de variables */
int day = 0;
int month = 0;
int year = 0;
int hour = 0;
int minute = 0;
int second = 0;
int temperature = 0;
/* ============================== FUNCIONES ==================================*/

/* init.ino */
void    init_rtc();
void    init_pins();
void    init_status();
void    init_events();
void    init_temperature(int *temperature);
void    init_date(int day, int month, int year, DateTime now);
void    init_hour(int hour, int minute, int second, DateTime now);

/* events.ino*/
void    ft_manual(void *ptr);
void    ft_automatic(void *ptr);
bool    ft_hour(int hourn, int minutes);
int     ft_minutes(int minutes);

#endif
