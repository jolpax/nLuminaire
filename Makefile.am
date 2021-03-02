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

bin_PROGRAMS = apppwm comapps0 comapps1 comappscan0 comappscan1
apppwm_SOURCES = apppwm.c
comapps0_SOURCES = comapps0.c
comapps1_SOURCES = comapps1.c
comappscan0_SOURCES = comappscan0.c
comappscan1_SOURCES = comappscan1.c

apppwm_LDADD = libpwm.la
