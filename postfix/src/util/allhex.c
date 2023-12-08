/*++
/* NAME
/*	allhex 3
/* SUMMARY
/*	predicate if string is all hexadecimal
/* SYNOPSIS
/*	#include <stringops.h>
/*
/*	int	allhex(buffer)
/*	const char *buffer;
/*
/*	int	allhex_len(buffer, len)
/*	const char *buffer;
/*	ssize_t	len;
/* DESCRIPTION
/*	allhex_len() determines if its argument is an all-hexadecimal
/*	string.
/*
/*	allhex() is a convenience wrapper for null-terminated
/*	strings.
/*
/*	Arguments:
/* .IP buffer
/*	The null-terminated input string.
/* .IP len
/*	The string length, -1 to determine the length dynamically.
/* LICENSE
/* .ad
/* .fi
/*	The Secure Mailer license must be distributed with this software.
/* AUTHOR(S)
/*	Wietse Venema
/*	IBM T.J. Watson Research
/*	P.O. Box 704
/*	Yorktown Heights, NY 10598, USA
/*
/*	Wietse Venema
/*	Google, Inc.
/*	111 8th Avenue
/*	New York, NY 10011, USA
/*--*/

/* System library. */

#include <sys_defs.h>
#include <ctype.h>
#include <string.h>

/* Utility library. */

#include "stringops.h"

/* allhex_len - return true if string is all hex */

int     allhex_len(const char *string, ssize_t len)
{
    const char *cp;
    int     ch;

    if (len < 0)
	len = strlen(string);
    if (len == 0)
	return (0);
    for (cp = string; cp < string + len
	 && (ch = *(unsigned char *) cp) != 0; cp++)
	if (!ISXDIGIT(ch))
	    return (0);
    return (1);
}
