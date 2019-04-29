#pragma once

#include "player.h"
#include "imgui.h"
#include "Tracker.h"
#include <string>
#include <fstream>
#include <windows.h>
#include <shlobj.h>
#include <ctime>

struct AppLog
{
    ImGuiTextFilter filter_player;
    ImGuiTextFilter filter_mechanic;
	bool show_pull_separators = true;
    bool scroll_to_bottom = false;
	uint64_t line_break_frequency = 5000;

    void draw(const char* title, bool* p_open, ImGuiWindowFlags flags, Tracker* tracker);
};

struct AppChart
{
    ImGuiTextFilter filter;
    uint16_t last_export_total = 0;
	std::string export_dir = "";
	std::string last_file_path = "";

    void clear(Tracker* tracker);

    void draw(Tracker* tracker, const char* title, bool* p_open, ImGuiWindowFlags flags, bool show_all);

    std::string toString(Tracker* tracker);
	void exportData(Tracker* tracker);
	void writeToDisk(Tracker* tracker);
	std::string getDefaultExportPath();
};

struct AppOptions
{
	void    draw(Tracker* tracker, const char* title, bool* p_open, ImGuiWindowFlags flags);
};

constexpr float getChartColumnWidth(float window_width);
float getChartColumnLoc(float window_width, uint16_t col);
static void showHelpMarker(const char* desc);