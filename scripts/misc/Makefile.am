#:ts=8
#
#    $Id: Makefile.am,v 1.1 2003/09/23 17:37:01 rusfidogate Exp $
#
#    Makefile for FIDOGATE scripts/misc/
#

bin_SCRIPTS	=	hosts2dns \
			recvuu \
			senduu \
			senduumail

$(bin_SCRIPTS) $(noinst_SCRIPTS):
	$(SUBSTCMD) $@.in > $@
	chmod +x $@

clean-am:
	rm -f $(bin_SCRIPTS) $(noinst_SCRIPTS)

