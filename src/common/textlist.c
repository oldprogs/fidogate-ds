/*:ts=8*/
/*****************************************************************************
 * FIDOGATE --- Gateway UNIX Mail/News <-> FIDO NetMail/EchoMail
 *
 * $Id: textlist.c,v 5.3 2006/12/28 17:51:39 anray Exp $
 *
 * Store text file as chain of linked text lines in memory
 *
 *****************************************************************************
 * Copyright (C) 1990-2002
 *  _____ _____
 * |     |___  |   Martin Junius             <mj@fidogate.org>
 * | | | |   | |   Radiumstr. 18
 * |_|_|_|@home|   D-51069 Koeln, Germany
 *
 * This file is part of FIDOGATE.
 *
 * FIDOGATE is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * FIDOGATE is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with FIDOGATE; see the file COPYING.  If not, write to the Free
 * Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *****************************************************************************/

#include "fidogate.h"



/*
 * Write Textlist to file
 */
void tl_fput(FILE *fp, Textlist *list)
{
    Textline *p;

    for(p=list->first; p; p=p->next)
	fputs(p->line, fp);

    return;
}



/*
 * tl_add() --- append Textline to Textlist
 */
void tl_add(Textlist *list, Textline *line)
{
    if(list->last)
	list->last->next = line;
    else
	list->first = line;

    line->next = NULL;
    line->prev = list->last;
    
    list->last = line;
    list->n++;
}



/*
 * tl_remove() --- remove Textline from Textlist
 */
void tl_remove(Textlist *list, Textline *line)
{
    if(list->first == line)
	list->first = line->next;
    else
	line->prev->next = line->next;
    
    if(list->last == line)
	list->last = line->prev;
    else
	line->next->prev = line->prev;

    line->next = NULL;
    line->prev = NULL;

    list->n--;
}



/*
 * tl_delete() --- remove Textline from Textlist, delete Textline
 */
void tl_delete(Textlist *list, Textline *line)
{
    tl_remove(list, line);
    xfree(line->line);
    xfree(line);
}



/***** tl_init() --- Initialize structure ******************************/

void tl_init(Textlist *list)
{
    list->first = NULL;
    list->last	= NULL;
    list->n     = 0;
}



/***** tl_clear() --- Delete text lines and chain **********************/

void tl_clear(Textlist *list)
{
    Textline *p, *pn;

    for(p=list->first; p;) {
	pn = p->next;
	xfree(p->line);
	xfree(p);
	p  = pn;
    }
    
    list->first = NULL;
    list->last	= NULL;
    list->n     = 0;
}



/***** tl_append() --- Append string to text line chain ****************/

void tl_append(Textlist *list, char *s)
{
    Textline *p;

    if(!s)
	return;
    
    s = strsave(s);
    p	    = (Textline *)xmalloc(sizeof(Textline));
    p->line = s;
    p->next = NULL;

    tl_add(list, p);
}



/***** tl_appendf() --- Append text to chain, printf like formatting ***/

void tl_appendf(Textlist *list, char *fmt, ...)
{
    static char buf[4096];
    int n;
    va_list args;

    va_start(args, fmt);

#ifndef HAVE_SPRINTF    
    n = vsnprintf(buf, sizeof(buf), fmt, args);
#else
    n = vsprintf(buf, fmt, args);
    if(n >= sizeof(buf))
    {
        fatal("Internal error - tl_appendf() buf overflow", EX_SOFTWARE);
        /**NOT REACHED**/
        return;
    }
#endif
    tl_append(list, (char *)buf);

    va_end(args);
}



/***** tl_print() --- Write text line chain to file ********************/

void tl_print(Textlist *list, FILE *fp)
{
    Textline *p;

    for(p=list->first; p; p=p->next)
	fputs(p->line, fp);

    return;
}



/*
 * Output complete textlist with extra end-of-line
 */
void tl_print_x(Textlist *list, FILE *fp, char *extra)
{
    Textline *p;

    for(p=list->first; p; p=p->next)
    {
	fputs(p->line, fp);
	fputs(extra  , fp);
    }

    return;
}



/***** tl_size() --- Compute size of text in chain *********************/

long tl_size(Textlist *list)
{
    Textline *p;
    long n=0;

    for(p=list->first; p; p=p->next)
	n += strlen(p->line);

    return n;
}



/***** tl_add() --- Add another textlist ******************************/

void tl_addtl(Textlist *d, Textlist *s)
{
    Textline *p;

    for(p=s->first; p; p=p->next)
	tl_append(d, p->line);
}

Textline* tl_get(Textlist *list, char *str, int len)
{
    Textline *p = NULL;
    
    for(p = list->first; p != NULL; p = p->next)
    {
	if(len == 0)
	{
	     if(stricmp(p->line, str) == 0)
		break;
	}
	else
	{
	    if(strnicmp(p->line, str, len) == 0)
		break;
	}
    }
    return p;
}
	
char* tl_get_str(Textlist *list, char *str, int len)
{
    Textline *p;
    char *new_str = NULL;
  
    p = tl_get(list, str, len);
    if(p != NULL)
	new_str = strsave(p->line);
    return new_str;
}

int tl_copy(Textlist *dst, Textlist *src)
{
    Textline *p;

    for(p = src->first; p != NULL; p = p->next)
	tl_append(dst, p->line);
    return OK;
}
