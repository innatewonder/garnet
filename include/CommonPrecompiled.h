#pragma warning( disable : 4267 )

//#define GLEW_STATIC
//Common Include and Macros
#include "Config.h"
#include "SuperCommon.h"

//very helpful
#include <regex>
#include <stdlib.h>

//OpenGL Includes
#if PLATFORM == PLAT_ANDROID
  #include <GLES2/gl2.h>
#endif

//Math
#include "MathIncludes.h"

#define SLEEP_MILLI(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

#include "Memory.h"

//ThreadLibrary
#include "HBThread.h"
#include "UpdateType.h" 

typedef u32 UID;
#include "CoreUtils.h"
#include "ArgParser.h"

// engine
#include "Factory.h"
#include "Message.h"
#include "Event.h"

#include "Timer.h"
#include "Component.h"
#include "Object.h"
#include "System.h"

#include "Core.h"
#include "SystemIncludes.h"
