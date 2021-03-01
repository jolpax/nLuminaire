AUTOMAKE_OPTIONS = foreign

CFLAGS = -Wall -pedantic -O2
CFLAGS += -std=gnu99
CFLAGS += $(OPT)
CFLAGS += -Wextra -Wno-stringop-truncation $(DEBUG) -fPIC


include_HEADERS = pwm.h
include_HEADERS += bbexample.h


lib_LTLIBRARIES = libpwm.la
libpwm_la_SOURCES  = pwmlib.c
libpwm_la_SOURCES  += bbexamplelib.c
libpwm_la_LDFLAGS= -version-info 1:0:0

bin_PROGRAMS = apppwm
apppwm_SOURCES = apppwm.c
apppwm_LDADD = libpwm.la
