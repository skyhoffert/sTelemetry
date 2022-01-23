# Filename: Makefile
# Description: Makefile for sTelemetry library.
# Revision: RevA
# Release Date: 2022-01-22
# Primary Author: Sky Hoffert
# Secondary Author(s): N/A
# Target Audience: Sky Hoffert and similar programmers looking for simple telemetry logging.

LDLIBS=

BINDIR=bin/
INCDIR=include/
LIBDIR=lib/
OBJDIR=obj/
SRCDIR=src/
TESTDIR=test/

CC=gcc
CFLAGS=-fPIC -Wall -I$(INCDIR) -I$(LIBDIR)

TARGETS=\
	$(OBJDIR)temp.o
TESTS=\
	$(BINDIR)s.test \
	$(BINDIR)sLogging.test

all: $(BINDIR)sTelemetry

tests: $(TESTS)

clean:
	$(info Cleaning.)
	rm -rf $(OBJDIR)*.o
	rm -rf $(BINDIR)*

###############################################################################
# Main ACQ2 program is defined below.
###############################################################################

$(BINDIR)sTelemetry: $(TARGETS) $(SRCDIR)sTelemetry.c
	$(info Building sTelemetry.)
	$(CC) $(CFLAGS) -o $(BINDIR)sTelemetry \
		$(SRCDIR)sTelemetry.c \
		$(TARGETS)

###############################################################################
# Object recipes are defined below.
###############################################################################

$(OBJDIR)temp.o: $(SRCDIR)temp.c $(INCDIR)temp.h
	$(info Building temp.)
	$(CC) $(CFLAGS) -o $(OBJDIR)temp.o -c \
		$(SRCDIR)temp.c

###############################################################################
# Test recipes are defined below.
###############################################################################

$(BINDIR)s.test: $(TESTDIR)s.test.c $(LIBDIR)s.h
	$(info Building s test.)
	$(CC) $(CFLAGS) -o $(BINDIR)s.test \
		$(TESTDIR)s.test.c

$(BINDIR)sLogging.test: $(TESTDIR)sLogging.test.c $(LIBDIR)sLogging.h
	$(info Building sLogging test.)
	$(CC) $(CFLAGS) -o $(BINDIR)sLogging.test \
		$(TESTDIR)sLogging.test.c
