# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nina/Dropbox/github/sommerjobb/qt/TestGui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nina/Dropbox/github/sommerjobb/qt/TestGui

# Include any dependencies generated for this target.
include CMakeFiles/TestGui.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestGui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestGui.dir/flags.make

ui_guiwindow.h: guiwindow.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nina/Dropbox/github/sommerjobb/qt/TestGui/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_guiwindow.h"
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic -o /home/nina/Dropbox/github/sommerjobb/qt/TestGui/ui_guiwindow.h /home/nina/Dropbox/github/sommerjobb/qt/TestGui/guiwindow.ui

moc_guiwindow.cxx: guiwindow.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nina/Dropbox/github/sommerjobb/qt/TestGui/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_guiwindow.cxx"
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc -I/usr/local/include/vtk-5.10 -I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/home/nina/Dropbox/github/sommerjobb/qt/TestGui -I/home/nina/Dropbox/github/sommerjobb/qt/TestGui -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -o /home/nina/Dropbox/github/sommerjobb/qt/TestGui/moc_guiwindow.cxx /home/nina/Dropbox/github/sommerjobb/qt/TestGui/guiwindow.h

moc_ui_guiwindow.cxx: ui_guiwindow.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nina/Dropbox/github/sommerjobb/qt/TestGui/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_ui_guiwindow.cxx"
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc -I/usr/local/include/vtk-5.10 -I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/home/nina/Dropbox/github/sommerjobb/qt/TestGui -I/home/nina/Dropbox/github/sommerjobb/qt/TestGui -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -o /home/nina/Dropbox/github/sommerjobb/qt/TestGui/moc_ui_guiwindow.cxx /home/nina/Dropbox/github/sommerjobb/qt/TestGui/ui_guiwindow.h

qrc_guiwindow.cxx: images/new.png
qrc_guiwindow.cxx: images/open.png
qrc_guiwindow.cxx: images/save.png
qrc_guiwindow.cxx: images/cut.png
qrc_guiwindow.cxx: images/copy.png
qrc_guiwindow.cxx: images/paste.png
qrc_guiwindow.cxx: images/exit.png
qrc_guiwindow.cxx: images/domain.png
qrc_guiwindow.cxx: images/boundary.png
qrc_guiwindow.cxx: images/mesh.png
qrc_guiwindow.cxx: images/fenics.png
qrc_guiwindow.cxx: images/fenics_banner.png
qrc_guiwindow.cxx: guiwindow.qrc.depends
qrc_guiwindow.cxx: guiwindow.qrc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nina/Dropbox/github/sommerjobb/qt/TestGui/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating qrc_guiwindow.cxx"
	/usr/lib/x86_64-linux-gnu/qt4/bin/rcc -name guiwindow -o /home/nina/Dropbox/github/sommerjobb/qt/TestGui/qrc_guiwindow.cxx /home/nina/Dropbox/github/sommerjobb/qt/TestGui/guiwindow.qrc

CMakeFiles/TestGui.dir/main.cpp.o: CMakeFiles/TestGui.dir/flags.make
CMakeFiles/TestGui.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nina/Dropbox/github/sommerjobb/qt/TestGui/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestGui.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestGui.dir/main.cpp.o -c /home/nina/Dropbox/github/sommerjobb/qt/TestGui/main.cpp

CMakeFiles/TestGui.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestGui.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nina/Dropbox/github/sommerjobb/qt/TestGui/main.cpp > CMakeFiles/TestGui.dir/main.cpp.i

CMakeFiles/TestGui.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestGui.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nina/Dropbox/github/sommerjobb/qt/TestGui/main.cpp -o CMakeFiles/TestGui.dir/main.cpp.s

CMakeFiles/TestGui.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/TestGui.dir/main.cpp.o.requires

CMakeFiles/TestGui.dir/main.cpp.o.provides: CMakeFiles/TestGui.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TestGui.dir/build.make CMakeFiles/TestGui.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TestGui.dir/main.cpp.o.provides

CMakeFiles/TestGui.dir/main.cpp.o.provides.build: CMakeFiles/TestGui.dir/main.cpp.o

