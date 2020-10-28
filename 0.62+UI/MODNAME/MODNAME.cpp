#include "pch.h"
#include "JSValueXaml.h"
#include "MODNAME.h"
#include "MODNAME.g.cpp"

namespace winrt {
    using namespace Microsoft::ReactNative;
    using namespace Windows::Data::Json;
    using namespace Windows::Foundation;
    using namespace Windows::UI;
    using namespace Windows::UI::Popups;
    using namespace Windows::UI::Xaml;
    using namespace Windows::UI::Xaml::Controls;
    using namespace Windows::UI::Xaml::Input;
    using namespace Windows::UI::Xaml::Media;
} // namespace winrt

namespace winrt::MODNAME::implementation {

    MODNAME::MODNAME(winrt::IReactContext const& reactContext) : m_reactContext(reactContext) {
        this->AllowFocusOnInteraction(true);
        // TODO: hook up events from the controll
        m_textChangedRevoker = this->TextChanged(winrt::auto_revoke,
            [ref = get_weak()](auto const& sender, auto const& args) {
            if (auto self = ref.get()) {
                self->OnTextChanged(sender, args);
            }
        });
    }

    void MODNAME::OnTextChanged(winrt::Windows::Foundation::IInspectable const& sender,
                                winrt::Windows::UI::Xaml::Controls::TextChangedEventArgs const& args) {
        // TODO: example sending event on text changed
        auto text = this->Text();
        m_reactContext.DispatchEvent(
            *this,
            L"sampleEvent",
            [&](winrt::Microsoft::ReactNative::IJSValueWriter const& eventDataWriter) noexcept {
                eventDataWriter.WriteObjectBegin();
                WriteProperty(eventDataWriter, L"text", text);
                eventDataWriter.WriteObjectEnd();
            });
        );
    }

    winrt::Windows::Foundation::Collections::
            IMapView<winrt::hstring, winrt::Microsoft::ReactNative::ViewManagerPropertyType>
            MODNAME::NativeProps() noexcept {
        // TODO: define props here
        auto nativeProps = winrt::single_threaded_map<hstring, ViewManagerPropertyType>();
        nativeProps.Insert(L"sampleProp", ViewManagerPropertyType::String);
        return nativeProps.GetView();
    }

    void MODNAME::UpdateProperties(winrt::Microsoft::ReactNative::IJSValueReader const& propertyMapReader) noexcept {
        // TODO: handle the props here
        const JSValueObject &propertyMap = JSValue::ReadObjectFrom(propertyMapReader);
        for (auto const &pair : propertyMap) {
            auto const &propertyName = pair.first;
            auto const &propertyValue = pair.second;
            if (propertyName == "sampleProp") {
                if (propertyValue != nullptr) {
                    auto const &value = propertyValue.AsString();
                    ths->Text(value);
                } else {
                    ths->Text(L"");
                }
            }
        }
    }

    winrt::Microsoft::ReactNative::ConstantProviderDelegate MODNAME::ExportedCustomBubblingEventTypeConstants() noexcept {
        return nullptr;
    }
    
    winrt::Microsoft::ReactNative::ConstantProviderDelegate MODNAME::ExportedCustomDirectEventTypeConstants() noexcept {
        return [](winrt::IJSValueWriter const& constantWriter) {
            // TODO: define events emitted by the control
            WriteCustomDirectEventTypeConstant(constantWriter, "sampleEvent");
        };
    }

    winrt::Windows::Foundation::Collections::IVectorView<winrt::hstring> Commands() noexcept {
        // TODO: deifne commands supported by the control
        auto commands = winrt::single_threaded_vector<hstring>();
        commands.Append(L"sampleCommand");
        return commands.GetView();
    }

    void MODNAME::DispatchCommand(winrt::hstring const &commandId, winrt::Microsoft::ReactNative::IJSValueReader const &commandArgsReader) noexcept {
        // TODO: handle commands here
        auto commandArgs = JSValue::ReadArrayFrom(commandArgsReader);
        if (commandId == L"sampleCommand") {
            this->Text(L"sampleCommand used!);
        }
    }
}