/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:02:15 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/29 17:02:15 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H
// ================================= LIBRARIES ============================== //

#include "Nextion.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Sodaq_DS3231.h> 

// ================================= MACROS ================================= //

#define ledAuto 12
//Bombas 
#define BLechugas 10
#define Rele 8
#define Rele2 9
//Ventiladores
#define Vent1 2
#define Vent2 3
//Sensores
#define STemperatureD 7
#define STemperatureA A7
//axuiliares
# define ON1 1
# define ON2 2
# define OFF 0

// ================================= COMPONENTS ============================= //

//DateTime dt(2023, 3, 29,  18, 35, 0, 0);//Configurar :año- mes- dia- hora- minutos- segundo
OneWire comuniacion(STemperatureD);
DallasTemperature ds18b20(&comuniacion);

// ================================= VARIABLES ============================== //

int				SENSOR;
bool			Estado;
unsigned long	tiempoX=0;

/* Bonotes pantalla nextion */
NexDSButton bAuto  = NexDSButton(0, 1, "bAuto"); 
NexDSButton Bomba1 = NexDSButton(0, 2, "Bomba1"); 
NexDSButton Bomba2 = NexDSButton(0, 3, "Bomba2");
/*Sensores*/
NexNumber nArdu   = NexNumber (0, 12, "nArdu");
NexNumber nInver   = NexNumber (0, 12, "nInver");
/* Bar temp */
NexProgressBar tArdu  = NexProgressBar(0, 4, "tArdu");
NexProgressBar tInver = NexProgressBar(0, 5, "tInver");
/* Fecha */
NexNumber nday    = NexNumber (0, 14, "nday");
NexNumber nmonth  = NexNumber (0, 15, "nmonth");
NexNumber nYear   = NexNumber (0, 16, "nYear");
//Hora
NexNumber nHr   = NexNumber (0, 17, "nHr");
NexNumber nMn   = NexNumber (0, 18, "nMn");
NexNumber nSg   = NexNumber (0, 19, "nSg");
NexTouch *nex_listen_list[] =
{
  &bAuto,
  &Bomba1,
  &Bomba2,
  NULL
};
// ================================= FUNTIONS =============================== //

void    init_pin_mode();
void    print_temp();
void    print_date();
void    print_temp_dig();
void    automatic();
void    switch_relay();
void    ft_irrigation();
#endif
