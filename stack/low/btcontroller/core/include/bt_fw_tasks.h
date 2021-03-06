/***************************************************************************
 Copyright (C) MindTree Ltd.
 This module is a confidential and proprietary property of MindTree and
 a possession or use of this module requires written permission of MindTree.
 ***************************************************************************/

#ifndef __BT_FW_TASKS_H__
#define __BT_FW_TASKS_H__

typedef enum
{
    ISR_EXTENDED_TASK_PRI = 0,
#ifndef USE_FREERTOS
    TIMER_TASK_PRI,
#endif
    LC_RX_TASK_PRI,
    HCI_TD_TASK_PRI,
    HCI_EVENT_TASK_PRI,
    LC_TX_TASK_PRI,
    LMP_TASK_PRI,
    HCI_CMD_TASK_PRI,    
    CH_AS_TASK_PRI,
#ifdef _ENABLE_MAILBOX_
    MAILBOX_TASK_PRI,
#endif
#if defined(ENABLE_LOGGER)
    LOGGER_TASK_PRI,
#endif
#ifdef _ENABLE_MWS_COEX_
    MWS_TASK_PRI,
#endif
    OS_TOTAL_TASKS
}BT_FW_TASKS_PRIORITY;

/* Task Names */
#define ISR_EXTENDED_TASK_NAME  "tISR_EXTENDED"
#ifndef USE_FREERTOS
#define TIMER_TASK_NAME         "tTimer"
#endif
#define LC_RX_TASK_NAME         "tLC_RX"
#define LC_TX_TASK_NAME         "tLC_TX"
#define LMP_TASK_NAME           "tLMP"
#define HCI_CMD_TASK_NAME       "tHCI_CMD"
#define HCI_EVENT_TASK_NAME     "tHCI_EVT"
#define HCI_TD_TASK_NAME        "tHCI_TD"
#define LMP_CH_TASK_NAME        "tLMP_CH"
#if defined(ENABLE_LOGGER)
#define LOGGER_TASK_NAME        "tLogger"
#endif
#ifdef _ENABLE_MAILBOX_
#define MAILBOX_TASK_NAME       "tMailbox"
#endif

/* These define the task's queue size in units */
#define ISR_EXTENDED_TASK_Q_SIZE 5
#ifdef USE_FREERTOS
#define TIMER_TASK_Q_SIZE        0
#else
#define TIMER_TASK_Q_SIZE        20
#endif
#define LC_RX_TASK_Q_SIZE        20
#define LC_TX_TASK_Q_SIZE        30 //if DHKey is generated by hw, we can reduce it.
#ifndef _SSP_DHKEY_CALCULATE_NEW_FLOW_ 
//#define LMP_TASK_Q_SIZE          35 //if DHKey is generated by hw, we can reduce it.
//#define LMP_TASK_Q_SIZE          45 // Dape increased the value for LE + Legacy Encryption.
#define LMP_TASK_Q_SIZE          55 // 20120814:Dape increased the value for LE + Legacy Encryption.
#else
#define LMP_TASK_Q_SIZE          30
#endif
#define HCI_CMD_TASK_Q_SIZE      20
#define HCI_EVENT_TASK_Q_SIZE    20
#define HCI_TD_TASK_Q_SIZE       20
#define CH_AS_TASK_Q_SIZE        10
#if defined(ENABLE_LOGGER)
#define LOGGER_TASK_Q_SIZE       10
#else
#define LOGGER_TASK_Q_SIZE        0
#endif
#ifdef _ENABLE_MAILBOX_
#define MAILBOX_TASK_Q_SIZE       10
#else
#define MAILBOX_TASK_Q_SIZE       0
#endif

#define BT_FW_TASK_Q_HEAP_REQ  \
        (TIMER_TASK_Q_SIZE*OS_Q_ITEM_SIZE)+ \
        (LC_RX_TASK_Q_SIZE*OS_Q_ITEM_SIZE)+ \
        (LC_TX_TASK_Q_SIZE*OS_Q_ITEM_SIZE)+ \
        (LMP_TASK_Q_SIZE*OS_Q_ITEM_SIZE)+ \
        (HCI_CMD_TASK_Q_SIZE*OS_Q_ITEM_SIZE)+ \
        (HCI_EVENT_TASK_Q_SIZE*OS_Q_ITEM_SIZE)+ \
        (HCI_TD_TASK_Q_SIZE*OS_Q_ITEM_SIZE)+ \
        (CH_AS_TASK_Q_SIZE*OS_Q_ITEM_SIZE)+ \
        (LOGGER_TASK_Q_SIZE*OS_Q_ITEM_SIZE)+ \
        (MAILBOX_TASK_Q_SIZE*OS_Q_ITEM_SIZE) + \
        (ISR_EXTENDED_TASK_Q_SIZE*OS_Q_ITEM_SIZE) + (4*11)
        
/* These define the task's busy period in milli seconds */
#define ISR_EXTENDED_TASK_BUSY_PERIOD 5
#define TIMER_TASK_BUSY_PERIOD        5
#define LC_RX_TASK_BUSY_PERIOD        5
#define LC_TX_TASK_BUSY_PERIOD        5
#define LMP_TASK_BUSY_PERIOD          5
#define HCI_CMD_TASK_BUSY_PERIOD      5
#define HCI_EVENT_TASK_BUSY_PERIOD    5
#define HCI_TD_TASK_BUSY_PERIOD       5
#define CH_AS_TASK_BUSY_PERIOD        5
#define LOGGER_TASK_BUSY_PERIOD       5
#ifdef _ENABLE_MAILBOX_
#define NAILBOX_TASK_BUSY_PERIOD      5
#else
#define NAILBOX_TASK_BUSY_PERIOD      0
#endif

#endif /* __BT_FW_TASKS_H__ */

