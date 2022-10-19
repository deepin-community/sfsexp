/**

SFSEXP: Small, Fast S-Expression Library version 1.3
Written by Matthew Sottile (mjsottile@gmail.com)

Copyright (2003-2006). The Regents of the University of California. This
material was produced under U.S. Government contract W-7405-ENG-36 for Los
Alamos National Laboratory, which is operated by the University of
California for the U.S. Department of Energy. The U.S. Government has rights
to use, reproduce, and distribute this software. NEITHER THE GOVERNMENT NOR
THE UNIVERSITY MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY
LIABILITY FOR THE USE OF THIS SOFTWARE. If software is modified to produce
derivative works, such modified software should be clearly marked, so as not
to confuse it with the version available from LANL.

Additionally, this library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation; either version 2.1 of the
License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, U SA

LA-CC-04-094

**/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "sexp.h"

int main(int argc, char **argv) {
	char foo[8192];
	char buf[4096];
	sexp_t *sx = NULL;
        int fd,len;

	fd = open("conttest",O_RDONLY);
	len = -1;

	while (len != 0) {
	  len = read(fd,foo,8192);
	  foo[len] = '\0';
          sx = parse_sexp(foo,8192);
            print_sexp(buf,4096,sx);
	    printf("\n\n%s\n",buf);
	    destroy_sexp(sx);
        }

        sexp_cleanup();

	close(fd);

	return 0;
}
