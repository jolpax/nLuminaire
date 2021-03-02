AUTOMAKE_OPTIONS = foreign

CFLAGS = -Wall -pedantic -O2
CFLAGS += -std=gnu99
CFLAGS += $(OPT)
CFLAGS += -Wextra -Wno-stringop-truncation $(DEBUG) -fPIC


include_HEADERS = pwm.h
include_HEADERS += bbexample.h
include_HEADERS += libsocketcan.h
include_HEADERS += can_netlink.h



lib_LTLIBRARIES = libpwm.la
libpwm_la_SOURCES = pwmlib.c
libpwm_la_SOURCES += bbexamplelib.c
libpwm_la_SOURCES += libsocketcan.c

libpwm_la_LDFLAGS= -version-info 1:1:0

bin_PROGRAMS = apppwm comapps0 comapps1 comappscan0 comappscan1 cantx
apppwm_SOURCES = apppwm.c
cantx_SOURCES = cantx.c
comapps0_SOURCES = comapps0.c
comapps1_SOURCES = comapps1.c
comappscan0_SOURCES = comappscan0.c
comappscan1_SOURCES = comappscan1.c

apppwm_LDADD = libpwm.la
comappscan0_LDADD = libpwm.la


