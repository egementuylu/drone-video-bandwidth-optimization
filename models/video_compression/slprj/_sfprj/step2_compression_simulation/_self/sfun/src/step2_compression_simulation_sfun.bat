@echo off
set COMPILER=C:\ProgramData\MATLAB\SupportPackages\R2024b\3P.instrset\mingw_w64.instrset\bin\gcc
                set CXXCOMPILER=C:\ProgramData\MATLAB\SupportPackages\R2024b\3P.instrset\mingw_w64.instrset\bin\g++
                set COMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE 
                set CXXCOMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE 
                set OPTIMFLAGS=-O2 -fwrapv -DNDEBUG
                set DEBUGFLAGS=-g
                set LINKER=C:\ProgramData\MATLAB\SupportPackages\R2024b\3P.instrset\mingw_w64.instrset\bin\gcc
                set CXXLINKER=C:\ProgramData\MATLAB\SupportPackages\R2024b\3P.instrset\mingw_w64.instrset\bin\g++
                set LINKFLAGS=-m64 -Wl,--no-undefined -shared -static -L"E:\matlab\extern\lib\win64\mingw64" -llibmx -llibmex -llibmat -lm -llibmwlapack -llibmwblas -Wl,"E:\matlab/extern/lib/win64/mingw64/mexFunction.def"
                set LINKDEBUGFLAGS=-g
                set NAME_OUTPUT=-o "%OUTDIR%%MEX_NAME%%MEX_EXT%"
set PATH=C:\ProgramData\MATLAB\SupportPackages\R2024b\3P.instrset\mingw_w64.instrset\bin;E:\matlab\extern\include\win64;E:\matlab\extern\include;E:\matlab\simulink\include;E:\matlab\lib\win64;%MATLAB_BIN%;%PATH%
set INCLUDE=C:\ProgramData\MATLAB\SupportPackages\R2024b\3P.instrset\mingw_w64.instrset\include;;%INCLUDE%
set LIB=C:\ProgramData\MATLAB\SupportPackages\R2024b\3P.instrset\mingw_w64.instrset\lib;;%LIB%
set LIBPATH=E:\matlab\extern\lib\win64;%LIBPATH%

gmake SHELL="cmd" -f step2_compression_simulation_sfun.gmk
