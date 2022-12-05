#include "a.h"
#include <iostream>

static const PluginDesc pluginA(
        "pluginA",
        "This is plugin A",
        []() {
            return std::make_unique<PluginA>();
        }
);

void PluginA::doSomething() {
    std::cout << "PluginA::doSomething()" << std::endl;
}