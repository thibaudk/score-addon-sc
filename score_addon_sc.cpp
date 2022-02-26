#include "score_addon_sc.hpp"

#include <score/plugins/FactorySetup.hpp>

#include <sc/ProtocolFactory.hpp>

score_addon_sc::score_addon_sc() { }

score_addon_sc::~score_addon_sc() { }

std::vector<std::unique_ptr<score::InterfaceBase>>
score_addon_sc::factories(
    const score::ApplicationContext& ctx,
    const score::InterfaceKey& key) const
{
  return instantiate_factories<
      score::ApplicationContext,
      FW<Device::ProtocolFactory, SC::ProtocolFactory>>(ctx, key);
}

#include <score/plugins/PluginInstances.hpp>
SCORE_EXPORT_PLUGIN(score_addon_sc)
