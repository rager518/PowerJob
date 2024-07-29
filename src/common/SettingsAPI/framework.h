#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
#define NOMINMAX

#include <winrt/base.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <Windows.h>

#include <filesystem>
#include <fstream>

#include <common/logger/logger.h>
#include <wil/filesystem.h>
