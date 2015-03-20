#ifndef _TEST_H_
#define _TEST_H_

#define LED1 GPIO_Pin_12
#define LED2 GPIO_Pin_13
#define LED3 GPIO_Pin_14
#define LED4 GPIO_Pin_15

extern void ledInit(void);

extern void setLed(uint16_t pin);
extern void resetLed(uint16_t pin);



#endif
