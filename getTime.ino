void getTime_Date()
{
  timeClient.update();
  if(timeClient.update() == true)
  digitalWrite(redLed, LOW); //means wifi is connected to internet
  else
  digitalWrite(redLed, HIGH); //means wifi has timed out
  time_t epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime ((time_t *)&epochTime);
  currentTime = String(String(timeClient.getHours())+":"+String(timeClient.getMinutes()));
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon+1;
  int currentYear = ptm->tm_year+1900;
  currentDate = String(String(monthDay) + "/" + String(currentMonth) + "/" + String(currentYear)); 
}
