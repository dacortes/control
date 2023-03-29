/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.ino                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:12:08 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/29 17:12:08 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"control.h"

void setup ()
{
    nexInit();
    rtc.begin();
    //rtc.setDateTime(dt);
    Serial.begin(9600);
    ds18b20.begin();
    init_pin_mode();
}

void loop()
{
    tiempoX = millis();
    print_temp();
    print_date();
    print_temp_dig();
    switch_relay();
    automatic();
    if (Estado)
        ft_irrigation();
    if (tiempoX == 1000)
        nexLoop(nex_listen_list);
}
