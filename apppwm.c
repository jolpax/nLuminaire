#include <stdio.h>
#include <stdlib.h>

#include "pwm.h"
#include "bbexample.h"

#include "nluminaire.h"
    pwm_t *pwm;

    double pulse = 0;
    double prevpulse = 0;
    
    

int main(void) {

    pwm = pwm_new();

    printf("Cabsy Luminaire Started!!!\n");
    LibHelloWorld();

    /* Open PWM chip 0, channel 10 */
    if (pwm_open(pwm, 0, 3) < 0) {
        fprintf(stderr, "pwm_open(): %s\n", pwm_errmsg(pwm));
        exit(1);
    }

    /* Set frequency to 1 kHz */
    if (pwm_set_frequency(pwm, 10000) < 0) {
        fprintf(stderr, "pwm_set_frequency(): %s\n", pwm_errmsg(pwm));
        exit(1);
    }

    /* Set duty cycle to 75% */
    if (pwm_set_duty_cycle(pwm, 0.5) < 0) {
        fprintf(stderr, "pwm_set_duty_cycle(): %s\n", pwm_errmsg(pwm));
        exit(1);
    }

    /* Enable PWM */
    if (pwm_enable(pwm) < 0) {
        fprintf(stderr, "pwm_enable(): %s\n", pwm_errmsg(pwm));
        exit(1);
    }

    

    while (1)
    {

        pulse = (nData.swtx[2]/471);


        if(prevpulse != pulse)
            {
                if (pwm_set_duty_cycle(pwm, pulse) < 0) 
                    {
                    fprintf(stderr, "pwm_set_duty_cycle(): %s\n", pwm_errmsg(pwm));
                    exit(1);
                    }
                prevpulse = pulse;           
            }
      
    }

    //pwm_close(pwm);

    //pwm_free(pwm);

    return 0;
}

