#include "pch.h"
#include "ReactPackageProvider.h"
#if __has_include("ReactPackageProvider.g.cpp")
#  include "ReactPackageProvider.g.cpp"
#endif

#include "MODNAMEViewManager.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::MODNAME::implementation {
  void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept {
    packageBuilder.AddViewManager(L"MODNAMEViewManager", []() { return winrt::make<MODNAMEViewManager>(); });
  }
}