CMakeFiles/TestGui.dir/guiwindow.cpp.o: CMakeFiles/TestGui.dir/flags.make
CMakeFiles/TestGui.dir/guiwindow.cpp.o: guiwindow.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nina/Dropbox/github/sommerjobb/qt/TestGui/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestGui.dir/guiwindow.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestGui.dir/guiwindow.cpp.o -c /home/nina/Dropbox/github/sommerjobb/qt/TestGui/guiwindow.cpp

CMakeFiles/TestGui.dir/guiwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestGui.dir/guiwindow.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nina/Dropbox/github/sommerjobb/qt/TestGui/guiwindow.cpp > CMakeFiles/TestGui.dir/guiwindow.cpp.i

CMakeFiles/TestGui.dir/guiwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestGui.dir/guiwindow.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nina/Dropbox/github/sommerjobb/qt/TestGui/guiwindow.cpp -o CMakeFiles/TestGui.dir/guiwindow.cpp.s

CMakeFiles/TestGui.dir/guiwindow.cpp.o.requires:
.PHONY : CMakeFiles/TestGui.dir/guiwindow.cpp.o.requires

CMakeFiles/TestGui.dir/guiwindow.cpp.o.provides: CMakeFiles/TestGui.dir/guiwindow.cpp.o.requires
	$(MAKE) -f CMakeFiles/TestGui.dir/build.make CMakeFiles/TestGui.dir/guiwindow.cpp.o.provides.build
.PHONY : CMakeFiles/TestGui.dir/guiwindow.cpp.o.provides

CMakeFiles/TestGui.dir/guiwindow.cpp.o.provides.build: CMakeFiles/TestGui.dir/guiwindow.cpp.o

CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o: CMakeFiles/TestGui.dir/flags.make
CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o: moc_guiwindow.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nina/Dropbox/github/sommerjobb/qt/TestGui/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o -c /home/nina/Dropbox/github/sommerjobb/qt/TestGui/moc_guiwindow.cxx

CMakeFiles/TestGui.dir/moc_guiwindow.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestGui.dir/moc_guiwindow.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nina/Dropbox/github/sommerjobb/qt/TestGui/moc_guiwindow.cxx > CMakeFiles/TestGui.dir/moc_guiwindow.cxx.i

CMakeFiles/TestGui.dir/moc_guiwindow.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestGui.dir/moc_guiwindow.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nina/Dropbox/github/sommerjobb/qt/TestGui/moc_guiwindow.cxx -o CMakeFiles/TestGui.dir/moc_guiwindow.cxx.s

CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o.requires:
.PHONY : CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o.requires

CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o.provides: CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o.requires
	$(MAKE) -f CMakeFiles/TestGui.dir/build.make CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o.provides.build
.PHONY : CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o.provides

CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o.provides.build: CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o

CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o: CMakeFiles/TestGui.dir/flags.make
CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o: moc_ui_guiwindow.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nina/Dropbox/github/sommerjobb/qt/TestGui/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o -c /home/nina/Dropbox/github/sommerjobb/qt/TestGui/moc_ui_guiwindow.cxx

CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nina/Dropbox/github/sommerjobb/qt/TestGui/moc_ui_guiwindow.cxx > CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.i

CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nina/Dropbox/github/sommerjobb/qt/TestGui/moc_ui_guiwindow.cxx -o CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.s

CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o.requires:
.PHONY : CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o.requires

CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o.provides: CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o.requires
	$(MAKE) -f CMakeFiles/TestGui.dir/build.make CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o.provides.build
.PHONY : CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o.provides

CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o.provides.build: CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o

CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o: CMakeFiles/TestGui.dir/flags.make
CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o: qrc_guiwindow.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nina/Dropbox/github/sommerjobb/qt/TestGui/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o -c /home/nina/Dropbox/github/sommerjobb/qt/TestGui/qrc_guiwindow.cxx

CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nina/Dropbox/github/sommerjobb/qt/TestGui/qrc_guiwindow.cxx > CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.i

CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nina/Dropbox/github/sommerjobb/qt/TestGui/qrc_guiwindow.cxx -o CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.s

CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o.requires:
.PHONY : CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o.requires

CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o.provides: CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o.requires
	$(MAKE) -f CMakeFiles/TestGui.dir/build.make CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o.provides.build
.PHONY : CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o.provides

CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o.provides.build: CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o

# Object files for target TestGui
TestGui_OBJECTS = \
"CMakeFiles/TestGui.dir/main.cpp.o" \
"CMakeFiles/TestGui.dir/guiwindow.cpp.o" \
"CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o" \
"CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o" \
"CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o"

# External object files for target TestGui
TestGui_EXTERNAL_OBJECTS =

TestGui: CMakeFiles/TestGui.dir/main.cpp.o
TestGui: CMakeFiles/TestGui.dir/guiwindow.cpp.o
TestGui: CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o
TestGui: CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o
TestGui: CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o
TestGui: CMakeFiles/TestGui.dir/build.make
TestGui: /usr/local/lib/vtk-5.10/libvtkCommon.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkFiltering.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkImaging.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkGraphics.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkGenericFiltering.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkIO.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkRendering.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkVolumeRendering.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkHybrid.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkWidgets.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkInfovis.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkGeovis.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkViews.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkCharts.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libQVTK.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkViews.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkInfovis.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkWidgets.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkVolumeRendering.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkHybrid.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkRendering.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkImaging.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkGraphics.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkIO.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkFiltering.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtkCommon.so.5.10.1
TestGui: /usr/local/lib/vtk-5.10/libvtksys.so.5.10.1
TestGui: /usr/lib/x86_64-linux-gnu/libQtWebKit.so
TestGui: /usr/lib/x86_64-linux-gnu/libQtXmlPatterns.so
TestGui: /usr/lib/x86_64-linux-gnu/libQtGui.so
TestGui: /usr/lib/x86_64-linux-gnu/libQtSql.so
TestGui: /usr/lib/x86_64-linux-gnu/libQtNetwork.so
TestGui: /usr/lib/x86_64-linux-gnu/libQtCore.so
TestGui: /usr/lib/x86_64-linux-gnu/libX11.so
TestGui: /usr/lib/x86_64-linux-gnu/libXext.so
TestGui: CMakeFiles/TestGui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable TestGui"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestGui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestGui.dir/build: TestGui
.PHONY : CMakeFiles/TestGui.dir/build

CMakeFiles/TestGui.dir/requires: CMakeFiles/TestGui.dir/main.cpp.o.requires
CMakeFiles/TestGui.dir/requires: CMakeFiles/TestGui.dir/guiwindow.cpp.o.requires
CMakeFiles/TestGui.dir/requires: CMakeFiles/TestGui.dir/moc_guiwindow.cxx.o.requires
CMakeFiles/TestGui.dir/requires: CMakeFiles/TestGui.dir/moc_ui_guiwindow.cxx.o.requires
CMakeFiles/TestGui.dir/requires: CMakeFiles/TestGui.dir/qrc_guiwindow.cxx.o.requires
.PHONY : CMakeFiles/TestGui.dir/requires

CMakeFiles/TestGui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestGui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestGui.dir/clean

CMakeFiles/TestGui.dir/depend: ui_guiwindow.h
CMakeFiles/TestGui.dir/depend: moc_guiwindow.cxx
CMakeFiles/TestGui.dir/depend: moc_ui_guiwindow.cxx
CMakeFiles/TestGui.dir/depend: qrc_guiwindow.cxx
	cd /home/nina/Dropbox/github/sommerjobb/qt/TestGui && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nina/Dropbox/github/sommerjobb/qt/TestGui /home/nina/Dropbox/github/sommerjobb/qt/TestGui /home/nina/Dropbox/github/sommerjobb/qt/TestGui /home/nina/Dropbox/github/sommerjobb/qt/TestGui /home/nina/Dropbox/github/sommerjobb/qt/TestGui/CMakeFiles/TestGui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestGui.dir/depend
