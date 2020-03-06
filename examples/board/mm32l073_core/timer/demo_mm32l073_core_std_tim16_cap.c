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
 * \brief TIM16 ��ʱ�� CAP ���̣�ͨ����׼�ӿ�ʵ��
 *
 * - �������裺
 *   1. ʹ�öŰ��ߣ��� PIOA_0 �� PIOA_6 ���ӡ�
 *
 * - ʵ������
 *   1. TIM2 ͨ�� PIOA_0 ������� 2KHz �� PWM��
 *   2. TIM16 ��������ͨ�� 1 ʹ�� PIOA_6 ���Ų���
 *   3. ���ڴ�ӡ�����ò����ܵõ��� PWM �źŵ����ں�Ƶ�ʡ�
 *
 * \note
 *    1. ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOA_9 �������� PC ���ڵ� RXD��
 *    2. ���� TIM16 Ĭ�ϳ�ʼ������Ϊ������ PWM ʹ�ã�ʹ�ñ� Demo ֮ǰ������
 *       am_prj_config.h �ڽ� AM_CFG_BUZZER_ENABLE ����Ϊ 0��
 *
 * \par Դ����
 * \snippet demo_mm32l073_core_std_tim16_cap.c src_mm32l073_core_std_tim16_cap
 *
 * \internal
 * \par Modification history
 * - 1.00 16-04-22  nwt, first implementation
 * \endinternal
 */ 

/**
 * \addtogroup demo_if_mm32l073_core_std_tim16_cap
 * \copydoc demo_mm32l073_core_std_tim16_cap.c
 */

/** [src_mm32l073_core_std_tim16_cap] */
#include "ametal.h"
#include "am_pwm.h"
#include "am_vdebug.h"
#include "am_mm32l073_inst_init.h"
#include "demo_std_entries.h"
#include "demo_mm32l073_core_entries.h"

/**
 * \brief �������
 */
void demo_mm32l073_core_std_tim16_cap_entry (void)
{
    am_pwm_handle_t pwm_handle = am_mm32l073_tim2_pwm_inst_init();

    AM_DBG_INFO("demo mm32l073_core std tim16 cap!\r\n");

    /* TIM2 ���Ƶ��Ϊ 2KHz �� PWM */
    am_pwm_config(pwm_handle, 0, 500000 / 2, 500000);
    am_pwm_enable(pwm_handle, 0);

    demo_std_timer_cap_entry(am_mm32l073_tim16_cap_inst_init(), 0);
}
/** [src_mm32l073_core_std_tim16_cap] */

/* end of file */