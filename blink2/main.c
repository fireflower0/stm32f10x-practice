#include "STM32vldiscovery.h"

int main(void) {
  STM32vldiscovery_LEDInit(LED3);
  STM32vldiscovery_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);
  while(1) {
    if(STM32vldiscovery_PBGetState(BUTTON_USER) == 0){
      STM32vldiscovery_LEDOff(LED3);
    } else {
      STM32vldiscovery_LEDOn(LED3);
    }
  }
}
