
#include "cyhal.h"
#include "cybsp.h"


// Timer interrupt handler
void timer_interrupt_handler(void)
{
	// Clear the interrupt status
	Cy_TCPWM_ClearInterrupt(TCPWM0, tcpwm_0_cnt_0_NUM, CY_TCPWM_INT_ON_CC);
    // Toggle the LED state
    Cy_GPIO_Inv(CYBSP_USER_LED_PORT, CYBSP_USER_LED_NUM);

}

int main(void)
{
    cy_rslt_t result;

#if defined (CY_DEVICE_SECURE)
    cyhal_wdt_t wdt_obj;

    /* Clear watchdog timer so that it doesn't trigger a reset */
    result = cyhal_wdt_init(&wdt_obj, cyhal_wdt_get_max_timeout_ms());
    CY_ASSERT(CY_RSLT_SUCCESS == result);
    cyhal_wdt_free(&wdt_obj);
#endif

    /* Initialize the device and board peripherals */
    result = cybsp_init();

    /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Enable global interrupts */
      __enable_irq();

    Cy_GPIO_Pin_Init(CYBSP_LED8_PORT, CYBSP_LED8_PIN, &CYBSP_LED8_config);

    // Attach the interrupt handler
    cy_stc_sysint_t irqcfg = {tcpwm_0_cnt_0_IRQ,3}; //Configure the interrupt with priority 3

       result = Cy_SysInt_Init(&irqcfg, timer_interrupt_handler);

       if(result != CY_SYSINT_SUCCESS)
           {
               CY_ASSERT(0);
           }
       NVIC_ClearPendingIRQ(tcpwm_0_cnt_0_IRQ);
        NVIC_EnableIRQ(irqcfg.intrSrc);

       result = Cy_TCPWM_Counter_Init(TCPWM0, tcpwm_0_cnt_0_NUM, &tcpwm_0_cnt_0_config);

       if(result != CY_TCPWM_SUCCESS){
             CY_ASSERT(0);
         }
       /* Enable the initialized counter */
        Cy_TCPWM_Counter_Enable(TCPWM0, tcpwm_0_cnt_0_NUM);

         Cy_TCPWM_TriggerStart(TCPWM0, tcpwm_0_cnt_0_MASK);


}

/* [] END OF FILE */
