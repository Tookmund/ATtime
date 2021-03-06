/* clock.c: CLI to convert to and from ATtime
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

#include <time.h>
#include "attime.h"
#include <stdio.h>

char * menu = "+--------------------------------+\n"
	      "| [0] Get Current Time in ATtime |\n"
	      "| [1] Convert ATtime to Seconds  |\n"
	      "| [2] Convert ATtime to UTC      |\n"
	      "+--------------------------------+\n";

int main ()
{
	int timer;
	struct tm tm;
	int ch = 1;
	printf(menu);
	while (ch != EOF)
	{
		ch = getchar();
		if (ch == '\n')
			continue;
		switch(ch)
		{
			case '0':
				printf("@%d\n",attime(NULL));
				break;
			case '1':
				printf("Input ATtime: ");
				scanf("%d",&timer);
				printf("%d\n",attime2seconds(timer));
				break;
			case '2':
				printf("Input ATtime: ");
				scanf("%d",&timer);
				tm = attime2utc(timer);
				printf("%d:%d:%d\n",tm.tm_hour,tm.tm_min,tm.tm_sec);
				break;
			default:
				break;
		}
		timer = 0;
		printf(menu);
	}
	return 0;
}
