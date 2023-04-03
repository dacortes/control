/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ino                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:36:06 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/31 15:36:06 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Nextion.h"
#include <Wire.h>
#include <Sodaq_DS3231.h> 

#define   relay 5
#define   fan_1 2
#define   fan_2 3
#define   temp_sensor A7

// ================================= Buttons ================================ //
NexDSButton btn_automatic = NexDSButton(0, 1, "btn_automatic");
NexDSButton btn_manual    = NexDSButton(0, 2, "btn_manual");
// ================================= Date =================================== //
NexNumber n_month = NexNumber(0, 3, "n_month");
NexNumber n_day   = NexNumber(0, 4, "n_day");
NexNumber n_year  = NexNumber(0, 5, "n_year");
// ================================= Hour =================================== //
NexNumber n_hour    = NexNumber(0, 8, "n_hour");
NexNumber n_minute  = NexNumber(0, 9, "n_minute");
NexNumber n_second  = NexNumber(0, 10, "n_second");

NexTouch *nex_listen_list[] =
{
  &btn_automatic,
  &btn_manual,
  NULL
};

DateTime dt(2023, 4, 3,  7, 39, 50, 0);
bool automaticMode = false;

void    ft_fan()
{
    int temp = 0;
    int t = 0;

    temp = analogRead(temp_sensor);
    t = ((temp * 5000.0)) / 1023 / 10;
    if (t >= 30)
    {
        digitalWrite(fan_1,HIGH);
        digitalWrite(fan_2,HIGH);
    }
    else
    {
        digitalWrite(fan_1,LOW);
        digitalWrite(fan_2,LOW);
    }
}

void checkCycle(int hour, int minute)
{
  if (hour >= 6 && hour <= 18)
  {
    int minutes_past_hour = (hour * 60) + minute - 370;

    if (minutes_past_hour % 30 <= 9)
    {
      digitalWrite(relay, LOW);
    }
    else
    {
      digitalWrite(relay, HIGH);
    }
  }
  else if (hour == 20 || hour == 22 || hour == 0 || hour == 2 || hour == 4)
  {
    if (minute >= 0 && minute <= 9)
    {
      digitalWrite(relay, LOW);
    }
    else
    {
      digitalWrite(relay, HIGH);
    }
  }
  else
  {
    digitalWrite(relay, HIGH);
  }
}

void cycles()
{
  DateTime now = rtc.now();
  checkCycle(now.hour(), now.minute());
}

void ft_automatic()
{
  uint32_t status;
  btn_automatic.getValue(&status);
  if (status == 1)
  {
    automaticMode = true;
  }
  else
  {
    automaticMode = false;
    digitalWrite(relay, HIGH);
  }
}

void ft_manual()
{
  uint32_t status_m;
  btn_manual.getValue(&status_m);
  if (status_m == 1)
  {
    digitalWrite(relay, LOW);
  }
  else
  {
    digitalWrite(relay, HIGH);
  }
}

void updateValues()
{
  DateTime now = rtc.now();
  n_month.setValue(now.month());
  n_day.setValue(now.date());
  n_year.setValue(now.year());
  n_hour.setValue(now.hour());
  n_minute.setValue(now.minute());
  n_second.setValue(now.second());
}

void setup() 
{
  nexInit();
  rtc.begin();
  rtc.setDateTime(dt);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  pinMode(temp_sensor,INPUT);
  btn_automatic.attachPop(ft_automatic);
  btn_manual.attachPop(ft_manual);
}

void loop()
{
  static unsigned long lastUpdate = 0;
  unsigned long currentTime = millis();
  
  if (currentTime - lastUpdate >= 1000)
  {
    lastUpdate = currentTime;
    updateValues();
  }
  if (automaticMode == true)
  {
    cycles();
  }
  ft_fan();
  nexLoop(nex_listen_list);
}