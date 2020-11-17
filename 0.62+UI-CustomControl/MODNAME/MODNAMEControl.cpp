#include "pch.h"
#include "MODNAMEControl.h"
#if __has_include("MODNAMEControl.g.cpp")
#include "MODNAMEControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;
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

namespace winrt::MODNAME::implementation
{
    MODNAMEControl::MODNAMEControl(winrt::IReactContext const& reactContext) : m_reactContext(reactContext) {
        this->AllowFocusOnInteraction(true);
        InitializeComponent();
        m_textChangedRevoker = TextElement().TextChanged(winrt::auto_revoke,
          [ref = get_weak()](auto const& sender, auto const& args) {
          if (auto self = ref.get()) {
            self->OnTextChanged(sender, args);
          }
        });
    }

    void MODNAMEControl::OnTextChanged(winrt::Windows::Foundation::IInspectable const&,
      winrt::Windows::UI::Xaml::Controls::TextChangedEventArgs const&) {
      // TODO: example sending event on text changed
      auto text = TextElement().Text();
      m_reactContext.DispatchEvent(
        *this,
        L"sampleEvent",
        [&](winrt::Microsoft::ReactNative::IJSValueWriter const& eventDataWriter) noexcept {
          eventDataWriter.WriteObjectBegin();
          WriteProperty(eventDataWriter, L"text", text);
          eventDataWriter.WriteObjectEnd();
        }
      );
    }

    winrt::Windows::Foundation::Collections::
      IMapView<winrt::hstring, winrt::Microsoft::ReactNative::ViewManagerPropertyType>
      MODNAMEControl::NativeProps() noexcept {
      // TODO: define props here
      auto nativeProps = winrt::single_threaded_map<hstring, ViewManagerPropertyType>();
      nativeProps.Insert(L"sampleProp", ViewManagerPropertyType::String);
      return nativeProps.GetView();
    }

    void MODNAMEControl::UpdateProperties(winrt::Microsoft::ReactNative::IJSValueReader const& propertyMapReader) noexcept {
      // TODO: handle the props here
      const JSValueObject& propertyMap = JSValue::ReadObjectFrom(propertyMapReader);
      for (auto const& pair : propertyMap) {
        auto const& propertyName = pair.first;
        auto const& propertyValue = pair.second;
        if (propertyName == "sampleProp") {
          if (propertyValue != nullptr) {
            auto const& value = propertyValue.AsString();
            TextElement().Text(winrt::to_hstring(value));
          }
          else {
            TextElement().Text(L"");
          }
        }
      }
    }

    winrt::Microsoft::ReactNative::ConstantProviderDelegate MODNAMEControl::ExportedCustomBubblingEventTypeConstants() noexcept {
      return nullptr;
    }

    winrt::Microsoft::ReactNative::ConstantProviderDelegate MODNAMEControl::ExportedCustomDirectEventTypeConstants() noexcept {
      return [](winrt::IJSValueWriter const& constantWriter) {
        // TODO: define events emitted by the control
        WriteCustomDirectEventTypeConstant(constantWriter, "sampleEvent");
      };
    }

    winrt::Windows::Foundation::Collections::IVectorView<winrt::hstring> MODNAMEControl::Commands() noexcept {
      // TODO: deifne commands supported by the control
      auto commands = winrt::single_threaded_vector<hstring>();
      commands.Append(L"sampleCommand");
      return commands.GetView();
    }

    void MODNAMEControl::DispatchCommand(winrt::hstring const& commandId, winrt::Microsoft::ReactNative::IJSValueReader const& commandArgsReader) noexcept {
      // TODO: handle commands here
      auto commandArgs = JSValue::ReadArrayFrom(commandArgsReader);
      if (commandId == L"sampleCommand") {
        TextElement().Text(L"sampleCommand used!");
      }
    }

}
