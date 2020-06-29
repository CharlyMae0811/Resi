---
title: "Reaktive Sicherheit"
subtitle: "Übungsblatt 9"
author: 
	- Balduin Binder [s6babind@uni-bonn.de]
	- Charlotte Mädler [s6chmaed@uni-bonn.de]
	- Bünyamin Sarikaya [s6busari@uni-bonn.de]
lang: de
output: pdf_file
---

# Aufgabe 1

(1) An environment variable is a dynamic-named value that can affect the way running processes will behave on a computer. They are part of the environment in which a process runs. For example, a running process can query the value of the TEMP environment variable to discover a suitable location to store temporary files, or the HOME or USERPROFILE variable to find the directory structure owned by the user running the process.

(2)Use the System.Environment class.

The methods

var value = System.Environment.GetEnvironmentVariable(variable [, Target])
and

System.Environment.SetEnvironmentVariable(variable, value [, Target])
will do the job for you.

The optional parameter Target is an enum of type EnvironmentVariableTarget and it can be one of: Machine, Process, or User. If you omit it, the default target is the current process.

(3)

(4)#include <unistd.h> 

int execve(const char *filename, char *const argv[], char *const envp[]);

execve() executes the program pointed to by filename. filename must be either a binary executable, or a script starting with a line of the form "#! interpreter [arg]". In the latter case, the interpreter must be a valid pathname for an executable which is not itself a script, which will be invoked as interpreter [arg] filename.

argv is an array of argument strings passed to the new program. envp is an array of strings, conventionally of the form key=value, which are passed as environment to the new program. Both argv and envp must be terminated by a null pointer. The argument vector and environment can be accessed by the called program’s main function, when it is defined as int main(int argc, char *argv[], char *envp[]).

execve() does not return on success, and the text, data, bss, and stack of the calling process are overwritten by that of the program loaded. The program invoked inherits the calling process’s PID, and any open file descriptors that are not set to close-on-exec. Signals pending on the calling process are cleared. Any signals set to be caught by the calling process are reset to their default behaviour. The SIGCHLD signal (when set to SIG_IGN) may or may not be reset to SIG_DFL.

If the current program is being ptraced, a SIGTRAP is sent to it after a successful execve().

If the set-user-ID bit is set on the program file pointed to by filename, and the calling process is not being ptraced, then the effective user ID of the calling process is changed to that of the owner of the program file. i Similarly, when the set-group-ID bit of the program file is set the effective group ID of the calling process is set to the group of the program file.

The effective user ID of the process is copied to the saved set-user-ID; similarly, the effective group ID is copied to the saved set-group-ID. This copying takes place after any effective ID changes that occur because of the set-user-ID and set-group-ID permission bits.

If the executable is an a.out dynamically-linked binary executable containing shared-library stubs, the Linux dynamic linker ld.so(8) is called at the start of execution to bring needed shared libraries into memory and link the executable with them.

If the executable is a dynamically-linked ELF executable, the interpreter named in the PT_INTERP segment is used to load the needed shared libraries. This interpreter is typically /lib/ld-linux.so.1 for binaries linked with the Linux libc version 5, or /lib/ld-linux.so.2 for binaries linked with the GNU libc version 2.

RETURN VALUE
On success, execve() does not return, on error -1 is returned, and errno is set appropriately

(5)

(6)
PATH ist die Systemvariable, die das Betriebssystem verwendet, um über die Befehlszeile oder das Terminalfenster nach erforderlichen ausführbaren Dateien zu suchen.
Die Systemvariable PATH kann mit dem Systemutility in der Windows-Systemsteuerung oder in der Startdatei der Linux- oder Solaris-Shell eingerichtet werden.
Änderungen an der Systemvariablen PATH sind in der Regel nicht erforderlich bei Rechnern, auf denen Windows oder Mac OS X ausgeführt wird.
One of the most well-known is called PATH on Windows, Linux and Mac OS X. It specifies the directories in which executable programs* are located on the machine that can be started without knowing and typing the whole path to the file on the command line.On Linux and Mac OS X, it usually holds all bin and sbin directories relevant for the current user.
specifying a set of directories where executable programs are located. In general, each executing process or user session has its own PATH setting.
 $PATH variable is specified as a list of one or more directory names separated by colon (:) characters
 Directories in the PATH-string are not meant to be escaped, making it impossible to have directories with : in their name. 
 absolute (/home/userjoe/bin/script.sh) or relative path (./script.sh) 
 
 # Aufgabe 3

           
