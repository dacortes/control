/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.ino                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:17:18 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/29 17:17:18 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"control.h"

/* Inicializar modeo de pines y estados */
void	init_pin_mode()
{
	pinMode(BLechugas,OUTPUT);
	pinMode(Rele,OUTPUT);
	pinMode(Rele2,OUTPUT);
	pinMode(Vent1,OUTPUT);
	pinMode(Vent2,OUTPUT);
	pinMode(ledAuto,OUTPUT);
	pinMode(STemperatureA,INPUT);
	pinMode(STemperatureD,INPUT);
	digitalWrite(Vent1,LOW);
	digitalWrite(Vent2,LOW);
	digitalWrite(BLechugas,HIGH);
	digitalWrite(Rele,HIGH);
	digitalWrite(Rele2,HIGH);
}