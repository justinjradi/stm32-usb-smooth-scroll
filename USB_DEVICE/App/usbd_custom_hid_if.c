/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @version        : v1.0_Cube
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
ResMultiplierReport resMultiplierReport = {0};
/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device.
  * @{
  */

/** @addtogroup USBD_CUSTOM_HID
  * @{
  */

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions USBD_CUSTOM_HID_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Defines USBD_CUSTOM_HID_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Macros USBD_CUSTOM_HID_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Variables USBD_CUSTOM_HID_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
  /* USER CODE BEGIN 0 */
		0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
		0x09, 0x02,        // Usage (Mouse)
		0xA1, 0x01,        // Collection (Application)
		0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
		0x09, 0x02,        //   Usage (Mouse)
		0xA1, 0x02,        //   Collection (Logical)
		0x85, REPORTID_MOUSE,  //     Report ID (REPORTID_MOUSE)
		0x09, 0x01,        //     Usage (Pointer)
		0xA1, 0x00,        //     Collection (Physical)
		0x05, 0x09,        //       Usage Page (Button)
		0x19, 0x01,        //       Usage Minimum (0x01)
		0x29, 0x05,        //       Usage Maximum (0x05)
		0x15, 0x00,        //       Logical Minimum (0)
		0x25, 0x01,        //       Logical Maximum (1)
		0x95, 0x05,        //       Report Count (5)
		0x75, 0x01,        //       Report Size (1)
		0x81, 0x02,        //       Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
		0x95, 0x01,        //       Report Count (1)
		0x75, 0x03,        //       Report Size (3)
		0x81, 0x01,        //       Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
		0x05, 0x01,        //       Usage Page (Generic Desktop Ctrls)
		0x09, 0x30,        //       Usage (X)
		0x09, 0x31,        //       Usage (Y)
		0x95, 0x02,        //       Report Count (2)
    0x75, 0x08,                    //       REPORT_SIZE (8)
    0x15, 0x81,                    //       LOGICAL_MINIMUM (-127)
    0x25, 0x7f,                    //       LOGICAL_MAXIMUM (127)
		0x81, 0x06,        //       Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
		0xA1, 0x02,        //       Collection (Logical)
		0x85, REPORTID_RES_MULTIPLIER, //         Report ID (REPORTID_RES_MULTIPLIER)
		0x09, 0x48,        //         Usage (Resolution Multiplier)
		0x95, 0x01,        //         Report Count (1)
		0x75, 0x02,        //         Report Size (2)
		0x15, 0x00,        //         Logical Minimum (0)
		0x25, 0x01,        //         Logical Maximum (1)
		0x35, 0x01,        //         Physical Minimum (1)
		0x45, MAX_SCROLL_RES,   //         Physical Maximum (MAX_SCROLL_RES)
		0xB1, 0x02,        //         Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
		0x85, REPORTID_MOUSE,  //         Report ID (REPORTID_MOUSE)
		0x09, 0x38,        //         Usage (Wheel)
		0x35, 0x00,        //         Physical Minimum (0)
		0x45, 0x00,        //         Physical Maximum (0)
		0x95, 0x01,        //         Report Count (1)
    0x75, 0x08,                    //       REPORT_SIZE (8)
    0x15, 0x81,                    //       LOGICAL_MINIMUM (-127)
    0x25, 0x7f,                    //       LOGICAL_MAXIMUM (127)
		0x81, 0x06,        //         Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
		0xC0,              //       End Collection
		0xA1, 0x02,        //       Collection (Logical)
		0x85, REPORTID_RES_MULTIPLIER, //         Report ID (REPORTID_RES_MULTIPLIER)
		0x09, 0x48,        //         Usage (0x48)
		0x95, 0x01,        //         Report Count (1)
		0x75, 0x02,        //         Report Size (2)
		0x15, 0x00,        //         Logical Minimum (0)
		0x25, 0x01,        //         Logical Maximum (1)
		0x35, 0x01,        //         Physical Minimum (1)
		0x45, MAX_PAN_RES,        //         Physical Maximum (MAX_PAN_RES)
		0xB1, 0x02,        //         Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
		0x35, 0x00,        //         Physical Minimum (0)
		0x45, 0x00,        //         Physical Maximum (0)
		0x75, 0x04,        //         Report Size (4)
		0xB1, 0x01,        //         Feature (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
		0x85, 0x01,        //         Report ID (1)
		0x05, 0x0C,        //         Usage Page (Consumer)
		0x0A, 0x38, 0x02,  //         Usage (AC Pan)
		0x95, 0x01,        //         Report Count (1)
    0x75, 0x08,                    //       REPORT_SIZE (8)
    0x15, 0x81,                    //       LOGICAL_MINIMUM (-127)
    0x25, 0x7f,                    //       LOGICAL_MAXIMUM (127)
		0x81, 0x06,        //         Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
		0xC0,              //       End Collection
		0xC0,              //     End Collection
		0xC0,              //   End Collection
  /* USER CODE END 0 */
  0xC0    /*     END_COLLECTION	             */
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_Init_FS(void);
static int8_t CUSTOM_HID_DeInit_FS(void);
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t report_ID, uint8_t data);
uint8_t getScrollRes(void);
uint8_t getPanRes(void);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS =
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */
  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Manage the CUSTOM HID class events
  * @param  event_idx: Event index
  * @param  state: Event state
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t report_ID, uint8_t data)
{
  /* USER CODE BEGIN 6 */

	if (report_ID == REPORTID_RES_MULTIPLIER)
	{
		resMultiplierReport.scroll_resolution = data & 0x00000011;
		resMultiplierReport.pan_resolution = data & 0x00001100;
	}

  /* Start next USB packet transfer once data processing is completed */
  if (USBD_CUSTOM_HID_ReceivePacket(&hUsbDeviceFS) != (uint8_t)USBD_OK)
  {
    return -1;
  }
  return (USBD_OK);
  /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
}
*/
/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */
uint8_t getScrollRes(void)
{
	return resMultiplierReport.scroll_resolution;
}
uint8_t getPanRes(void)
{
	return resMultiplierReport.pan_resolution;
}
/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

