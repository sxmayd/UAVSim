#
# OMNeT++/OMNEST Makefile for libqueueinglib
#
# This file was generated with the command:
#  opp_makemake -f --make-so -DAUTOIMPORT_NAMESPACE
#

# Name of target to be created (-o option)
TARGET = libqueueinglib$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = -I.

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/Allocate.o \
    $O/Classifier.o \
    $O/Clone.o \
    $O/Deallocate.o \
    $O/Delay.o \
    $O/Fork.o \
    $O/Job.o \
    $O/JobList.o \
    $O/Join.o \
    $O/Merge.o \
    $O/PassiveQueue.o \
    $O/Queue.o \
    $O/ResourceBasedQueue.o \
    $O/ResourcePool.o \
    $O/Router.o \
    $O/SelectionStrategies.o \
    $O/Server.o \
    $O/Sink.o \
    $O/Source.o \
    $O/Job_m.o

# Message files
MSGFILES = \
    Job.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS) -DAUTOIMPORT_NAMESPACE $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)$(SHLIB_LD) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS)
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f queueinglib queueinglib.exe libqueueinglib.so libqueueinglib.a libqueueinglib.dll libqueueinglib.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/Allocate.o: Allocate.cc \
  ./Job.h \
  ./IResourcePool.h \
  ./ResourcePool.h \
  ./Job_m.h \
  ./Allocate.h \
  ./QueueingDefs.h
$O/Classifier.o: Classifier.cc \
  ./QueueingDefs.h \
  ./Job_m.h \
  ./Classifier.h \
  ./Job.h
$O/Clone.o: Clone.cc \
  ./Clone.h \
  ./QueueingDefs.h \
  ./Job_m.h \
  ./Job.h
$O/Deallocate.o: Deallocate.cc \
  ./ResourcePool.h \
  ./IResourcePool.h \
  ./Deallocate.h \
  ./QueueingDefs.h
$O/Delay.o: Delay.cc \
  ./Delay.h \
  ./Job.h \
  ./QueueingDefs.h \
  ./Job_m.h
$O/Fork.o: Fork.cc \
  ./Fork.h \
  ./QueueingDefs.h \
  ./Job_m.h \
  ./Job.h
$O/Job.o: Job.cc \
  ./QueueingDefs.h \
  ./Job_m.h \
  ./JobList.h \
  ./Job.h
$O/JobList.o: JobList.cc \
  ./Job_m.h \
  ./QueueingDefs.h \
  ./Job.h \
  ./JobList.h
$O/Job_m.o: Job_m.cc \
  ./QueueingDefs.h \
  ./Job_m.h
$O/Join.o: Join.cc \
  ./Job.h \
  ./QueueingDefs.h \
  ./Join.h \
  ./Job_m.h
$O/Merge.o: Merge.cc \
  ./Merge.h \
  ./QueueingDefs.h
$O/PassiveQueue.o: PassiveQueue.cc \
  ./Job_m.h \
  ./QueueingDefs.h \
  ./PassiveQueue.h \
  ./Job.h \
  ./IPassiveQueue.h \
  ./SelectionStrategies.h
$O/Queue.o: Queue.cc \
  ./Queue.h \
  ./Job_m.h \
  ./QueueingDefs.h \
  ./Job.h
$O/ResourceBasedQueue.o: ResourceBasedQueue.cc \
  ./Job_m.h \
  ./IResourcePool.h \
  ./QueueingDefs.h \
  ./Job.h \
  ./ResourceBasedQueue.h
$O/ResourcePool.o: ResourcePool.cc \
  ./QueueingDefs.h \
  ./IResourcePool.h \
  ./ResourcePool.h
$O/Router.o: Router.cc \
  ./Router.h \
  ./QueueingDefs.h
$O/SelectionStrategies.o: SelectionStrategies.cc \
  ./Server.h \
  ./QueueingDefs.h \
  ./IPassiveQueue.h \
  ./PassiveQueue.h \
  ./SelectionStrategies.h \
  ./IServer.h
$O/Server.o: Server.cc \
  ./Server.h \
  ./Job_m.h \
  ./QueueingDefs.h \
  ./IPassiveQueue.h \
  ./Job.h \
  ./SelectionStrategies.h \
  ./IServer.h
$O/Sink.o: Sink.cc \
  ./Sink.h \
  ./QueueingDefs.h \
  ./Job_m.h \
  ./Job.h
$O/Source.o: Source.cc \
  ./Job.h \
  ./Source.h \
  ./Job_m.h \
  ./QueueingDefs.h
