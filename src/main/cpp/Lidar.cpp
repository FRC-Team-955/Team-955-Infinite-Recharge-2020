#include "Lidar.h"
using namespace frc;

int Lidar::GetDistance(std::string units){
  if(units == "cm"){
    return ((lidar->GetPeriod()*1000000.0/10.0));
  }else{
    return ((lidar->GetPeriod()*1000000.0/10.0)/2.54);
  }
  
}
bool Lidar::IsInRange(int low_range, int high_range){
  dist = ((lidar->GetPeriod()*1000000.0/10.0)/2.54);
  if (dist >= low_range && dist <= high_range){
    return 1;
  }else{
    return 0;
  }
}