## Purpose

This project demonstrates how (using the latest v143 toolset) an exported inline function with thread_local static data will cause the linker error:
LNK1161: invalid export specification

Compiling with TestFunc defined as inlined results in the following linker directives:
```
   /EXPORT:?data@?1??TestFunc@ExportedClass@@QEAAXXZ@4UThreadLocalData@@A,THREAD_DATA
   /EXPORT:??__J?1??TestFunc@ExportedClass@@QEAAXXZ@51,THREAD_DATA
```

Compiling **without** inline, ofcourse, will omit these directives (no static function data is exported).

## Previous Behaviour (v142)
**THREAD_DATA** cannot be exported, in previous versions of MSVC, these linker directives were marked as DATA instead (essentially the same as omitting thread_local from the storage specification).

## Building
Well, this won't compile by default.
But generally use any Visual Studio CMAKE generator to compile this project to test the compilation.