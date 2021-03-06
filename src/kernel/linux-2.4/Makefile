#
# Special Makefile for building a kernel 2.4 module.
#
here = src/kernel/linux-2.4
there = src/kernel/linux-2.6
top  = ../../..

k24_minor_ver = 
absolute_src_dir = /home/summerkk/ICS/SSDUP
absolute_build_dir= /home/summerkk/ICS/SSDUP
src_relative_top = ./
ifeq "/" "$(shell echo ${src_relative_top} | cut -c 1)"
# not actually relative (as if someone called /tmp/foo/configure
#    instead of ../foo/configure)
    relative_src_dir = ${src_relative_top}
else
    relative_src_dir = $(top)/${src_relative_top}
endif

QUIET_COMPILE = 1
ifdef V
    QUIET_COMPILE = 0
endif

ifeq ($(QUIET_COMPILE),1)
  # say a one-line description of the action, do not echo the command
  Q=@echo
  E=@
else
  # do not say the short Q lines, but do echo the entire command
  Q=@echo >/dev/null
  E=
endif

csrc = \
    pvfs2-utils.c \
    devpvfs2-req.c \
    pvfs2-cache.c \
    dcache.c \
    file.c \
    inode.c \
    dir.c \
    namei.c \
    super.c \
    pvfs2-mod.c \
    pvfs2-bufmap.c \
    symlink.c \
    xattr.c \
	 xattr-trusted.c \
	 xattr-default.c \
    waitqueue.c \
    pvfs2-proc.c

hsrc = \
    pvfs2-kernel.h \
    pvfs2-dev-proto.h \
    pvfs2-bufmap.h \
    upcall.h \
    downcall.h \
    pvfs2-proc.h 

objs = $(csrc:.c=.o)
othergen = pvfs2.o
deps = $(csrc:.c=.d)
preps = $(csrc:.c=.i)

EXTRA_CFLAGS = \
    -I$(absolute_src_dir)/ \
    -I$(absolute_build_dir)/ \
    -I$(absolute_src_dir)/include \
    -I$(absolute_build_dir)/include \
    -I$(absolute_src_dir)/src/io/dev \
    -I$(absolute_src_dir)/src/io/bmi \
    -I$(absolute_src_dir)/src/common/quickhash \
	 -I$(absolute_src_dir)/src/proto \
    -I$(absolute_src_dir)/src/common/gossip \
    -I$(absolute_src_dir)/src/common/misc

EXTRA_CFLAGS += -DPVFS2_LINUX_KERNEL_2_4_MINOR_VER=${k24_minor_ver}
EXTRA_CFLAGS +=   -DPVFS2_LINUX_KERNEL_2_4
EXTRA_CFLAGS += -DPVFS2_VERSION="\"2.9.3-orangefs\""
#EXTRA_CFLAGS += -DPVFS2_KERNEL_DEBUG

KDIR = 
HPATH = $(KDIR)/include

CC = gcc
CPPFLAGS = -D__KERNEL__ -I$(HPATH) -DMODULE -DLINUX 
CFLAGS = $(CPPFLAGS) -MMD -Wall -Wstrict-prototypes -Wno-trigraphs \
         -O2 -nostdinc -iwithprefix include -fno-strict-aliasing \
         -fno-common -fomit-frame-pointer $(EXTRA_CFLAGS)
ARCH := $(shell uname -m | sed -e s/i.86/i386/ -e s/sun4u/sparc64/ -e s/arm.*/arm/ -e s/sa110/arm/)
LINK_SETUP := $(shell for i in $(csrc) $(hsrc); do \
		if [ ! -f $$i  -a  ! -L $$i ] ; then \
			ln -s $(relative_src_dir)/$(there)/$$i ;\
		fi ;\
		done)

dummy: all

include $(KDIR)/arch/$(ARCH)/Makefile

all: pvfs2.o

pvfs2.o: $(objs)
	$(Q) "  LD [M]  $(absolute_src_dir)/$(here)/$@"
	$(E)$(LD) -r -o $@ $^

$(objs):%.o: %.c
	$(Q) "  CC [M]  $(absolute_src_dir)/$(here)/$@"
	$(E)$(CC) $(CFLAGS) -c $< -o $@

$(deps):%.d: %.c
	$(E)touch $@

$(preps):%.i: %.c
	$(E)$(CC) $(CFLAGS) -E $< -o $@

clean:
	$(E)rm -f $(objs) $(deps) $(preps) $(othergen) $(csrc) $(hsrc)

-include $(deps)
