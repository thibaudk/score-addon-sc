#include "score_sc_device.hpp"

#include <score/plugins/FactorySetup.hpp>

#include <Device/ProtocolFactory.hpp>

score_sc_device::score_sc_device() { }

score_sc_device::~score_sc_device() { }

std::vector<std::unique_ptr<score::InterfaceBase>>
score_sc_device::factories(
    const score::ApplicationContext& ctx,
    const score::InterfaceKey& key) const
{
  return instantiate_factories<
      score::ApplicationContext,
      FW<Device::ProtocolFactory, SC::ProtocolFactory>>(ctx, key);
}

#include <score/plugins/PluginInstances.hpp>
SCORE_EXPORT_PLUGIN(score_sc_device)
