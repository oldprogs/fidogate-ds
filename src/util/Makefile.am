#:ts=8
#
#    $Id: Makefile.am,v 5.2 2004/11/23 00:50:41 anray Exp $
#
#    Makefile for FIDOGATE src/util/
#

INCLUDES		= -I$(top_srcdir)/src/include

if enable_static
LDADD			= $(top_srcdir)/src/common/libfidogate.a
else
LDADD			= $(top_srcdir)/src/common/libfidogate.la
endif

AM_CFLAGS		= -Wall

bin_PROGRAMS		= ftnfattach sumcrc ftnoutpkt pktdebug
libexec_PROGRAMS	= confval ftnflo
bin_SCRIPTS		= pktmore

pktmore:
	$(SUBSTCMD) $@.in > $@
	chmod +x $@

clean-am:
	rm -f pktmore
