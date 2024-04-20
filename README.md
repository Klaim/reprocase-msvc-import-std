# Repro-case bug msvc

- using VS 17.10-preview4

Reproduction with only the toolchain (without build2) will come soon.


## Reproduce with `build2`

We just have to build the repro-case 2. Note that the issue will not appear for other repro-cases.

See [main.cxx](./main.cxx) for details of how the repro-cases works.

0. Clone and go in the cloned directory.

1. Configure with msvc:
```
# assuming you have vs17-10.preview4
bdep init -C ../build-msvc @msvc cc
```

2. Build repro-case 2:
```
b config.cxx.poptions=-DREPRO_CASE=2
```


## Observed

```
$ b config.cxx.poptions=-DREPRO_CASE=2
c++ mxx{moduleA} -> ..\build-msvc\simpleapp\bmie{moduleA}
c++ cxx{simpleapp} -> ..\build-msvc\simpleapp\obje{simpleapp}
C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.40.33807\include\emmintrin.h(298): error C2733: '_mm_cmpeq_epi8': you cannot overload a function with 'extern "C"' linkage
C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.40.33807\include\emmintrin.h(298): note: see declaration of '_mm_cmpeq_epi8'
C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.40.33807\include\emmintrin.h(298): note: the template instantiation context (the oldest one first) is
E:\tests\repro-import_std\simpleapp\simpleapp.cxx(24): note: see reference to class template instantiation 'A::X<int>' being compiled
E:\tests\repro-import_std\simpleapp\moduleA.mxx(11): note: see reference to class template instantiation 'boost::unordered::unordered_flat_map<int,T,boost::hash<T>,std::equal_to<int>,std::allocator<std::pair<const Key,T>>>' being compiled
        with
        [
            T=int,
            Key=int
        ]
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\unordered_flat_map.hpp(45): note: see reference to class template instantiation 'boost::unordered::detail::foa::table<boost::unordered::detail::foa::flat_map_types<Key,T>,Hash,KeyEqual,std::allocator<std::pair<const Key,T>>>' being compiled
        with
        [
            Key=int,
            T=int,
            Hash=boost::hash<int>,
            KeyEqual=std::equal_to<int>
        ]
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\table.hpp(280): note: see reference to class template instantiation 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>' being compiled
        with
        [
            TypePolicy=boost::unordered::detail::foa::flat_map_types<int,int>,
            Hash=boost::hash<int>,
            Pred=std::equal_to<int>,
            Allocator=std::allocator<std::pair<const int,int>>
        ]
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\core.hpp(1250): note: see reference to class template instantiation 'boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>' being compiled
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\core.hpp(290): note: while compiling class template member function 'int boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>::match_available(void) const'
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\core.hpp(309): note: see the first reference to 'boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>::match_available' in 'boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>::match_occupied'
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\core.hpp(1670): note: see the first reference to 'boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>::match_occupied' in 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::match_really_occupied'
        with
        [
            TypePolicy=boost::unordered::detail::foa::flat_map_types<int,int>,
            Hash=boost::hash<int>,
            Pred=std::equal_to<int>,
            Allocator=std::allocator<std::pair<const int,int>>
        ]
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\core.hpp(1775): note: see the first reference to 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::match_really_occupied' in 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::for_all_elements_while'
        with
        [
            TypePolicy=boost::unordered::detail::foa::flat_map_types<int,int>,
            Hash=boost::hash<int>,
            Pred=std::equal_to<int>,
            Allocator=std::allocator<std::pair<const int,int>>
        ]
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\core.hpp(1763): note: see the first reference to 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::for_all_elements_while' in 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::for_all_elements_while'
        with
        [
            TypePolicy=boost::unordered::detail::foa::flat_map_types<int,int>,
            Hash=boost::hash<int>,
            Pred=std::equal_to<int>,
            Allocator=std::allocator<std::pair<const int,int>>
        ]
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\core.hpp(1741): note: see the first reference to 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::for_all_elements_while' in 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::for_all_elements'
        with
        [
            TypePolicy=boost::unordered::detail::foa::flat_map_types<int,int>,
            Hash=boost::hash<int>,
            Pred=std::equal_to<int>,
            Allocator=std::allocator<std::pair<const int,int>>
        ]
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\core.hpp(1734): note: see the first reference to 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::for_all_elements' in 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::for_all_elements'
        with
        [
            TypePolicy=boost::unordered::detail::foa::flat_map_types<int,int>,
            Hash=boost::hash<int>,
            Pred=std::equal_to<int>,
            Allocator=std::allocator<std::pair<const int,int>>
        ]
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\core.hpp(1333): note: see the first reference to 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::for_all_elements' in 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::~table_core'
        with
        [
            TypePolicy=boost::unordered::detail::foa::flat_map_types<int,int>,
            Hash=boost::hash<int>,
            Pred=std::equal_to<int>,
            Allocator=std::allocator<std::pair<const int,int>>
        ]
E:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include\boost\unordered\detail\foa\table.hpp(326): note: see the first reference to 'boost::unordered::detail::foa::table_core<TypePolicy,boost::unordered::detail::foa::group15<boost::unordered::detail::foa::plain_integral>,boost::unordered::detail::foa::table_arrays,boost::unordered::detail::foa::plain_size_control,Hash,Pred,Allocator>::~table_core' in 'boost::unordered::detail::foa::table<boost::unordered::detail::foa::flat_map_types<Key,T>,Hash,KeyEqual,std::allocator<std::pair<const Key,T>>>::~table'
        with
        [
            TypePolicy=boost::unordered::detail::foa::flat_map_types<int,int>,
            Hash=boost::hash<int>,
            Pred=std::equal_to<int>,
            Allocator=std::allocator<std::pair<const int,int>>
        ]
        and
        [
            Key=int,
            T=int,
            Hash=boost::hash<int>,
            KeyEqual=std::equal_to<int>
        ]
C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.40.33807\include\emmintrin.h(324): error C2733: '_mm_movemask_epi8': you cannot overload a function with 'extern "C"' linkage
C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.40.33807\include\emmintrin.h(324): note: see declaration of '_mm_movemask_epi8'
error: process C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.40.33807\bin\Hostx64\x64\cl exited with code 2
  info: command line: "C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.40.33807\bin\Hostx64\x64\cl" -IE:\tests\repro-import_std\build-msvc\simpleapp -IE:\tests\repro-import_std\simpleapp -DREPRO_CASE=2 -IE:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-unordered-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-container-hash-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-container-hash-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-describe-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-describe-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-mp11-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-mp11-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-type-traits-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-type-traits-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-static-assert-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-static-assert-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-config-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-config-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-move-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-move-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-predef-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-predef-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-preprocessor-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-preprocessor-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-tuple-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-tuple-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-core-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-core-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-throw-exception-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-throw-exception-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-assert-1.83.0\include -IE:\tests\repro-import_std\build-msvc\libboost-assert-1.83.0\include /nologo /std:c++latest /Zc:__cplusplus /permissive- /I "C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.40.33807\include" /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\ucrt" /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\shared" /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\um" /I "C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\winrt" /utf-8 /EHsc /MD /reference A=..\build-msvc\simpleapp\moduleA.exe.ifc /reference std=..\build-msvc\build\cc\build\modules\cxx\std.dll.ifc /Fo: ..\build-msvc\simpleapp\simpleapp.exe.obj /c /TP E:\tests\repro-import_std\simpleapp\simpleapp.cxx
  info: while updating ..\build-msvc\simpleapp\obje{simpleapp}
  info: while updating ..\build-msvc\simpleapp\exe{simpleapp}
  info: while updating ..\build-msvc\dir{simpleapp\}
info: failed to update ..\build-msvc\dir{simpleapp\}
```

## Observations

- Other repro-case are *not* triggering any issue, they compile as expected.
- So far I didnt manage to isolate the issue without using `boost::unordered::unordered_flat_map`

