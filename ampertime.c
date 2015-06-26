/* ampertime.c: Functions to convert to and from Ampertime
 * Copyright (c) 2015 Jacob Adams
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * Conversion from UTC = (UTCseconds + (UTCminutes * 60) + (UTChours * 3600)) / 86.4
 */

#include <time.h>
#include "ampertime.h"

int ampertime(time_t* timer)
{
	time_t reftime = time(timer);
	struct tm* tm;
	tm = gmtime(&reftime);
	return (tm->tm_sec + (tm->tm_min * 60) + (tm->tm_hour * 3600))/86.4;
}

struct tm ampertime2std(int amper)
{
	int totsec = amper*86.4;
	/* Based mostly on http://programmingcentre.blogspot.com/2013/04/c-program-to-convert-time-in-seconds-to.html */
	int hr = totsec/3600;
	int t = totsec%3600;
	int min = t/60;
	int sec = t%60;
	struct tm tm;
	tm.tm_sec = sec;
	tm.tm_min = min;
	tm.tm_hour = hr;
	return tm;
}
int ampertime2seconds(int amper)
{
	return amper*86.4;
}
