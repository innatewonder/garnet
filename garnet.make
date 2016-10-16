# GNU Make project makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild prelink

ifeq ($(config),debug)
  RESCOMP = windres
  TARGETDIR = bin/debug
  TARGET = $(TARGETDIR)/garnet
  OBJDIR = obj/Debug
  PCH = include/CommonPrecompiled.h
  GCH = $(OBJDIR)/$(notdir $(PCH)).gch
  DEFINES += -D_DEBUG -DDEBUG
  INCLUDES += -Iinclude -Iinclude/input -Iinclude/physics -Iinclude/graphics -Iinclude/audio -Iinclude/math -Iinclude/networking -Iinclude/core -Iinclude/graphics/components -Iinclude/math/common -Iinclude/math/algebra -Iinclude/math/geometry -Iinclude/networking/engine -Iinclude/networking/protocols -Iinclude/core/thread -Iinclude/core/util -Iinclude/core/memory -Iinclude/core/filesystem -Iinclude/core/delegate -Iinclude/core/containers
  FORCE_INCLUDE += -include $(OBJDIR)/$(notdir $(PCH))
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -g -std=c++11
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CFLAGS)
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/debug/libaudio.a bin/debug/libgraphics.a bin/debug/libphysics.a bin/debug/libnetworking.a -lpthread
  LDDEPS += bin/debug/libaudio.a bin/debug/libgraphics.a bin/debug/libphysics.a bin/debug/libnetworking.a
  ALL_LDFLAGS += $(LDFLAGS) -Llib -Llib/debug
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),release)
  RESCOMP = windres
  TARGETDIR = bin/release
  TARGET = $(TARGETDIR)/garnet
  OBJDIR = obj/Release
  PCH = include/CommonPrecompiled.h
  GCH = $(OBJDIR)/$(notdir $(PCH)).gch
  DEFINES += -DNDEBUG
  INCLUDES += -Iinclude -Iinclude/input -Iinclude/physics -Iinclude/graphics -Iinclude/audio -Iinclude/math -Iinclude/networking -Iinclude/core -Iinclude/graphics/components -Iinclude/math/common -Iinclude/math/algebra -Iinclude/math/geometry -Iinclude/networking/engine -Iinclude/networking/protocols -Iinclude/core/thread -Iinclude/core/util -Iinclude/core/memory -Iinclude/core/filesystem -Iinclude/core/delegate -Iinclude/core/containers
  FORCE_INCLUDE += -include $(OBJDIR)/$(notdir $(PCH))
  ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -std=c++11
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CFLAGS)
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += bin/release/libaudio.a bin/release/libgraphics.a bin/release/libphysics.a bin/release/libnetworking.a -lpthread
  LDDEPS += bin/release/libaudio.a bin/release/libgraphics.a bin/release/libphysics.a bin/release/libnetworking.a
  ALL_LDFLAGS += $(LDFLAGS) -Llib -Llib/release -s
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

endif

OBJECTS := \
	$(OBJDIR)/CommonPrecompiled.o \
	$(OBJDIR)/Main.o \

RESOURCES := \

CUSTOMFILES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

$(TARGET): $(GCH) ${CUSTOMFILES} $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking garnet
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning garnet
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) $(PCH)
$(GCH): $(PCH)
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
endif

$(OBJDIR)/CommonPrecompiled.o: src/CommonPrecompiled.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Main.o: src/Main.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(OBJDIR)/$(notdir $(PCH)).d
endif