/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief ARM LIB
 *
 * \internal
 * \par Modification History
 * - 1.00 17-08-17  pea, first implementation.
 * \endinternal
 */

#ifndef __MICROLIB

#include "ametal.h"
#include "am_bsp_armlib.h"
#include "am_armlib_adapter.h"

/**
 * \brief ���һ���ַ�
 *
 * \param[in] p_arg UART��׼����������
 * \param[in] ch    ��Ҫ������ַ�
 *
 * \return ��������ַ�
 */
static int __dbg_fputc (void *p_arg, const char ch)
{
    while (-AM_EAGAIN == am_uart_poll_putchar(p_arg, ch)) {
        ;
    }

    return ch;
}

/**
 * \brief ����һ���ַ�
 *
 * \param[in] p_arg UART��׼����������
 *
 * \return ������ַ������򷵻�EOF
 */
static int __dbg_fgetc (void *p_arg)
{
    char ch;

    while (-AM_EAGAIN == am_uart_poll_getchar(p_arg, &ch)) {
        ;
    }

    return ch;
}

/**
 * \brief ��ʼ��ARM LIB�������ṹ
 */
static am_armlib_adapter_ops_t g_armlib_adapter_ops = {
    __dbg_fputc,
    __dbg_fgetc
};

/**
 * \brief ARM LIB��ʼ��
 *
 * \param[in] uart_handle UART����
 *
 * \return AM_OK
 */
int am_bsp_armlib_init (am_uart_handle_t uart_handle)
{
    return am_armlib_adapter_init(&g_armlib_adapter_ops, uart_handle);
}

#endif /* __MICROLIB */

/* end of file */