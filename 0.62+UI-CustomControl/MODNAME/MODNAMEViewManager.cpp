#include "pch.h"
#include "NativeModules.h"
#include "JSValueXaml.h"
#include "MODNAMEViewManager.h"
#include "MODNAMEControl.h"

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
        return winrt::MODNAME::MODNAMEControl(m_reactContext);
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
        return winrt::MODNAME::implementation::MODNAMEControl::NativeProps();
    }

    void MODNAMEViewManager::UpdateProperties(
        FrameworkElement const& view,
        IJSValueReader const& propertyMapReader) noexcept {
         if (auto module = view.try_as<winrt::MODNAME::MODNAMEControl>()) {
            module.UpdateProperties(propertyMapReader);
        }
    }
    // IViewManagerWithExportedEventTypeConstants
    ConstantProviderDelegate MODNAMEViewManager::ExportedCustomBubblingEventTypeConstants() noexcept {
        return winrt::MODNAME::implementation::MODNAMEControl::ExportedCustomBubblingEventTypeConstants();
    }

    ConstantProviderDelegate MODNAMEViewManager::ExportedCustomDirectEventTypeConstants() noexcept {
       return winrt::MODNAME::implementation::MODNAMEControl::ExportedCustomDirectEventTypeConstants();
    }

    // IViewManagerWithCommands
    IVectorView<hstring> MODNAMEViewManager::Commands() noexcept {
        return winrt::MODNAME::implementation::MODNAMEControl::Commands();
    }

    void MODNAMEViewManager::DispatchCommand(
        FrameworkElement const& view,
        winrt::hstring const& commandId,
        winrt::IJSValueReader const& commandArgsReader) noexcept {
        if (auto module = view.try_as<winrt::MODNAME::MODNAMEControl>()) {
            module.DispatchCommand(commandId, commandArgsReader);
        }
    }
}
