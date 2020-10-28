#include "pch.h"
#include "NativeModules.h"
#include "JSValueXaml.h"
#include "MODNAMEViewManager.h"
#include "MODNAME.h"

namespace winrt {
    using namespace Microsoft::ReactNative;
    using namespace Windows::Foundation;
    using namespace Windows::Foundation::Collections;
    using namespace Windows::UI;
    using namespace Windows::UI::Xaml;
    using namespace Windows::UI::Xaml::Controls;
}

namespace winrt::MODNAME::implementation {
    // IViewManager
    winrt::hstring MODNAMEViewManager::Name() noexcept {
        return L"MODNAME";
    }

    winrt::FrameworkElement MODNAMEViewManager::CreateView() noexcept {
        return winrt::MODNAME::MODNAMEModule(m_reactContext);
    }

    // IViewManagerWithReactContext
    winrt::IReactContext MODNAMEViewManager::ReactContext() noexcept {
        return m_reactContext;
    }

    void MODNAMEViewManager::ReactContext(IReactContext reactContext) noexcept {
        m_reactContext = reactContext;
    }

    // IViewManagerWithNativeProperties
    IMapView<hstring, ViewManagerPropertyType> MODNAMEViewManager::NativeProps() noexcept {
        return winrt::MODNAME::implementation::MODNAMEModule::NativeProps();
    }

    void MODNAMEViewManager::UpdateProperties(
        FrameworkElement const& view,
        IJSValueReader const& propertyMapReader) noexcept {
         if (auto module = view.try_as<winrt::MODNAME::MODNAMEModule>()) {
            module.UpdateProperties(propertyMapReader);
        }
    }
    // IViewManagerWithExportedEventTypeConstants
    ConstantProviderDelegate MODNAMEViewManager::ExportedCustomBubblingEventTypeConstants() noexcept {
        return winrt::MODNAME::implementation::MODNAMEModule::ExportedCustomBubblingEventTypeConstants();
    }

    ConstantProviderDelegate MODNAMEViewManager::ExportedCustomDirectEventTypeConstants() noexcept {
       return winrt::MODNAME::implementation::MODNAMEModule::ExportedCustomDirectEventTypeConstants();
    }

    // IViewManagerWithCommands
    IVectorView<hstring> MODNAMEViewManager::Commands() noexcept {
        return winrt::MODNAME::implementation::MODNAMEModule::Commands();
    }

    void MODNAMEViewManager::DispatchCommand(
        FrameworkElement const& view,
        winrt::hstring const& commandId,
        winrt::IJSValueReader const& commandArgsReader) noexcept {
        if (auto module = view.try_as<winrt::MODNAME::MODNAMEModule>()) {
            module.DispatchCommand(commandId, commandArgsReader);
        }
    }
}
