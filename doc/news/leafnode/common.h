/*
 * (C) Maint Laboratory 2003
 * Author: Elohin Igor
 * e-mail: maint@unona.ru
 * fido  : 2:5070/222.52
 * URL   : http://maint.unona.ru
 */
#define BUFSIZE 512
#ifndef TRUE
 #define TRUE  1
 #define FALSE 0
#endif

#define OUTGOING "/var/spool/leafnode/out.going"
#define FAILED_POSTING "/var/spool/leafnode/failed.postings"
#define IN_COMING "/var/spool/leafnode/in.coming"
#define DUPE_POST "/var/spool/leafnode/dupe.post"
#define INTERESTING_GROUPS "/var/spool/leafnode/interesting.groups"
#define GROUPINFO "/var/spool/leafnode/leaf.node/groupinfo"
#define LOCAL_GROUPINFO "/usr/local/etc/leafnode/local.groups"
#define ACTIVE "/var/spool/leafnode/leaf.node/active"
#define RFC2FTN  "/usr/local/fidogate/libexec/rfc2ftn -n -v"
#define DELETE_CTRL_D  "/usr/local/fidogate/leafnode/ctrld" // ������ Ctrl+D � ����� �����, ������� ������ leafnode
#define DIRLOG  "/var/log/fidogate"
#define NEWSLOGDIR  "/var/log/leafnode"
#define MSGBUF 512
#define LEAFNODE_OWNER "news"
#define LOGNAME "leafnode"

void loginit(char *, char *);
void logclose(void);
void error(const char *fmt, ...);
void message(const char *fmt, ...);
void notice(const char *fmt, ...);
void dolog(int flag, const char *fmt, ...);
void die(int);
void put_server(char *);
int get_server(char *);
char *get_line(char *);
void putaline(const char *fmt, ...);
char *diagtime(void);

