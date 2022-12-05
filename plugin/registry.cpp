#include "registry.h"

class PluginTable {
public:
    static PluginTable& instance() {
        static PluginTable instance;
        return instance;
    }

    void registerPlugin(const std::string& name, std::function<std::unique_ptr<Plugin>()> creator) {
        plugins[name] = creator;
    }

    std::unique_ptr<Plugin> createPlugin(const std::string& name) {
        auto it = plugins.find(name);
        if (it != plugins.end()) {
            return it->second();
        }
        return nullptr;
    }

private:
    std::unordered_map<std::string, std::function<std::unique_ptr<Plugin>()>> plugins;
};

PluginDesc::PluginDesc(std::string_view name,
               std::string_view desc,
               std::function<std::unique_ptr<Plugin>()> factory) {
    PluginTable::instance().registerPlugin(name.data(), factory);
}

std::unique_ptr<Plugin> createPlugin(const std::string& name) {
    return PluginTable::instance().createPlugin(name);
}