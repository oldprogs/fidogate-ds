��������! ��� - ������������� ������. ���������� ����� ����� �����:
  cvs -z3 -d:pserver:anonymous@cvs.rusfidogate.sourceforge.net:/cvsroot/rusfidogate \
  co fidogate-sta

Version 5.2.0ds-alpha2
~~~~~~~~~~~~~~~~~~~~~~
- ���� �������� AF_AVAIL, �� ������� ��������� %avail �������� ����� ���
  � %listall. ���� AF_AVAIL �������, �� �������� ������ ����� - %avail
  ������� ������ AvailFile.
- ��������� ����� configure --whith-netmaildir, � ������� ������� �����
  �������� �����������, ���� ������������ ������� ��� ����������
  --enable-dnt-netmail. �� ��������� ��� /var/spool/fido/bt/netmail.
  ����� �� ����� �������� � fidogate.conf - NETMAILDIR.
- ������ ��� ��������� NoRfcKludge ftn2rfc �� ���������� RFC-Message-ID �
  Message-ID � Message-ID ������������ ������. ������ �� ORIGID ��� ���������
  �� MSGID.
- ����� ����� OLD_COMMENT_TO. ���� �� ��������, �� � ������������ ��������
  � ��������� X-Comment-To: �� �������� ������.

Version 5.2.0ds-alpha1
~~~~~~~~~~~~~~~~~~~~~~
- ����� ����� INSERT_ORIGIN. ���� �� �������, �� ���� �� �������� �������-
  ������ �� ���� ������ '* Origin', ����������� ������ � ������� �����,
  �� �������� ������ ���� �����(������ ���������). �� ��������� ��������,
  �.�. ������ �������� � verbose �� ���������� �������.
- ����� ���� ��������� ������ � runinc '-c', � ������� �������� ����� 
  ��������� ������������ ��������� �������.
- ����� ���� � passwd ��� ��������� '$' - �������� ���. ���������������
  �������� � ������ '&'.
- ��� ���������� ftn2rfc ���� � �������� ��������� ������ �������, �� � Organization
  ������� '(none)'.

Version 5.1.0ds-beta2
~~~~~~~~~~~~~~~~~~~~~
- ���� ������� �� �������� ��������� ������ � ������� NOINSERT_ORGANIZATION,
  �� ��� ���������� � Organization ����������� '(none)'
- ������ ����� DEFAULT_OUTNETMAIL
- ��������� ������� ��� exim4
- � ��������� charset ��������� ���������� map-�.

Version 5.1.0ds-beta1
~~~~~~~~~~~~~~~~~~~~~
- ��� EchoGateAlias ����� � MSGID ������������� �� �����, � ������� ��
  aliases.
- ftnafutil delete ������� �� ������ ��� ��� ������, �� ��� � �������
  ������ 'U'.
- ��������� leafnode-util �� Elohin Igor
- ���������� ������ confval - ������ �� ��� ������� ��� ������ ����������
  ��� ������ � �������.
