#include "score_sc_process.hpp"

#include <score/plugins/FactorySetup.hpp>

#include <Process/Distortion.hpp>
#include <score_plugin_engine.hpp>

/**
 * This file instantiates the classes that are provided by this plug-in.
 */

score_sc_process::score_sc_process() = default;
score_sc_process::~score_sc_process() = default;

std::vector<std::unique_ptr<score::InterfaceBase>>
score_sc_process::factories(
    const score::ApplicationContext& ctx,
    const score::InterfaceKey& key) const
{
  return Control::instantiate_fx<SC::Distortion>(ctx, key);
}

std::vector<score::PluginKey> score_sc_process::required() const
{
  return {score_plugin_engine::static_key()};
}

#include <score/plugins/PluginInstances.hpp>
SCORE_EXPORT_PLUGIN(score_sc_process)
