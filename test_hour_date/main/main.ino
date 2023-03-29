/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.ino                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:38:39 by dacortes          #+#    #+#             */
/*   Updated: 2023/02/28 20:38:39 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"hidroteg.h"

/* init pines*/
/*void setup ()
{
    ds18b20.begin();
    init_rtc();
    nexInit();
    init_pins();
    init_status();
    init_events();
}

void loop()
{
  DateTime now = rtc.now();
  init_date(day, month, year, now);
  init_hour(hour, minute, second, now);
  init_temperature(&temperature);
  nexLoop(nex_listen_list);
}*/
DateTime dt(2021, 1, 6,  15, 11, 0, 0);
void setup () {
  Serial.begin(9600);
  rtc.setDateTime(dt);
}

void loop () {
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.date(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  delay(1000);
}
