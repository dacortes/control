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
/* Declaración de pines */
# define relay_one 8

/* Configurar :año- mes- dia- hora- minutos- segundo */
DateTime dt(2021, 1, 6,  15, 11, 0, 0);

/* Declaración de los objetos a utilizar [pagina id:0, componente id:1,
nombrecomponente: "obj_name"]*/

/* Botones de la pagina 1 */
NexDSButton btn_auto = NexDSButton(1, 2, "btn_auto");
NexDSButton btn_manu = NexDSButton(1, 2, "btn_manu");

/* Registro de los btns de la lista de eventos*/
NextTouch *nex_listen_list[] =
{
    &btn_auto,
    &btn_manu,
    NULL
};

/* FUNCIONES */
/* events.ino */
void    event_relay_one(void *ptr);
/* init.ino */
void    init_pins();
void    init_status();
void    init_events();

/* events.ino*/
void    event_relay_one(void *ptr);
bool    ft_hour(int hour);
bool    ft_range(int minutes, int seconds);
#endif