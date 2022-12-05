#include <iostream>
#include "plugin/registry.h"
#include "plugin/instances/a.h"

int main() {
    // uncomment next line will produce different result
    // PluginA a;
    auto plugin = createPlugin("pluginA");

    if (plugin) {
        plugin->doSomething();
    } else {
        std::cout << "Plugin not found" << std::endl;
    }

    return 0;
}