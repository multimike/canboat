#
# (C) 2009-2015, Kees Verruijt, Harlingen, The Netherlands.
#
# This file is part of CANboat.
#
# CANboat is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# CANboat is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with CANboat.  If not, see <http://www.gnu.org/licenses/>.
#

PLATFORM=$(shell uname | tr '[A-Z]' '[a-z]')-$(shell uname -m)
TARGETDIR=../rel/$(PLATFORM)
ANALYZER=$(TARGETDIR)/analyzer
TARGETS=$(ANALYZER)
XMLFILE=pgns.xml
JSONFILE=pgns.json
NGTXMLFILE=pgns-ngt.xml
NGTJSONFILE=pgns-ngt.json
IKXMLFILE=pgns-ik.xml
IKJSONFILE=pgns-ik.json

CFLAGS?=-Wall -O2

all: $(TARGETS)

$(ANALYZER): analyzer.c pgn.c analyzer.h pgn.h ../common/common.c ../common/common.h ../common/license.h Makefile
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $(ANALYZER) -I../common pgn.c analyzer.c ../common/common.c $(LDLIBS$(LDLIBS-$(@)))

json: $(ANALYZER) pgns2json.xslt
	$(ANALYZER) -explain-xml >$(XMLFILE) && xsltproc pgns2json.xslt $(XMLFILE) >$(JSONFILE)
	$(ANALYZER) -explain-ngt-xml >$(NGTXMLFILE) && xsltproc pgns2json.xslt $(NGTXMLFILE) >$(NGTJSONFILE)
	$(ANALYZER) -explain-ik-xml >$(IKXMLFILE) && xsltproc pgns2json.xslt $(IKXMLFILE) >$(IKJSONFILE)

clean:
	-rm -f $(TARGETS) *.elf *.gdb
	-rm -f $(XMLFILE)
	-rm -f $(JSONFILE)

