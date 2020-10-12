#pragma once

#include "pch.h"
#include "NativeModules.h"

using namespace winrt::Microsoft::ReactNative;

#ifdef RNW61
#define JSVALUEOBJECTPARAMETER
#else
#define JSVALUEOBJECTPARAMETER const &
#endif

namespace winrt::MODNAME {
  REACT_MODULE(MODNAME);
  struct MODNAME {
    const std::string Name = "MODNAME";
  };
}
