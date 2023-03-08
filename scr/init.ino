/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:23:45 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/05 15:23:45 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"hidroteg.h"

void    init_pins()
{
    pinMode(relay_one, OUTPUT);
}

void    init_status()
{
    digitalWrite(relay_one, HIGH);
}

void    init_events()
{
    btn_auto.attachPop(event_relay_one, relay_one);
}