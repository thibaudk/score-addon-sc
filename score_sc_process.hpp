#pragma once
#include <score/application/ApplicationContext.hpp>
#include <score/plugins/Interface.hpp>
#include <score/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <score/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>

#include <verdigris>

class score_sc_process final
    : public score::FactoryInterface_QtInterface
    , public score::Plugin_QtInterface
{
  SCORE_PLUGIN_METADATA(1, "74623bd2-231d-4f3c-8d6f-af2ed3a1a2bc")
public:
  score_sc_process();
  ~score_sc_process() override;

private:
  std::vector<std::unique_ptr<score::InterfaceBase>> factories(
      const score::ApplicationContext&,
      const score::InterfaceKey& factoryName) const override;

  std::vector<score::PluginKey> required() const override;
};
