/*
(C) 2009-2021, Kees Verruijt, Harlingen, The Netherlands.

This file is part of CANboat.

CANboat is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

CANboat is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with CANboat.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <signal.h>
#include <sys/select.h>
#include "common.h"
#include "nmea0183.h"

extern uint16_t port;
extern char *   srcFilter;
extern bool     rateLimit;
extern uint32_t protocol;
extern int      debug;
extern bool     unitSI;

extern int64_t epoch(void);

typedef enum
{
  U_ANGLE,
  U_ANGULAR_VELOCITY,
  U_VELOCITY,
  U_DISTANCE,
  U_TEMPERATURE,
  U_GEO,
  U_MAX
} Unit;

bool         getJSONNumber(const char *message, const char *fieldName, double *value, Unit unit);
bool         getJSONInteger(const char *message, const char *fieldName, int *value);
