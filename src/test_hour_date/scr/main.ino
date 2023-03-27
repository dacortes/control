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

#include"../inc/hidroteg.h"

/* init pines*/
void setup ()
{
    nexInit();
    init_pins();
    init_status();
    init_events();
    rtc.setDateTime(dt);
}

void loop()
{
  init_date(day, month, year);
  init_hour(hour, minute, second);
  nexLoop(nex_listen_list);
}

