```
$ # print running kernel release 
$ uname -r
4.15.0-72-generic

$ # location of kernel include files
$ ls /usr/src/linux-headers-4.15.0-72/include/
acpi         clocksource  drm          keys  linux     media   misc  pcmcia  rdma  soc    target  uapi   xen
asm-generic  crypto       dt-bindings  kvm   math-emu  memory  net   ras     scsi  sound  trace   video

$ # location of user include files
$ ls /usr/include/
aio.h          elf.h         glob.h          mcheck.h    nfs         rpcsvc         stropts.h      utmp.h
aliases.h      endian.h      gnumake.h       memory.h    nl_types.h  sched.h        sudo_plugin.h  utmpx.h
alloca.h       envz.h        gnu-versions.h  misc        nss.h       scsi           syscall.h      values.h
argp.h         err.h         grp.h           mntent.h    obstack.h   search.h       sysexits.h     video
argz.h         errno.h       gshadow.h       monetary.h  paths.h     semaphore.h    syslog.h       wait.h
ar.h           error.h       iconv.h         mqueue.h    poll.h      setjmp.h       tar.h          wchar.h
arpa           execinfo.h    ifaddrs.h       mtd         printf.h    sgtty.h        termio.h       wctype.h
asm-generic    fcntl.h       inttypes.h      net         protocols   shadow.h       termios.h      wordexp.h
assert.h       features.h    langinfo.h      netash      pthread.h   signal.h       tgmath.h       X11
autosprintf.h  fenv.h        lastlog.h       netatalk    pty.h       sound          thread_db.h    x86-linux-gnu
byteswap.h     fmtmsg.h      libgen.h        netax25     pwd.h       spawn.h        time.h         xen
c++            fnmatch.h     libintl.h       netdb.h     python3.5m  stab.h         ttyent.h       xlocale.h
complex.h      fstab.h       libio.h         neteconet   rdma        stdc-predef.h  uapi           xorg
cpio.h         fts.h         limits.h        netinet     re_comp.h   stdint.h       uchar.h
crypt.h        ftw.h         link.h          netipx      regex.h     stdio_ext.h    ucontext.h
ctype.h        _G_config.h   linux           netiucv     regexp.h    stdio.h        ulimit.h
dirent.h       gconv.h       locale.h        netpacket   reglib      stdlib.h       unistd.h
dlfcn.h        getopt.h      malloc.h        netrom      resolv.h    string.h       ustat.h
drm            gettext-po.h  math.h          netrose     rpc         strings.h      utime.h

$ mknod devfile c 60 0

$ insmod testdriver.ko
$ echo hello > devfile
$ cat devfile
$ rmmod testdriver

$ dmesg
$ dmesg -c
```
