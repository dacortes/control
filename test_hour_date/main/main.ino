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
void setup ()
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
}
