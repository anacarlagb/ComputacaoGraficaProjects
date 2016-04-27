# Microsoft Developer Studio Project File - Name="Texture JPG" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Texture JPG - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Texture JPG.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Texture JPG.mak" CFG="Texture JPG - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Texture JPG - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Texture JPG - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Texture JPG - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x416 /d "NDEBUG"
# ADD RSC /l 0x416 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "Texture JPG - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ  /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ  /c
# ADD BASE RSC /l 0x416 /d "_DEBUG"
# ADD RSC /l 0x416 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib glut32.lib glu32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Texture JPG - Win32 Release"
# Name "Texture JPG - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "JPEG Lib"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\JpegLib\JCAPIMIN.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCAPISTD.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCCOEFCT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCCOLOR.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCDCTMGR.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCHUFF.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCINIT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCMAINCT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCMARKER.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCMASTER.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCOMAPI.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCPARAM.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCPHUFF.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCPREPCT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCSAMPLE.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JCTRANS.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDAPIMIN.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDAPISTD.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDATADST.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDATASRC.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDCOEFCT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDCOLOR.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDDCTMGR.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDHUFF.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDINPUT.C

!IF  "$(CFG)" == "Texture JPG - Win32 Release"

!ELSEIF  "$(CFG)" == "Texture JPG - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDMAINCT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDMARKER.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDMASTER.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDMERGE.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDPHUFF.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDPOSTCT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDSAMPLE.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JDTRANS.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JERROR.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JFDCTFLT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JFDCTFST.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JFDCTINT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JIDCTFLT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JIDCTFST.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JIDCTINT.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JIDCTRED.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JMEMMGR.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JMEMNOBS.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\Jpegfile.cpp
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JQUANT1.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JQUANT2.C
# End Source File
# Begin Source File

SOURCE=.\JpegLib\JUTILS.C
# End Source File
# End Group
# Begin Source File

SOURCE=.\FirstTextureJPG.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Jpegfile.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
