AUTOMAKE_OPTIONS = foreign

CFLAGS = -Wall -pedantic -O2
CFLAGS += -std=gnu99
CFLAGS += $(OPT)
CFLAGS += -Wextra -Wno-stringop-truncation $(DEBUG) -fPIC
CFLAGS += -DPERIPHERY_VERSION_COMMIT=\"$(COMMIT_ID)\" -DPERIPHERY_GPIO_CDEV_SUPPORT=$(GPIO_CDEV_SUPPORT)

include_HEADERS = pwm.h

lib_LTLIBRARIES = libpwm.la
libbbexample_la_SOURCES  = pwmlib.c
libbbexample_la_LDFLAGS= -version-info 1:0:0

bin_PROGRAMS = app-pwm
bbexample_SOURCES = app-pwm.c
bbexample_LDADD = libpwm.la
