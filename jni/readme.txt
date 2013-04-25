1 download:  http://www.swig.org/download.html
2.Code in cygwin:

swig -c++ -java -package com.habzy.swig -outdir src/com/habzy/swig -o jni/swigtest_jni.cpp jni/swigtest.i

3.Code in cygwin:

ndk-build -B -j4

4.Run APK
