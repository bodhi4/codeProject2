#define rightLim 10

void checkPingUnder()
{
  Distunder = UnderPing.ping_cm();
}

void checkDistUnder()
{
  if(Distunder > 10)
  {
    warningFlagU = true;
  }
}

void checkPingRight()
{
  Distright = RightPing.ping_cm();
}

void checkDistRight()
{
  if(Distright > 7 || Distright == 0)
  {
     warningFlagR = true;
  }
}

void checkPingFront()
{
  Distfront = FrontPing.ping_cm();
}

void checkDistFront()
{
  if(Distfront > 10)
  {
    warningFlagF = true;
  }
  else if(Distfront < 5)
  {
    warningFlagCloseF = true;
  }
}

void checkPingLeft()
{
  DistLeft = LeftPing.ping_cm();
}

void checkDistLeft()
{
  if(DistLeft > 7 || DistLeft == 0)
  {
    warningFlagL = true;
  }
}


 

