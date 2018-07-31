

void centra(){    
  serialEvent3();


 if((distDx+distSx)>140){
   if(distDx-distSx > 15){
    moveRobot(90, 0, 70, 0);
  }
  else if(distDx-distSx < -15){
    moveRobot(270, 0, 70, 0);
  }
  else if((distDx-distSx <= 7) || (distDx-distSx >= -7)){
    moveRobot(fermo, 0, 0, 0);
  }
 }

}








void ct(){
  serialEvent3();
  //lineeBianche();
  moveRobot(fermo, 0, 0, 0);
  for(int m=0; m<300; m++){
  
  riallinea();
  }
    while((distPx > 35)&&(bandieraBianca == false))
    {
      serialEvent3();
      moveRobot(180, 0, 70, 0);
    }
//  for(int m=0; m<3000; m++){
//
//  if(distDx-distSx > 16){
//    moveRobot(90, 0, 70, 0);
//  }
//  
//  else if(distDx-distSx < -16){
//    moveRobot(270, 0, 70, 0);
//  }
//  else if((distDx-distSx <= 8) || (distDx-distSx >= -8)){
//    if((distPx > 25)||(bandieraBianca == false))
//    {
//      moveRobot(180, 0, 70, 0);
//    }
//    else {
//      moveRobot(fermo, 0, 0, 0);
//    }
//  }
//
//
//  }
moveRobot(fermo, 0, 0, 0);
}


























