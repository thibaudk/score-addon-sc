#include "Device.hpp"
#include "SCProtocol.hpp"
#include "SpecificSettings.hpp"

#include <Explorer/DocumentPlugin/DeviceDocumentPlugin.hpp>

#include <score/document/DocumentContext.hpp>

#include <ossia/network/generic/generic_device.hpp>
#include <ossia/network/local/local.hpp>

#include <QDebug>

#include <wobjectimpl.h>

W_OBJECT_IMPL(SC::DeviceImplementation)

namespace SC
{
DeviceImplementation::DeviceImplementation(
    const Device::DeviceSettings& settings,
    const Explorer::DeviceDocumentPlugin& plugin,
    const score::DocumentContext&)
    : OwningDeviceInterface{settings}
    , m_ctx{plugin}
{
  m_capas.canRefreshTree = true;
  m_capas.canAddNode = false;
  m_capas.canRemoveNode = false;
  m_capas.canRenameNode = false;
  m_capas.canSetProperties = false;
  m_capas.canSerialize = false;
}

DeviceImplementation::~DeviceImplementation() { }

bool DeviceImplementation::reconnect()
{
  disconnect();

  try
  {
    const auto& set
        = m_settings.deviceSpecificSettings.value<SpecificSettings>();
    qDebug() << "sc created with: " << set.control;

    // Needed by most protocols:
    auto& ctx = m_ctx.networkContext();

//    auto protocol = std::make_unique<SCProtocol>();
//    auto dev = std::make_unique<ossia::net::generic_device>(
//        std::move(protocol), settings().name.toStdString());

//    m_dev = std::move(dev);
//    deviceChanged(nullptr, m_dev.get());
  }
  catch (const std::runtime_error& e)
  {
    qDebug() << "sc error: " << e.what();
  }
  catch (...)
  {
    qDebug() << "sc error";
  }

  return connected();
}

void DeviceImplementation::disconnect()
{
  OwningDeviceInterface::disconnect();
}
}
