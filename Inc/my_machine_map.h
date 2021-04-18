/*
 * my_machine_map.h
 *
 *  Created on: 8 de abr de 2021
 *      Author: OSMAR
 *
 *      ESQUEMA DA PLACA
 *      E:\GRBL32\GRBL_HAL_F4\Esquema\GrblHAL.PRJ
 *
 *      MODIFICAÇÕES NO MÓDULO DRIVER.H
 *
 *      PARA USAR O I2C1
 *      #if EEPROM_ENABLE|| KEYPAD_ENABLE || (TRINAMIC_ENABLE && TRINAMIC_I2C)
 *	  #if defined(NUCLEO_F411) || defined(NUCLEO_F446)|| defined(STM32F407xx)
 *	    #define I2C_PORT 1 // GPIOB, SCL_PIN = 8, SDA_PIN = 9
 *	    ...
 *
 *	PARA MUDAR O TIMER DO SPINDLE
 * 	#define SPINDLE_PWM_TIMER_N         12
 *
 * 	MODIFICAÇÕES NO DRIVER.C
 * 	static bool driver_setup (settings_t *settings)
 * 	{
 * 	  __HAL_RCC_TIM12_CLK_ENABLE();
 * 	  GPIO_Init.Alternate = GPIO_AF9_TIM12;
 * 	  ...
 *
 *	OUTRAS MODIFICAÇÕES EM
 *	Project Explorer and select Properties > C/C++ General > Paths and Symbols > Symbols
 */

#ifndef MY_MACHINE_MAP_H_
#define MY_MACHINE_MAP_H_

#include "driver.h"

// Define step pulse output pins.
#define STEP_PORT         		GPIOA
#define X_STEP_PIN        		4
#define X_STEP_BIT        		(1<<X_STEP_PIN)
#define Y_STEP_PIN        		5
#define Y_STEP_BIT        		(1<<Y_STEP_PIN)
#define Z_STEP_PIN        		6
#define Z_STEP_BIT        		(1<<Z_STEP_PIN)
#if N_AXIS == 4
  #define A_STEP_PIN        	7
  #define A_STEP_BIT        	(1<<A_STEP_PIN)
  #define STEP_MASK         	(X_STEP_BIT|Y_STEP_BIT|Z_STEP_BIT|A_STEP_BIT) // All step bits
#else
  #define STEP_MASK         	(X_STEP_BIT|Y_STEP_BIT|Z_STEP_BIT) // All step bits
#endif
#define STEP_OUTMODE 			GPIO_MAP

// Define step direction output pins.
#define DIRECTION_PORT        	GPIOA
#define X_DIRECTION_PIN       	0
#define X_DIRECTION_BIT       	(1<<X_DIRECTION_PIN)
#define Y_DIRECTION_PIN       	1
#define Y_DIRECTION_BIT       	(1<<Y_DIRECTION_PIN)
#define Z_DIRECTION_PIN       	2
#define Z_DIRECTION_BIT       	(1<<Z_DIRECTION_PIN)
#if N_AXIS == 4
  #define A_DIRECTION_PIN       3
  #define A_DIRECTION_BIT       (1<<A_DIRECTION_PIN)
  #define DIRECTION_MASK        (X_DIRECTION_BIT|Y_DIRECTION_BIT|Z_DIRECTION_BIT|A_DIRECTION_BIT) // All direction bits
#else
  #define DIRECTION_MASK        (X_DIRECTION_BIT|Y_DIRECTION_BIT|Z_DIRECTION_BIT) // All direction bits
#endif
#define DIRECTION_OUTMODE     	GPIO_MAP

// Define stepper driver enable/disable output pin.
#define STEPPERS_DISABLE_PORT   GPIOA
#define STEPPERS_DISABLE_PIN    8
#define STEPPERS_DISABLE_BIT    (1<<STEPPERS_DISABLE_PIN)
#define STEPPERS_DISABLE_MASK   STEPPERS_DISABLE_BIT

// Define homing/hard limit switch input pins.
#define LIMIT_PORT         		GPIOD
#define X_LIMIT_PIN        		10
#define X_LIMIT_BIT        		(1<<X_LIMIT_PIN)
#define Y_LIMIT_PIN        		11
#define Y_LIMIT_BIT        		(1<<Y_LIMIT_PIN)
#define Z_LIMIT_PIN        		12
#define Z_LIMIT_BIT        		(1<<Z_LIMIT_PIN)
#if N_AXIS == 4
  #define A_LIMIT_PIN        	13
  #define A_LIMIT_BIT        	(1<<A_LIMIT_PIN)
  #define LIMIT_MASK       		(X_LIMIT_BIT|Y_LIMIT_BIT|Z_LIMIT_BIT|A_LIMIT_BIT) // All limit bits
#else
  #define LIMIT_MASK       		(X_LIMIT_BIT|Y_LIMIT_BIT|Z_LIMIT_BIT) // All limit bits
#endif
#define LIMIT_INMODE 			GPIO_MAP

  // Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT     GPIOD
#define SPINDLE_ENABLE_PIN      5
#define SPINDLE_ENABLE_BIT      (1<<SPINDLE_ENABLE_PIN)
#define SPINDLE_DIRECTION_PORT  GPIOD
#define SPINDLE_DIRECTION_PIN   4
#define SPINDLE_DIRECTION_BIT   (1<<SPINDLE_DIRECTION_PIN)

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT        GPIOB
#define SPINDLE_PWM_PIN         14
#define SPINDLE_PWM_BIT         (1<<SPINDLE_PWM_PIN)

#define COOLANT_FLOOD_PORT      GPIOD
#define COOLANT_FLOOD_PIN       7
#define COOLANT_FLOOD_BIT       (1<<COOLANT_FLOOD_PIN)
#define COOLANT_MIST_PORT       GPIOD
#define COOLANT_MIST_PIN        6
#define COOLANT_MIST_BIT        (1<<COOLANT_MIST_PIN)

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define CONTROL_PORT            GPIOE
#define CONTROL_RESET_PIN       6
#define CONTROL_FEED_HOLD_PIN   7
#define CONTROL_CYCLE_START_PIN 8
#define CONTROL_SAFETY_DOOR_PIN 9
#define CONTROL_INMODE 			GPIO_MAP

#define CONTROL_RESET_BIT       (1<<CONTROL_RESET_PIN)
#define CONTROL_FEED_HOLD_BIT   (1<<CONTROL_FEED_HOLD_PIN)
#define CONTROL_CYCLE_START_BIT (1<<CONTROL_CYCLE_START_PIN)
#define CONTROL_SAFETY_DOOR_BIT (1<<CONTROL_SAFETY_DOOR_PIN)
#define CONTROL_MASK            (CONTROL_RESET_BIT|CONTROL_FEED_HOLD_BIT|CONTROL_CYCLE_START_BIT|CONTROL_SAFETY_DOOR_BIT)

// Define probe switch input pin.
#define PROBE_PORT              GPIOB
#define PROBE_PIN               5
#define PROBE_BIT               (1<<PROBE_PIN)

// Define keypad isr
#if KEYPAD_ENABLE
  #define KEYPAD_PORT           GPIOD
  #define KEYPAD_STROBE_PIN     14
  #define KEYPAD_STROBE_BIT     (1<<KEYPAD_STROBE_PIN)
#endif

#endif /* MY_MACHINE_MAP_H_ */

