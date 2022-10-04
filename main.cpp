#include "resource.h"

#include "common.h"

#include "imgui.h"
#include "imgui_stdlib.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>

#include "tb/Constants.h"
#include "tb/BitmapFont.h"
#include "tb/BitmapFontText.h"

sf::Cursor g_cursorArrow;

tb::BitmapFont g_bitmapFontDefault;
tb::BitmapFont g_bitmapFontTiny;
tb::BitmapFont g_bitmapFontModern;

std::string g_textString = "Hello, world!";
sf::Color g_textColor = sf::Color::Yellow;
ImVec4 g_textColorArray = {1.0f, 1.0f, 0.0f, 1.0f}; // default to yellow

bool loadBitmapFonts()
{
    if (g_bitmapFontDefault.load(tb::BitmapFonts::Default::FileName, tb::BitmapFonts::Default::GlyphSize, &tb::BitmapFonts::Default::GlyphWidthList) == false)
    {
        return false;
    }

    if (g_bitmapFontTiny.load(tb::BitmapFonts::Tiny::FileName, tb::BitmapFonts::Tiny::GlyphSize, &tb::BitmapFonts::Tiny::GlyphWidthList) == false)
    {
        return false;
    }

    if (g_bitmapFontModern.load(tb::BitmapFonts::Modern::FileName, tb::BitmapFonts::Modern::GlyphSize, &tb::BitmapFonts::Modern::GlyphWidthList) == false)
    {
        return false;
    }

    return true;
}

void fixMouseCursorForWindowResize(sf::RenderWindow* renderWindow)
{
    // this function fixes a bug between imgui, SFML and imgui-SFML
    // where the mouse cursor doesn't work correctly when resizing the window

    static ImGuiIO& imguiIO = ImGui::GetIO();

    static bool imguiHasCursorPrev = true;

    if (bool imguiHasCursor = imguiIO.WantCaptureMouse || imguiIO.WantCaptureKeyboard; imguiHasCursor != imguiHasCursorPrev)
    {
        if (imguiHasCursor)
        {
            imguiIO.ConfigFlags &= ~ImGuiConfigFlags_NoMouseCursorChange;
        }
        else
        {
            imguiIO.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

            renderWindow->setMouseCursor(g_cursorArrow);
        }
        imguiHasCursorPrev = imguiHasCursor;
    }
}

int main()
{
    sf::RenderWindow renderWindow;
    renderWindow.create(sf::VideoMode(1024, 768), "Tibia Font Render", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

    sf::Image renderWindowIcon;
    if (renderWindowIcon.loadFromFile("images/icon.png") == true)
    {
        renderWindow.setIcon(renderWindowIcon.getSize().x, renderWindowIcon.getSize().y, renderWindowIcon.getPixelsPtr());
    }

    renderWindow.setFramerateLimit(60);
    renderWindow.setVerticalSyncEnabled(true);

    ImGui::SFML::Init(renderWindow);

    g_cursorArrow.loadFromSystem(sf::Cursor::Arrow);

    loadBitmapFonts();

    sf::Clock deltaClock;

    while (renderWindow.isOpen())
    {
        sf::Event event;

        while (renderWindow.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(renderWindow, event);

            if (event.type == sf::Event::Closed)
            {
                renderWindow.close();
            }
            else if (event.type == sf::Event::Resized)
            {
                // stretch to fill window
                sf::FloatRect visibleArea(0.0f, 0.0f, event.size.width, event.size.height);
                renderWindow.setView(sf::View(visibleArea));
            }
        }

        fixMouseCursorForWindowResize(&renderWindow);

        ImGui::SFML::Update(renderWindow, deltaClock.restart());

        ImGui::Begin("Text Editor");
        ImGui::InputText("Text", &g_textString);
        ImGui::ColorEdit3("Color", (float*)&g_textColorArray);
        ImGui::End();

        renderWindow.clear(sf::Color::Magenta);

        unsigned int textColor = ImGui::ColorConvertFloat4ToU32(g_textColorArray);

        g_textColor.r = textColor & 0xFF;
        g_textColor.g = (textColor >> 8) & 0xFF;
        g_textColor.b = (textColor >> 16) & 0xFF;

        tb::BitmapFontText defaultText;
        defaultText.setText(&g_bitmapFontDefault, g_textString, g_textColor, false);
        defaultText.setPosition(10.0f, 10.0f);

        tb::BitmapFontText tinyText;
        tinyText.setText(&g_bitmapFontTiny, g_textString, g_textColor, false);
        tinyText.setPosition(10.0f, 60.0f);

        tb::BitmapFontText modernText;
        modernText.setText(&g_bitmapFontModern, g_textString, g_textColor, false);
        modernText.setPosition(10.0f, 110.0f);

        renderWindow.draw(defaultText);
        renderWindow.draw(tinyText);
        renderWindow.draw(modernText);

        ImGui::SFML::Render(renderWindow);

        renderWindow.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
