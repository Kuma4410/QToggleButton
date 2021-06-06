#ifndef SAMPLEWINDOW_H
#define SAMPLEWINDOW_H

#include <qmainwindow.h>

namespace Ui
{
    class SampleWindowClass;
}

class SampleWindow : public QMainWindow
{
public:
    SampleWindow(QWidget *parent = nullptr);
    ~SampleWindow();

private:
    Ui::SampleWindowClass *_ui;
};

#endif // SAMPLEWINDOW_H
