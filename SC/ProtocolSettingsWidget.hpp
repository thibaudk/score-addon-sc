#pragma once
#include <Device/Protocol/DeviceSettings.hpp>
#include <Device/Protocol/ProtocolSettingsWidget.hpp>

#include <SC/SpecificSettings.hpp>

#include <variant>
#include <verdigris>

class QLineEdit;
class QSpinBox;
class QTableWidget;
class QPushButton;

namespace SC
{
class ProtocolSettingsWidget final : public Device::ProtocolSettingsWidget
{
  W_OBJECT(ProtocolSettingsWidget)

public:
  ProtocolSettingsWidget(QWidget* parent = nullptr);
  virtual ~ProtocolSettingsWidget();
  Device::DeviceSettings getSettings() const override;
  void setSettings(const Device::DeviceSettings& settings) override;

private:
  QLineEdit* m_deviceNameEdit{};
  QSpinBox* m_control{};
};
}
