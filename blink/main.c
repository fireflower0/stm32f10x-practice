#include "stm32f10x.h"

GPIO_InitTypeDef GPIO_InitStructure;

int main(void) {
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_WriteBit(GPIOC, GPIO_Pin_8, Bit_RESET);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  for (;;) {
    if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0){
      GPIO_WriteBit(GPIOC, GPIO_Pin_8, Bit_RESET);
    } else {
      GPIO_WriteBit(GPIOC, GPIO_Pin_8, Bit_SET);
    }
  }
}
