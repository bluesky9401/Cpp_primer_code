#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <string>
#include <iostream>
#include <vector>
// 声明Screen以便后面的WindowMgr用到Screen类
class Screen;
// WindowMgr is use to manage the screen
class WindowMgr{
public:
       using ScreenIndex = std::vector<Screen>::size_type;
       void clear(ScreenIndex index);
       ScreenIndex addScreen(const Screen&);
private:
       std::vector<Screen> m_screens;
};
WindowMgr::ScreenIndex WindowMgr::addScreen(const Screen& s)
{
        m_screens.push_back(s);
        return m_screens.size() - 1;
}

class Screen{
    friend void WindowMgr::clear(WindowMgr::ScreenIndex index);
public:

    // constructor function
    Screen() = default;
    Screen(pos height, pos width):m_height(height), m_width(width),
           m_contents(height * width, ' ') { }
    Screen(pos height, pos width, char c):m_height(height), m_width(width),
           m_contents(height * width, c) { }

    // return the cursor position's char
    char get() { return m_contents[m_cursor]; }
    // return give postion's char
    inline char get(pos row, pos column) const;
    // move the cursor to the corresponding position
    Screen& move(pos row, pos column);
    // set char at the cursor position
    Screen& set(char c);
    // set char at the giving position
    Screen& set(pos row, pos column, char c);
    // the display function (no const version)
    Screen& display(std::ostream &os)
                   { do_display(os); return *this; }
    // the display function (const version)
    const Screen& display(std::ostream &os) const
                   { do_display(os); return *this; }

private:
    // Screen's cursor position,it's heigth and width
    pos m_cursor = 0;
    pos m_height = 0, m_width = 0;
    std::string m_contents;
    // a function for display the contents of screen
    void do_display(std::ostream &os) const { os << m_contents; }
    typedef std::string::size_type pos;

};
// 定义WindowMgr中的函数clear()
void WindowMgr::clear(ScreenIndex index)
{
    Screen &s = m_screens[index];
    s.m_contents = std::string(s.m_height * s.m_width, ' ');
}

// 定义Screen类中的函数
char Screen::get(pos row, pos column) const
{
    pos row_position = row * m_width;
    return m_contents[row_position + column];
}

inline Screen& Screen::move(pos row, pos column)
{
    pos row_position = row * m_width;
    m_cursor = row_position + column;
    return *this;
}

inline Screen& Screen::set(char c) { m_contents[m_cursor] = c; return *this;}

inline Screen& Screen::set(pos row, pos column, char c)
{
    m_contents[row * m_width + column] = c;
    return *this;
}

#endif
