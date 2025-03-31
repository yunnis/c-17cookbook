#pragma once
#include "base.h"
#include <filesystem>

void _10_1(char argv[])
{
    const std::filesystem::path dir{ argv };
    if (!exists(dir))
    {
        std::cout << "Path " << dir << " does not exist.\n";
        return;
    }
    std::cout << std::filesystem::canonical(dir).string() << "\n";
}
