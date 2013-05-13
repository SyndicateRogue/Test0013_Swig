/* File : example.i */
%module (directors="1") swigtest

%{
#include "swigtest.h"
%}

%feature("director") Callback;
/* Let's just grab the original header file here */

 
%include "swigtest.h"
%template(CircleMgr) swigtest::ShapesMgr<swigtest::Circle>;
%template(SquareMgr) swigtest::ShapesMgr<swigtest::Square>;

%pragma(java) jniclasscode=%{
  static {
    try {
        System.loadLibrary("swigtest");
    } catch (UnsatisfiedLinkError e) {
      System.err.println("Native code library failed to load. \n" + e);
      System.exit(1);
    }
  }
%}