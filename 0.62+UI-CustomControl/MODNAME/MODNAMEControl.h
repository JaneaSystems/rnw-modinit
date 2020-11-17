#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "winrt/Microsoft.ReactNative.h"
#include "NativeModules.h"
#include "MODNAMEControl.g.h"

namespace winrt::MODNAME::implementation
{
    struct MODNAMEControl : MODNAMEControlT<MODNAMEControl>
    {
    public:
        MODNAMEControl(Microsoft::ReactNative::IReactContext const& reactContext);

        static winrt::Windows::Foundation::Collections::
          IMapView<winrt::hstring, winrt::Microsoft::ReactNative::ViewManagerPropertyType>
          NativeProps() noexcept;
        void UpdateProperties(winrt::Microsoft::ReactNative::IJSValueReader const& propertyMapReader) noexcept;

        static winrt::Microsoft::ReactNative::ConstantProviderDelegate
          ExportedCustomBubblingEventTypeConstants() noexcept;
        static winrt::Microsoft::ReactNative::ConstantProviderDelegate
          ExportedCustomDirectEventTypeConstants() noexcept;

        static winrt::Windows::Foundation::Collections::IVectorView<winrt::hstring> Commands() noexcept;
        void DispatchCommand(
          winrt::hstring const& commandId,
          winrt::Microsoft::ReactNative::IJSValueReader const& commandArgsReader) noexcept;
    private:
        Microsoft::ReactNative::IReactContext m_reactContext{ nullptr };
        void OnTextChanged(winrt::Windows::Foundation::IInspectable const& sender,
          winrt::Windows::UI::Xaml::Controls::TextChangedEventArgs const& args);
        winrt::Windows::UI::Xaml::Controls::TextBox::TextChanged_revoker m_textChangedRevoker{};
    };
}

namespace winrt::MODNAME::factory_implementation
{
    struct MODNAMEControl : MODNAMEControlT<MODNAMEControl, implementation::MODNAMEControl>
    {
    };
}
