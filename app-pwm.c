#include <stdio.h>
#include <stdlib.h>

#include "pwm.h"


int main(void) {
    pwm_t *pwm;

    pwm = pwm_new();
    
    printf("Hello, World!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

    /* Open PWM chip 0, channel 10 */
    if (pwm_open(pwm, 0, 10) < 0) {
        fprintf(stderr, "pwm_open(): %s\n", pwm_errmsg(pwm));
        exit(1);
    }

    /* Set frequency to 1 kHz */
    if (pwm_set_frequency(pwm, 1e3) < 0) {
        fprintf(stderr, "pwm_set_frequency(): %s\n", pwm_errmsg(pwm));
        exit(1);
    }

    /* Set duty cycle to 75% */
    if (pwm_set_duty_cycle(pwm, 0.75) < 0) {
        fprintf(stderr, "pwm_set_duty_cycle(): %s\n", pwm_errmsg(pwm));
        exit(1);
    }

    /* Enable PWM */
    if (pwm_enable(pwm) < 0) {
        fprintf(stderr, "pwm_enable(): %s\n", pwm_errmsg(pwm));
        exit(1);
    }

    /* Change duty cycle to 50% */
    if (pwm_set_duty_cycle(pwm, 0.50) < 0) {
        fprintf(stderr, "pwm_set_duty_cycle(): %s\n", pwm_errmsg(pwm));
        exit(1);
    }

    pwm_close(pwm);

    pwm_free(pwm);

    return 0;
}
