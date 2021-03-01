AUTOMAKE_OPTIONS = foreign

CFLAGS = -Wall -pedantic -O2
include_HEADERS = pwm.h

lib_LTLIBRARIES = libpwm.la
libbbexample_la_SOURCES  = pwmlib.c
libbbexample_la_LDFLAGS= -version-info 1:0:0

bin_PROGRAMS = app-pwm
bbexample_SOURCES = app-pwm.c
bbexample_LDADD = libpwm.la
