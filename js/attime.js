/* attime.c: Functions to convert to and from ATtime
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

function attime(date) {
	return Math.round((date.getUTCSeconds() + (date.getUTCMinutes() * 60) + (date.getUTCHours()*3600)) / 86.4);
}

function attimeclock(dom) {
	var date;
	var at;
	setInterval(function() {
		date = new Date();
		at = attime(date);
		dom.innerHTML = "@"+at;
	},1500);
}
