Visual Studio 2019 constexpr inconsistency
------------------------------------------

This is an MVCE (minimal, verifiable, complete example) of a bug in Visual Studio 2019's compiler
which results in an inconsistency between compile time values and runtime values, specifically
relating to `char16_t` pointers.

# Issue

At compile time, the `Span` struct correctly identifies that the `char16_t` string `u"hello"` is
5 `char16_t`s long, but somehow the executable produces a different value at runtime.


# Use

1. Install Visual Studio 2019 or Visual Studio 2019 Build Tools
(Tested with Visual Studio 2019 v16.11.42)

2. Generate a debug config with default settings
```pwsh
# For a very Microsoft build
cmake -G "Visual Studio 16 2019" -S . -B build
```

3. Build
```pwsh
cmake --build build
```

4. Run the executable
```pwsh
./build/Debug/repro.exe
```

5. Expected output:
'hello' length is 5,
'#'     length is 1,

Actual output:
```
Microsoft (R) Build Engine version 16.11.2+f32259642 for .NET Framework
Copyright (C) Microsoft Corporation. All rights reserved.

  1>Checking Build System
  Building Custom Rule C:/Users/oliver.smith/source/repos/cpp/vsconstexpr/CMakeLists.txt
  repro.cpp
  repro.vcxproj -> C:\Users\oliver.smith\source\repos\cpp\vsconstexpr\build\Debug\repro.exe

```

6. Comparison
Build with Visual Studio 2022/Build Tools, and the correct output is seen.
