.TH SREP 1 "March 2024" "1.0" "srep man page"
.SH NAME
srep \- search and highlight patterns in files
.SH SYNOPSIS
.B srep
[\-i] [\-\-ignore-case]
[\-c] [\-\-count-matches]
[\-n] [\-\-line-numbers]
[\-w] [\-\-exact-word]
.PP
.B srep
.PP
[\fIpattern\fR] 
[\fIoption\fR]
[\fIfile1\fR] [\fIfile2\fR] ...
.SH DESCRIPTION
\fBsrep\fR is a command-line tool that searches for a specified pattern in one or more files and highlights occurrences of the pattern. It provides options to control the search behavior and output format and regular expressions or regex can be provided instead of the word or pattern.
.SH OPTIONS
.TP
.B \-i, \-\-ignore-case
Perform case-insensitive pattern matching.
.TP
.B \-c, \-\-count-matches
Display the total number of matched lines.
.TP
.B \-n, \-\-line-numbers
Print line numbers before each matching line.
.TP
.B \-w, \-\-exact-word
Match only whole words, not substrings.

\fIAll these options can be used simultaneously also.\fR

.SH ARGUMENTS
.TP
\fIpattern\fR
The pattern to search for in the input files. Supports regular expressions.
.TP
\fIoption\fR
Mentioned above options can be used.
.TP
\fIfile1, file2, ...\fR
The input files to search for the pattern.
	
.SH EXAMPLES
.TP
.B srep "hello world"  -w file.txt
Search for the exact phrase "hello world" in file.txt.
.TP
.B srep  "word" \-i  \-n file1.txt file2.txt
Search for "word" case-insensitively in file1.txt and file2.txt, displaying line numbers.
.SH AUTHOR
Written by Siba charan Das | III B.S.c(Maths).
.SH REPORTING BUGS
Report bugs to sibacharan2002@gmail.com.
.SH COPYRIGHT
Copyright (c) [2024] [Siba]. This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
.SH SEE ALSO
.TP
.BR grep (1)
man grep
.TP
.BR regex (3)
man regex
.SH NOTES
This manual page was written for the srep program and should be adapted to fit your specific implementation.
