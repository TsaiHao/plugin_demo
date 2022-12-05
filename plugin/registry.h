#pragma once

#include <string>
#include <memory>
#include <functional>
#include <unordered_map>

class Plugin {
public:
    virtual ~Plugin() {}
    virtual void doSomething() = 0;
};

struct PluginDesc {
    std::string_view name;
    std::string_view desc;
    
    PluginDesc(std::string_view name, 
               std::string_view desc,
               std::function<std::unique_ptr<Plugin>()> factory);
};

std::unique_ptr<Plugin> createPlugin(const std::string& name);