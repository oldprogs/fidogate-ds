#:ts=8
#
#    $Id: Makefile.am,v 1.1 2003/09/23 17:36:36 rusfidogate Exp $
#
#    Makefile for FIDOGATE scripts/filebase/
#

bin_SCRIPTS	=	logcheck \
			logdaily \
			logreport \
			logsendmail \
			logstat \
			runchklock

noinst_SCRIPT	=	fidogate.logrotate \
			rc.fidogate

$(bin_SCRIPTS) $(noinst_SCRIPTS):
	$(SUBSTCMD) $@.in > $@
	chmod +x $@

clean-am:
	rm -f $(bin_SCRIPTS) $(noinst_SCRIPTS)
