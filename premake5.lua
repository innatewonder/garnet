solution "garnet"
  configurations { "Debug", "Release" }

  configuration { "Debug" }
    targetdir "bin/debug"

  configuration { "Release" }
    targetdir "bin/release"

  if _ACTION == "clean" then
    os.rmdir("bin/debug", "bin/release")
  end

------------------------
------EXE
------------------------
  project "garnet"
    language "C++"
    kind     "ConsoleApp"

    files  {"src/*.cpp", "include/**.h", "include/**.hpp" }
    links  { 
      "audio", 
      "graphics", 
      "physics", 
      "networking", 
    }

    libdirs { "lib/"}
    if(os.get() == "windows") then
      debugenvs "PATH=%PATH%;$(ProjectDir)"
      links { 
      }
    elseif(os.get() == "linux") then
      buildoptions { "-std=c++11" }
      links { 
      "pthread", 
      }
    end


    defines{
    }

    includedirs {
    "include",
    "include/**",    }
    if(_ACTION == "gmake") then
      buildoptions {"-std=c++11"}

      pchheader ( "include/CommonPrecompiled.h" )
    else
      pchheader ( "CommonPrecompiled.h" )
    end
    pchsource ( "src/CommonPrecompiled.cpp" )
    flags { 
    "Unicode"}

    configuration { "Debug*" }
      defines { "_DEBUG", "DEBUG" }
      flags   { "Symbols" }
      libdirs { "lib/debug", 
      }

    configuration { "Release*" }
      defines { "NDEBUG" }
      libdirs { "lib/release",       }

------------------------
------audio LIB
------------------------
  project "audio"
    location "settings"
    language "C++"
    kind     "StaticLib"

    files  { 
"src/CommonPrecompiled.cpp",
 "src/audio/**.cpp", "include/**.h", "include/**.hpp" }


    defines{
    }

    includedirs {
    "include",
    "include/**",    }
    if(_ACTION == "gmake") then
      buildoptions {"-std=c++11"}

      pchheader ( "include/CommonPrecompiled.h" )
    else
      pchheader ( "CommonPrecompiled.h" )
    end
    pchsource ( "src/CommonPrecompiled.cpp" )
    flags { 
    "Unicode"}

    configuration { "Debug*" }
      defines { "_DEBUG", "DEBUG" }
      flags   { "Symbols" }
      libdirs { "lib/debug", 
      }

    configuration { "Release*" }
      defines { "NDEBUG" }
      libdirs { "lib/release",       }

------------------------
------graphics LIB
------------------------
  project "graphics"
    location "settings"
    language "C++"
    kind     "StaticLib"

    files  { 
"src/CommonPrecompiled.cpp",
 "src/graphics/**.cpp", "include/**.h", "include/**.hpp" }


    defines{
    }

    includedirs {
    "include",
    "include/**",    }
    if(_ACTION == "gmake") then
      buildoptions {"-std=c++11"}

      pchheader ( "include/CommonPrecompiled.h" )
    else
      pchheader ( "CommonPrecompiled.h" )
    end
    pchsource ( "src/CommonPrecompiled.cpp" )
    flags { 
    "Unicode"}

    configuration { "Debug*" }
      defines { "_DEBUG", "DEBUG" }
      flags   { "Symbols" }
      libdirs { "lib/debug", 
      }

    configuration { "Release*" }
      defines { "NDEBUG" }
      libdirs { "lib/release",       }

------------------------
------physics LIB
------------------------
  project "physics"
    location "settings"
    language "C++"
    kind     "StaticLib"

    files  { 
"src/CommonPrecompiled.cpp",
 "src/physics/**.cpp", "include/**.h", "include/**.hpp" }


    defines{
    }

    includedirs {
    "include",
    "include/**",    }
    if(_ACTION == "gmake") then
      buildoptions {"-std=c++11"}

      pchheader ( "include/CommonPrecompiled.h" )
    else
      pchheader ( "CommonPrecompiled.h" )
    end
    pchsource ( "src/CommonPrecompiled.cpp" )
    flags { 
    "Unicode"}

    configuration { "Debug*" }
      defines { "_DEBUG", "DEBUG" }
      flags   { "Symbols" }
      libdirs { "lib/debug", 
      }

    configuration { "Release*" }
      defines { "NDEBUG" }
      libdirs { "lib/release",       }

------------------------
------networking LIB
------------------------
  project "networking"
    location "settings"
    language "C++"
    kind     "StaticLib"

    files  { 
"src/CommonPrecompiled.cpp",
 "src/networking/**.cpp", "include/**.h", "include/**.hpp" }


    defines{
    }

    includedirs {
    "include",
    "include/**",    }
    if(_ACTION == "gmake") then
      buildoptions {"-std=c++11"}

      pchheader ( "include/CommonPrecompiled.h" )
    else
      pchheader ( "CommonPrecompiled.h" )
    end
    pchsource ( "src/CommonPrecompiled.cpp" )
    flags { 
    "Unicode"}

    configuration { "Debug*" }
      defines { "_DEBUG", "DEBUG" }
      flags   { "Symbols" }
      libdirs { "lib/debug", 
      }

    configuration { "Release*" }
      defines { "NDEBUG" }
      libdirs { "lib/release",       }
