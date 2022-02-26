/**
 ******************************************************************************
 * @file main.h
 * @date Feb 23, 2022
 * @author Kunal Verma
 * @details This file contains macros and function declarations for main.c
 ******************************************************************************
 */

#ifndef MAIN_H_
#define MAIN_H_

#define MAX_TASKS   5   //Total number of tasks in the system including Idle Task

/* some stack memory calculations */
#define SIZE_TASK_STACK          1024U   //Stack size allocated per task
#define SIZE_SCHED_STACK         1024U   //Stack size allocated to scheduler task

#define SRAM_START               0x20000000U   //Starting address of SRAM
#define SIZE_SRAM                ( (20) * (1024))   //Size of SRAM of STM32F103C8Tx
#define SRAM_END                 ((SRAM_START) + (SIZE_SRAM) )

//Stack sizes for various are allocated from SRAM and starts from top of SRAM

#define T1_STACK_START           SRAM_END
#define T2_STACK_START           ( (SRAM_END) - (1 * SIZE_TASK_STACK) )
#define T3_STACK_START           ( (SRAM_END) - (2 * SIZE_TASK_STACK) )
#define T4_STACK_START           ( (SRAM_END) - (3 * SIZE_TASK_STACK) )
#define IDLE_STACK_START         ( (SRAM_END) - (4 * SIZE_TASK_STACK) )
#define SCHED_STACK_START        ( (SRAM_END) - (5 * SIZE_TASK_STACK) )

#define TICK_HZ 1000U

#define HSI_CLOCK         		8000000U  //High-speed Internal Clock
#define SYSTICK_TIM_CLK   		HSI_CLOCK


#define DUMMY_XPSR  0x01000000U

#define TASK_READY_STATE    0x00
#define TASK_BLOCKED_STATE  0XFF

//Disable Interrupts
#define INTERRUPT_DISABLE()  do{__asm volatile ("MOV R0,#0x1"); asm volatile("MSR PRIMASK,R0"); } while(0)

//Enable Interrupts
#define INTERRUPT_ENABLE()  do{__asm volatile ("MOV R0,#0x0"); asm volatile("MSR PRIMASK,R0"); } while(0)

/* task handler function prototypes */
void task1_handler(void); //This is task1
void task2_handler(void); //this is task2
void task3_handler(void); //this is task3
void task4_handler(void); // this is task4 of the application


void init_systick_timer(uint32_t tick_hz);  //Initializes the Systick Timer
__attribute__((naked)) void init_scheduler_stack(uint32_t sched_top_of_stack); //Initializes the Scheduler Stack
void init_tasks_stack(void);
void enable_processor_faults(void);
__attribute__((naked)) void switch_sp_to_psp(void); //Switch from Main Stack pointer to Program Stack pointer
uint32_t get_psp_value(void);

void task_delay(uint32_t tick_count);

#endif /* MAIN_H_ */
