#pragma once
// declare a plugin class
#include "../registry.h"

class PluginA: public Plugin {
public:
    virtual void doSomething() override;
};